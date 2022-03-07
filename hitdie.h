#ifndef HITDIE_H
#define HITDIE_H

#include <QWidget>
#include <dndobjects.h>

namespace Ui {
class HitDie;
}

class HitDie : public QWidget
{
    Q_OBJECT

public:
    explicit HitDie(std::vector<dndobjs::DDDice*> hd, QWidget *parent = nullptr);
    ~HitDie();

private slots:
    void DisplayHitDie(int index);

    void on_hitDieCBox_currentIndexChanged(int index);

    void on_hitDieCount_valueChanged(int arg1);

private:
    Ui::HitDie *ui;
    std::vector<dndobjs::DDDice*> hitDie;
    std::vector<uint> maximums;
    uint index;
};

#endif // HITDIE_H
