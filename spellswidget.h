#ifndef SPELLSWIDGET_H
#define SPELLSWIDGET_H

#include <QWidget>
#include "dndobjects.h"

namespace Ui {
class SpellsWidget;
}

class SpellsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpellsWidget(dndobjs::DDPlayerCharacter *p, QWidget *parent = nullptr);
    ~SpellsWidget();

private:
    Ui::SpellsWidget *ui;
    dndobjs::DDPlayerCharacter *player;
};

#endif // SPELLSWIDGET_H
