#include "dlgcrudmaps.h"

DlgCRUDMaps::DlgCRUDMaps(QWidget *parent) : DlgCRUD("maps", parent) {
    setWindowTitle("Maps");

    table_model_.setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    table_model_.setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    table_model_.setHeaderData(2, Qt::Horizontal, QObject::tr("X Size"));
    table_model_.setHeaderData(3, Qt::Horizontal, QObject::tr("Y Size"));

    ui_.tbvCRUD->setColumnWidth(0, 50);
    ui_.tbvCRUD->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui_.tbvCRUD->setColumnWidth(2, 100);
    ui_.tbvCRUD->setColumnWidth(3, 100);
}
