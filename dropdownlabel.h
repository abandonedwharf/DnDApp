#ifndef DROPDOWNLABEL_H
#define DROPDOWNLABEL_H

#include <QWidget>
#include <QPropertyAnimation>
#include "dndobjects.h"

namespace Ui {
class DropDownLabel;
}

class DropDownLabel : public QWidget
{
    Q_OBJECT

public:
    DropDownLabel(QString buttonText, QString dropDownText, QWidget *parent = nullptr);
    DropDownLabel(dndobjs::DDWeapon* weapon, int atkBonus, QWidget *parent = nullptr);
    DropDownLabel(dndobjs::DDSpell* spell, QWidget *parent = nullptr, int atkBonus = 0);
    DropDownLabel(dndobjs::DDObject* object, QWidget *parent = nullptr);
    ~DropDownLabel();

private slots:
    void on_dropDownButton_clicked();

private:
    Ui::DropDownLabel *ui;
    bool dropped;
    QPropertyAnimation *labelAnim, *wholeAnim;
    int heightDrop;
    QWidget* dropWidget;
};

#endif // DROPDOWNLABEL_H
