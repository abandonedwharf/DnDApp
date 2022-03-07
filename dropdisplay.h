#ifndef DROPDISPLAY_H
#define DROPDISPLAY_H

#include <QWidget>
#include "dndobjects.h"

namespace Ui {
class DropDisplay;
}

class DropDisplay : public QWidget
{
    Q_OBJECT

public:
    DropDisplay(dndobjs::DDWeapon *weapon, int atkBonus, QWidget *parent = nullptr);
    DropDisplay(dndobjs::DDSpell *spell, int atkBonus = 0, QWidget *parent = nullptr);
    DropDisplay(dndobjs::DDObject *object, QWidget *parent = nullptr);
    ~DropDisplay();
    ushort GetHeight();

private:
    void AddLayer(float ratio, QString left, QString right, int height = 35, int pos = -1);
    void AddLayer(QString text, int height = 35, int pos = -1);

private:
    Ui::DropDisplay *ui;
};

#endif // DROPDISPLAY_H
