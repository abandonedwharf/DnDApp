#include "itemwidget.h"
#include "ui_itemwidget.h"
#include "dropdownlabel.h"

ItemWidget::ItemWidget(dndobjs::InventoryNode *obj, int i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemWidget)
{
    ui->setupUi(this);

    this->index = i;

    DropDownLabel *itemDDL = new DropDownLabel(obj->GetObject(), this);

    itemDDL->setGeometry(200, 0, 400, 25);
}

ItemWidget::~ItemWidget()
{
    delete ui;
}
