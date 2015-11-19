#include "dlgstatus.h"

DlgStatus::DlgStatus(QWidget *parent) : QDialog(parent) {
    ui_.setupUi(this);
}

void DlgStatus::addStatusEntry(const QString& text, bool status) {
    QString status_text = (status ? ": <font color=\"Green\">OK</font>" : ": <font color=\"Red\">NOK</font>");
    ui_.tedStatus->append(text + status_text);
    if(!status) overall_status_ = false;
}
