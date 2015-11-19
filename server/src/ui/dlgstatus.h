#ifndef DLG_STATUS_H
#define DLG_STATUS_H

#include "dodapreferences.h"
#include "ui_dlgstatus.h"

class DlgStatus : public QDialog {
    Q_OBJECT

public:
    explicit DlgStatus(QWidget* parent = 0);

    void addStatusEntry(const QString& text, bool status);
    bool overallStatus() const { return overall_status_; }

private:
    Ui::dlgStatus ui_;
    bool overall_status_{true};
};

#endif
