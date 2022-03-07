#include "actionwidget.h"
#include "ui_actionwidget.h"

ActionWidget::ActionWidget(QString top, QString bot, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionWidget)
{
    ui->setupUi(this);

    ui->label->setText(top);
    ui->label_2->setText(bot);

    ui->label->setStyleSheet("background-color: #2A2D44; font: 16pt 'Roboto Regular'; color: #FFFFFF; padding: 2px;");
    ui->label_2->setStyleSheet("background-color: #5F6983; font: 10pt 'Roboto Regular'; color: #FFFFFF; padding: 2px;");
}

ActionWidget::~ActionWidget()
{
    delete ui;
}
