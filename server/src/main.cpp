#include <QApplication>

#include <logger.h>

#include "dodapreferences.h"
#include "mainwindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    DoDAPreferences prefs;
    prefs.load();

    the_logger = std::make_shared<FileLogger>(std::make_unique<ConsoleLogger>(std::make_unique<Logger>(),
                                                                              prefs.console_level()),
                                              prefs.file_level(),
                                              prefs.app_name().toStdString() + ".log");

    LOG(INFO) << prefs.app_name().toStdString() << " version " << prefs.version().toStdString() << " started";

    MainWindow mainWin;
    mainWin.setWindowTitle(prefs.app_name() + " " + prefs.version());
    mainWin.show();

    int ret = app.exec();

    LOG(INFO) << prefs.app_name().toStdString() << " version " << prefs.version().toStdString() << " ended";

    return ret;
}
