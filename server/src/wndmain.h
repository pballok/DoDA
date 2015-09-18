#ifndef WND_MAIN_H
#define WND_MAIN_H

#include "dodapreferences.h"
#include "ui_wndmain.h"

class WndMain : public QMainWindow {
    Q_OBJECT

public:
    WndMain(DoDAPreferences& prefs, QWidget* parent = 0);

protected slots:
    void on_actPreferences_triggered(bool);

private:
    Ui::wndMain      ui_;
    DoDAPreferences& prefs_;
};

#endif
