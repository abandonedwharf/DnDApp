#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include "dndobjects.h"

namespace Ui {
class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

signals:


public:
    explicit ItemWidget(dndobjs::InventoryNode *obj, int i, QWidget *parent = nullptr);
    ~ItemWidget();

private:
    Ui::ItemWidget *ui;
    int index;
};

#endif // ITEMWIDGET_H
