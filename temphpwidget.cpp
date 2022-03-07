#include "temphpwidget.h"
#include "ui_temphpwidget.h"

TempHPWidget::TempHPWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TempHPWidget)
{
    ui->setupUi(this);

    ui->spinBox->setStyleSheet("background-color: #2A2D44; font: 16pt 'Roboto Regular'; color: #FFFFFF; qproperty-frame: false;");
    ui->spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->label->setStyleSheet("font: 12pt 'Roboto Regular';");
}

TempHPWidget::~TempHPWidget()
{
    delete ui;
}
