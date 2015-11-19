#include <QSqlDatabase>
#include <QMessageBox>

#include <tracer.h>
#include <loggedquery.h>

#include "dlgmaintenance.h"
#include "dlgstatus.h"

DlgMaintenance::DlgMaintenance(DoDAPreferences &prefs, QWidget *parent) : QDialog(parent),
                                                                          prefs_{prefs} {
    ui_.setupUi(this);

    setStatusDisplay(DBStatus::UNDETERMINED);
}



void DlgMaintenance::on_psbCheck_clicked() {
    TRACE_ME();

    setStatusDisplay(DBStatus::PENDING);

    if(checkDBStatus()) {
        setStatusDisplay(DBStatus::OK);
    }
    else {
        setStatusDisplay(DBStatus::NOK);
    }
}



void DlgMaintenance::on_psbWipe_clicked() {
    TRACE_ME();

    auto default_db = QSqlDatabase::database();

    if(!default_db.isOpen()) {
        QMessageBox::critical(this, "Database Wipe", "Cannot connect to Database!");
        return;
    }

    if(QMessageBox::question(this, "Database Wipe", "Are you sure you want to wipe all the data? This will DELETE all the tables as well!") == QMessageBox::No)
        return;

    DlgStatus status_dlg(this);
    status_dlg.setWindowTitle("Deleting Tables");

    status_dlg.show();

    LoggedQuery query(default_db);

    for(const auto t : db_tables_) {
        status_dlg.addStatusEntry("Deleting table `" + t.first + "`", query.exec("DROP TABLE IF EXISTS `" + t.first + "`"));
    }

    status_dlg.exec();

    setStatusDisplay(DBStatus::UNDETERMINED);
}



void DlgMaintenance::on_psbCreateMissing_clicked() {
    TRACE_ME();

    auto default_db = QSqlDatabase::database();

    if(!default_db.isOpen()) {
        QMessageBox::critical(this, "Database Recreate", "Cannot connect to DataBase!");
        return;
    }

    DlgStatus status_dlg(this);
    status_dlg.setWindowTitle("Recreating Missing Tables");

    status_dlg.show();

    LoggedQuery query(default_db);
    auto      tables = default_db.tables();

    for(const auto t : db_tables_) {
        if(tables.contains(t.first)) {
            status_dlg.addStatusEntry("Skipped table `" + t.first + "`", true);
        } else {
            status_dlg.addStatusEntry("Creating table `" + t.first + "`", query.exec("CREATE TABLE `" + t.first + "` (" + t.second + ") ENGINE=InnoDB DEFAULT CHARSET=utf8"));
        }
    }

    status_dlg.exec();

    setStatusDisplay(DBStatus::UNDETERMINED);
}



void DlgMaintenance::on_psbTestData_clicked() {
    TRACE_ME();

    auto default_db = QSqlDatabase::database();

    if(!default_db.isOpen()) {
        QMessageBox::critical(this, "Initialise with Test Data", "Cannot connect to DataBase!");
        return;
    }

    if(QMessageBox::question(this, "Initialise with Test Data", "Are you sure you want to reinitialise the database with test data? This will DELETE all current data!") == QMessageBox::No)
        return;

    DlgStatus status_dlg(this);
    status_dlg.setWindowTitle("Reinitialising with Test Data");

    status_dlg.show();

    LoggedQuery query(default_db);

    status_dlg.addStatusEntry("Truncating table `maps`", query.exec("TRUNCATE TABLE `maps`"));
    status_dlg.addStatusEntry("Inserting test data into table `maps`", query.exec("INSERT INTO `maps`(`name`, `size_x`, `size_y`) VALUES"
                                                                                  "('Test Map 1', 20, 20),"
                                                                                  "('Test Map 2', 10, 30),"
                                                                                  "('Test Map 3', 10, 15)"));

    status_dlg.exec();

    setStatusDisplay(DBStatus::UNDETERMINED);
}



bool DlgMaintenance::checkDBStatus() noexcept {
    TRACE_ME();

    DlgStatus status_dlg(this);
    status_dlg.setWindowTitle("Current Database Structure");

    status_dlg.show();

    auto default_db = QSqlDatabase::database();
    status_dlg.addStatusEntry("Database Connection", default_db.isOpen());

    auto tables = default_db.tables();
    for(const auto t: db_tables_)
        status_dlg.addStatusEntry("Table `" + t.first + "` exists", tables.contains(t.first));

    status_dlg.exec();

    TRACE_RESULT(status_dlg.overallStatus());

    return status_dlg.overallStatus();
}



void DlgMaintenance::setStatusDisplay(DBStatus status) noexcept {
    switch(status) {
    case DBStatus::OK:
        ui_.lblDBStatus->setText("OK");
        ui_.lblDBStatus->setStyleSheet("color: green");
        break;
    case DBStatus::NOK:
        ui_.lblDBStatus->setText("NOK");
        ui_.lblDBStatus->setStyleSheet("color: red");
        break;
    case DBStatus::UNDETERMINED:
        ui_.lblDBStatus->setText("Undetermined");
        ui_.lblDBStatus->setStyleSheet("color: black");
        break;
    case DBStatus::PENDING:
        ui_.lblDBStatus->setText("Pending...");
        ui_.lblDBStatus->setStyleSheet("color: black");
    }
}
