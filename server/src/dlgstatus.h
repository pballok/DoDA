#ifndef DLG_STATUS_H
#define DLG_STATUS_H

#include "dodapreferences.h"
#include "ui_dlgstatus.h"

class DlgStatus : public QDialog {
    Q_OBJECT

public:
    explicit DlgStatus(QWidget* parent = 0);

private:
    Ui::dlgStatus ui_;
};

#endif
