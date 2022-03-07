#ifndef INVENTORYWIDGET_H
#define INVENTORYWIDGET_H

#include <QWidget>
#include "dndobjects.h"

namespace Ui {
class InventoryWidget;
}

class InventoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryWidget(dndobjs::DDPlayerCharacter *p, QWidget *parent = nullptr);
    ~InventoryWidget();

private:
    Ui::InventoryWidget *ui;
    dndobjs::DDPlayerCharacter *player;
};

#endif // INVENTORYWIDGET_H
