#include "statdisplay.h"
#include "ui_statdisplay.h"

StatDisplay::StatDisplay(QString statName, ushort stat, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatDisplay)
{
    ui->setupUi(this);
    ui->statName->setText(statName);
    ui->statNumber->setText(QString::number(stat));
    short modifier = (stat - 10) / 2;

    ui->statModifier->setText((modifier > 0 ? "+" : "") + QString::number(modifier));

    this->setStyleSheet("QLabel { background-color: #2A2D44; } QLabel#statName { background-color: #5F6983; } QLabel#statNumber { font: 24pt 'Roboto Regular'; }");
}

StatDisplay::~StatDisplay()
{
    delete ui;
}
