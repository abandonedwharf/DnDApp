#include "deathsaves.h"
#include "ui_deathsaves.h"

DeathSaves::DeathSaves(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeathSaves)
{
    ui->setupUi(this);
    this->setStyleSheet("QLabel { font: 16pt 'Roboto Regular'; }");

    ui->death1->setStyleSheet("QRadioButton::indicator { width: 25px; height: 25px; background-color: #2A2D44; border-radius: 12px; border-width: 1px; border-color: #2A2D44; }"
                              "QRadioButton::indicator::checked { background-color: rgba(0,0,0,0); }"
                              "QRadioButton::checked { border-image: url(:/images/resources/images/skull.PNG) 0 0 0 0 stretch stretch; }");

    ui->death2->setStyleSheet("QRadioButton::indicator { width: 25px; height: 25px; background-color: #2A2D44; border-radius: 12px; border-width: 1px; border-color: #2A2D44; }"
                              "QRadioButton::indicator::checked { background-color: rgba(0,0,0,0); }"
                              "QRadioButton::checked { border-image: url(:/images/resources/images/skull.PNG) 0 0 0 0 stretch stretch; }");

    ui->death3->setStyleSheet("QRadioButton::indicator { width: 25px; height: 25px; background-color: #2A2D44; border-radius: 12px; border-width: 1px; border-color: #2A2D44; }"
                              "QRadioButton::indicator::checked { background-color: rgba(0,0,0,0); }"
                              "QRadioButton::checked { border-image: url(:/images/resources/images/skull.PNG) 0 0 0 0 stretch stretch; }");


    ui->life1->setStyleSheet("QRadioButton::indicator { width: 25px; height: 25px; background-color: #2A2D44; border-radius: 12px; border-width: 1px; border-color: #2A2D44; }"
                              "QRadioButton::indicator::checked { background-color: rgba(0,0,0,0); }"
                              "QRadioButton::checked { border-image: url(:/images/resources/images/heart.png) 0 0 0 0 stretch stretch; }");

    ui->life2->setStyleSheet("QRadioButton::indicator { width: 25px; height: 25px; background-color: #2A2D44; border-radius: 12px; border-width: 1px; border-color: #2A2D44; }"
                              "QRadioButton::indicator::checked { background-color: rgba(0,0,0,0); }"
                              "QRadioButton::checked { border-image: url(:/images/resources/images/heart.png) 0 0 0 0 stretch stretch; }");

    ui->life3->setStyleSheet("QRadioButton::indicator { width: 25px; height: 25px; background-color: #2A2D44; border-radius: 12px; border-width: 1px; border-color: #2A2D44; }"
                              "QRadioButton::indicator::checked { background-color: rgba(0,0,0,0); }"
                              "QRadioButton::checked { border-image: url(:/images/resources/images/heart.png) 0 0 0 0 stretch stretch; }");

}

DeathSaves::~DeathSaves()
{
    delete ui;
}
