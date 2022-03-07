#include "inventorywidget.h"
#include "ui_inventorywidget.h"
#include "itemwidget.h"

InventoryWidget::InventoryWidget(dndobjs::DDPlayerCharacter *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryWidget)
{
    ui->setupUi(this);

    this->player = p;

    dndobjs::InventoryNode *currentNode = player->GetHeadInventoryNode()->Next();
    for (int i = 0; i < player->GetHeadInventoryNode()->Count(); i++)
    {
        ui->rightLayout->addWidget(new ItemWidget(currentNode, i, this));
        currentNode = currentNode->Next();
    }
}

InventoryWidget::~InventoryWidget()
{
    delete ui;
}
