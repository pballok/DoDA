#ifndef DLG_MAINTENANCE_H
#define DLG_MAINTENANCE_H

#include <map>

#include <QString>

#include "dodapreferences.h"
#include "ui_dlgmaintenance.h"

using DBTableDesc = std::map<QString, QString>;

class DlgMaintenance : public QDialog {
    Q_OBJECT

public:
    DlgMaintenance(DoDAPreferences& prefs, QWidget* parent = 0);

protected slots:
    void on_psbCheck_clicked();
    void on_psbWipe_clicked();
    void on_psbCreateMissing_clicked();
    void on_psbTestData_clicked();

private:
    enum class DBStatus {OK, NOK, UNDETERMINED, PENDING};
    Ui::dlgMaintenance  ui_;
    DoDAPreferences&    prefs_;
    DBTableDesc         db_tables_{{"maps", "`id`     mediumint(8) UNSIGNED NOT NULL AUTO_INCREMENT,"
                                            "`name`   varchar(255)          NOT NULL,"
                                            "`size_x` smallint(5)  UNSIGNED NOT NULL,"
                                            "`size_y` smallint(5)  UNSIGNED NOT NULL,"
                                            "PRIMARY KEY (`id`)"}};

    bool checkDBStatus() noexcept;
    void setStatusDisplay(DBStatus status) noexcept;
};

#endif
