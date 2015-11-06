#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

#include <severity.h>
#include <tracer.h>

#include "dlgpreferences.h"

DlgPreferences::DlgPreferences(DoDAPreferences &prefs, QWidget *parent) : QDialog(parent),
                                                                          prefs_{prefs} {
    ui_.setupUi(this);

    ui_.cbxConsoleLogLevel->addItem("None",    QString::fromStdString(EnumToString<Severity>::toString(Severity::NONE)));
    ui_.cbxConsoleLogLevel->addItem("Info",    QString::fromStdString(EnumToString<Severity>::toString(Severity::INFO)));
    ui_.cbxConsoleLogLevel->addItem("Error",   QString::fromStdString(EnumToString<Severity>::toString(Severity::ERROR)));
    ui_.cbxConsoleLogLevel->addItem("Warning", QString::fromStdString(EnumToString<Severity>::toString(Severity::WARNING)));
    ui_.cbxConsoleLogLevel->addItem("Debug",   QString::fromStdString(EnumToString<Severity>::toString(Severity::DEBUG)));

    ui_.cbxFileLogLevel->addItem("None",    QString::fromStdString(EnumToString<Severity>::toString(Severity::NONE)));
    ui_.cbxFileLogLevel->addItem("Info",    QString::fromStdString(EnumToString<Severity>::toString(Severity::INFO)));
    ui_.cbxFileLogLevel->addItem("Error",   QString::fromStdString(EnumToString<Severity>::toString(Severity::ERROR)));
    ui_.cbxFileLogLevel->addItem("Warning", QString::fromStdString(EnumToString<Severity>::toString(Severity::WARNING)));
    ui_.cbxFileLogLevel->addItem("Debug",   QString::fromStdString(EnumToString<Severity>::toString(Severity::DEBUG)));

    ui_.cbxConsoleLogLevel->setCurrentIndex(ui_.cbxConsoleLogLevel->findData(QString::fromStdString(EnumToString<Severity>::toString(prefs_.console_level()))));
    ui_.cbxFileLogLevel->setCurrentIndex(ui_.cbxConsoleLogLevel->findData(QString::fromStdString(EnumToString<Severity>::toString(prefs_.file_level()))));
    ui_.ledDBName->setText(prefs_.db_name());
    ui_.ledDBHost->setText(prefs_.db_host());
    ui_.ledDBUser->setText(prefs_.db_user());
    ui_.ledDBPassword->setText(prefs_.db_password());
}

void DlgPreferences::on_dlgPreferences_accepted() {
    TRACE_ME();

    bool log_levels_changed{false};
    bool db_prefs_changed{false};

    Severity selected_console_level = EnumToString<Severity>::fromString(ui_.cbxConsoleLogLevel->currentData().toString().toStdString());
    Severity selected_file_level    = EnumToString<Severity>::fromString(ui_.cbxFileLogLevel->currentData().toString().toStdString());
    if(selected_console_level != prefs_.console_level() ||
       selected_file_level    != prefs_.file_level()) {
        prefs_.set_console_level(selected_console_level);
        prefs_.set_file_level(selected_file_level);
        log_levels_changed = true;
    }

    if(ui_.ledDBName->text()     != prefs_.db_name() ||
       ui_.ledDBHost->text()     != prefs_.db_host() ||
       ui_.ledDBUser->text()     != prefs_.db_user() ||
       ui_.ledDBPassword->text() != prefs_.db_password()) {
        prefs_.set_db_name(ui_.ledDBName->text());
        prefs_.set_db_host(ui_.ledDBHost->text());
        prefs_.set_db_user(ui_.ledDBUser->text());
        prefs_.set_db_password(ui_.ledDBPassword->text());
        db_prefs_changed = true;
    }

    if(log_levels_changed)
        the_logger = std::make_unique<FileLogger>(std::make_unique<ConsoleLogger>(std::make_unique<Logger>(),
                                                                                  prefs_.console_level()),
                                                  prefs_.file_level(),
                                                  prefs_.app_name().toStdString() + ".log");

    if(db_prefs_changed) {
        QSqlDatabase default_db = QSqlDatabase::database(QSqlDatabase::defaultConnection, false);

        default_db.close();
        default_db.setHostName(prefs_.db_host());
        default_db.setDatabaseName(prefs_.db_name());
        default_db.setUserName(prefs_.db_user());
        default_db.setPassword(prefs_.db_password());
        default_db.open();
    }

    if(log_levels_changed || db_prefs_changed) prefs_.save();
}

void DlgPreferences::on_psbTestConnection_clicked() {
    TRACE_ME();

    {
        QSqlDatabase test_db = QSqlDatabase::addDatabase("QMYSQL", "connection_test");

        test_db.setDatabaseName(ui_.ledDBName->text());
        test_db.setHostName(ui_.ledDBHost->text());
        test_db.setUserName(ui_.ledDBUser->text());
        test_db.setPassword(ui_.ledDBPassword->text());
        LOG(DEBUG) << "TestConnection db_name: \"" << ui_.ledDBName->text().toStdString() << "\", "
                   << "host: \"" << ui_.ledDBHost->text().toStdString() << "\", "
                   << "user: \"" << ui_.ledDBUser->text().toStdString() << "\", "
                   << "password: \"" << ui_.ledDBPassword->text().toStdString() << "\"";

        test_db.open();
        if(test_db.isOpen()) {
            LOG(DEBUG) << "TestConnection success";
            QMessageBox::information(this, "Database Connection", "Testing Database Connection was SUCCESSFUL.");
            test_db.close();
        } else {
            LOG(DEBUG) << "TestConnection failed: " << test_db.lastError().text().toStdString();
            QMessageBox::information(this, "Database Connection", "Testing Database Connection FAILED.");
        }
    }

    QSqlDatabase::removeDatabase("connection_test");
}
