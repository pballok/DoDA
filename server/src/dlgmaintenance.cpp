#include <QSqlDatabase>

#include <tracer.h>

#include "dlgmaintenance.h"
#include "dlgstatus.h"

DlgMaintenance::DlgMaintenance(DoDAPreferences &prefs, QWidget *parent) : QDialog(parent),
                                                                          prefs_{prefs} {
    ui_.setupUi(this);
}

void DlgMaintenance::on_psbCheck_clicked() {
    TRACE_ME();

    ui_.lblDBStatus->setText("PENDING...");
    ui_.lblDBStatus->setStyleSheet("color: black");

    if(checkDBStatus()) {
        ui_.lblDBStatus->setText("OK");
        ui_.lblDBStatus->setStyleSheet("color: green");
    }
    else {
        ui_.lblDBStatus->setText("NOK");
        ui_.lblDBStatus->setStyleSheet("color: red");
    }
}

bool DlgMaintenance::checkDBStatus() noexcept {
    DlgStatus status_dlg(this);
    status_dlg.show();

    QSqlDatabase default_db = QSqlDatabase::database();
    if(default_db.isOpen()) {
//        db_status_.emplace("Database Connection", true);
    } else {
//        db_status_.emplace("Database Connection", false);
    }
}
