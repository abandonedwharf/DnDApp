#include "hitdie.h"
#include "ui_hitdie.h"

HitDie::HitDie(std::vector<dndobjs::DDDice*> hd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HitDie)
{
    ui->setupUi(this);
    this->hitDie = hd;
    this->index = 0;

    this->setMaximumSize(115, 40);

    for (int i = 0; i < (int)hitDie.size(); i++)
    {
        this->maximums.push_back(hitDie[i]->GetDiceCount());
        ui->hitDieCBox->addItem(dndobjs::DiceText(hitDie[i]->GetDice()) + ((hitDie[i]->GetModifier() >= 0) ? "+" : "") + QString::number(hitDie[i]->GetModifier()));
    }

    ui->hitDieCount->setButtonSymbols(QAbstractSpinBox::NoButtons);

    this->setStyleSheet
            ("QLabel { font: 12pt 'Roboto Regular'; }"
             "QComboBox { background-color: #2A2D44; color: #FFFFFF; qproperty-frame: false; font: 12pt 'Roboto Regular'; }"
             "QComboBox::drop-down { border: none; }"
             "QSpinBox { background-color: #2A2D44; font: 12pt 'Roboto Regular'; color: #FFFFFF; qproperty-frame: false; }"
             );

    DisplayHitDie(index);
}

void HitDie::DisplayHitDie(int index)
{
    ui->hitDieCount->setMaximum(maximums[index]);
    ui->hitDieCount->setValue(hitDie[index]->GetDiceCount());
}

HitDie::~HitDie()
{
    delete ui;
}

void HitDie::on_hitDieCBox_currentIndexChanged(int index)
{
    DisplayHitDie(index);
}

void HitDie::on_hitDieCount_valueChanged(int arg1)
{
    hitDie[ui->hitDieCBox->currentIndex()]->SetCount(arg1);
}

