#ifndef COMBATWIDGET_H
#define COMBATWIDGET_H

#include <QWidget>
#include "dndobjects.h"
#include "darklabel.h"

namespace Ui {
class CombatWidget;
}

class CombatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CombatWidget(dndobjs::DDPlayerCharacter *p, QWidget *parent = nullptr);
    ~CombatWidget();

private slots:
    void EquipArmour(int index);

    void EquipWeapon(int index);

    void EquipShield(int index);

private:
    Ui::CombatWidget *ui;
    dndobjs::DDPlayerCharacter *player;
    dndobjs::DDArmour *equippedArmour;
    dndobjs::DDWeapon *equippedWeapon;
    dndobjs::DDShield *equippedShield;

    int ac;

    std::vector<dndobjs::DDArmour*> armours;
    std::vector<dndobjs::DDWeapon*> weapons;
    std::vector<dndobjs::DDShield*> shields;

    DarkLabel* acLabel;
};

#endif // COMBATWIDGET_H
