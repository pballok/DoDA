#include <QApplication>
#include <QSqlDatabase>

#include <logger.h>

#include "dodapreferences.h"
#include "wndmain.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    DoDAPreferences prefs;
    prefs.load();

    the_logger = std::make_unique<FileLogger>(std::make_unique<ConsoleLogger>(std::make_unique<Logger>(),
                                                                              prefs.console_level()),
                                              prefs.file_level(),
                                              prefs.app_name().toStdString() + ".log");

    LOG(INFO) << prefs.app_name().toStdString() << " version " << prefs.version().toStdString() << " started";

    QSqlDatabase main_db_connection = QSqlDatabase::addDatabase("QMYSQL");
    main_db_connection.setHostName(prefs.db_host());
    main_db_connection.setDatabaseName(prefs.db_name());
    main_db_connection.setUserName(prefs.db_user());
    main_db_connection.setPassword(prefs.db_password());
    main_db_connection.open();

    WndMain mainWin(prefs);
    mainWin.setWindowTitle(prefs.app_name() + " " + prefs.version());
    mainWin.show();

    int ret = app.exec();

    main_db_connection.close();

    LOG(INFO) << prefs.app_name().toStdString() << " version " << prefs.version().toStdString() << " ended";

    return ret;
}
