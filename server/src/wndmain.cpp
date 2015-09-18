#include "wndmain.h"
#include "dlgpreferences.h"

WndMain::WndMain(DoDAPreferences &prefs, QWidget *parent) : QMainWindow(parent),
                                                            prefs_{prefs} {
    ui_.setupUi(this);
}

void WndMain::on_actPreferences_triggered(bool) {
    DlgPreferences preferences_dialog(prefs_, this);
    preferences_dialog.exec();
}
