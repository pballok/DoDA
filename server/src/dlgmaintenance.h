#ifndef DLG_MAINTENANCE_H
#define DLG_MAINTENANCE_H

#include <map>

#include "dodapreferences.h"
#include "ui_dlgmaintenance.h"

// using DBStatusMap = std::map<QString, bool>;

class DlgMaintenance : public QDialog {
    Q_OBJECT

public:
    DlgMaintenance(DoDAPreferences& prefs, QWidget* parent = 0);

protected slots:
    void on_psbCheck_clicked();

private:
    Ui::dlgMaintenance ui_;
    DoDAPreferences&   prefs_;
//    DBStatusMap        db_status_;

    bool checkDBStatus() noexcept;
};

#endif
