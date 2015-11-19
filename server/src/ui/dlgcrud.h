#ifndef DLGCRUD_H
#define DLGCRUD_H

#include <QSqlTableModel>

#include "ui_dlgcrud.h"

class DlgCRUD : public QDialog {
    Q_OBJECT

public:
    explicit DlgCRUD( const QString& table_name, QWidget* parent = 0);

private:
    QSqlTableModel table_model_;
    Ui::dlgCRUD    ui_;
};

#endif
