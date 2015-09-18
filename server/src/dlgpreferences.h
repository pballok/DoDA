#ifndef DLG_PREFERENCES_H
#define DLG_PREFERENCES_H

#include "dodapreferences.h"
#include "ui_dlgpreferences.h"

class DlgPreferences : public QDialog {
    Q_OBJECT

public:
    DlgPreferences(DoDAPreferences& prefs, QWidget* parent = 0);

protected slots:
    void on_dlgPreferences_accepted();
    void on_psbTestConnection_clicked();

private:
    Ui::dlgPreferences ui_;
    DoDAPreferences&   prefs_;
};

#endif
