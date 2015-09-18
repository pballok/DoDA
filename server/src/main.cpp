#include <QApplication>

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

    WndMain mainWin(prefs);
    mainWin.setWindowTitle(prefs.app_name() + " " + prefs.version());
    mainWin.show();

    int ret = app.exec();

    LOG(INFO) << prefs.app_name().toStdString() << " version " << prefs.version().toStdString() << " ended";

    return ret;
}
