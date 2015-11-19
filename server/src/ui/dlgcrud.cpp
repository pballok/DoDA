#include "dlgcrud.h"

#include <tracer.h>

DlgCRUD::DlgCRUD(const QString &table_name, QWidget *parent) : QDialog(parent) {
    TRACE_ME();

    ui_.setupUi(this);

    ui_.bbxButtons->addButton("&Close", QDialogButtonBox::RejectRole);

    table_model_.setTable(table_name);
    table_model_.select();

    ui_.tbvCRUD->setModel(&table_model_);

    TRACE_RESULT("row count", table_model_.rowCount());
}
