#include "tracer.h"

#include "wndmain.h"
#include "dlgpreferences.h"
#include "dlgmaintenance.h"
#include "dlgcrud.h"

WndMain::WndMain(DoDAPreferences &prefs, QWidget *parent) : QMainWindow(parent),
                                                            prefs_{prefs} {
    ui_.setupUi(this);
}

void WndMain::on_actPreferences_triggered(bool) {
    TRACE_ME();

    DlgPreferences preferences_dialog(prefs_, this);
    preferences_dialog.exec();
}

void WndMain::on_actMaintenance_triggered(bool) {
    TRACE_ME();

    DlgMaintenance maintenance_dialog(prefs_, this);
    maintenance_dialog.exec();
}

void WndMain::on_actMaps_triggered(bool) {
    TRACE_ME();

    DlgCRUD maps_dialog("maps", this);
    maps_dialog.exec();
}
