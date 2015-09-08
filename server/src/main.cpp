#include <QApplication>

#include "dodapreferences.h"
#include "mainwindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    DoDAPreferences prefs;

    MainWindow mainWin;
    mainWin.setWindowTitle(prefs.app_name() + " " + prefs.version());
    mainWin.show();

    return app.exec();
}
