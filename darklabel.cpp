#include "darklabel.h"
#include "ui_darklabel.h"

DarkLabel::DarkLabel(QString mainText, int width, int height, int fontSize, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DarkLabel)
{
    ui->setupUi(this);

    this->setMaximumSize(width, height); this->setMinimumSize(width, height);

    ui->darkLabel->setText(mainText);
    ui->darkLabel->setMinimumSize(width, height); ui->darkLabel->setMaximumSize(width, height);
    ui->darkLabel->setStyleSheet("font: " + QString::number(fontSize) + "pt 'Roboto Regular'; background-color: #2A2D44; color: #FFFFFF;");

    ui->label->setFixedSize(0, 0);
}

DarkLabel::DarkLabel(QString mainText, QString labelText, int width, int height, int fontSize, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DarkLabel)
{
    ui->setupUi(this);

    this->setMaximumSize(145, height); this->setMinimumSize(145, height);

    ui->darkLabel->setText(mainText);
    ui->darkLabel->setMinimumSize(width, height); ui->darkLabel->setMaximumSize(width, height);
    ui->darkLabel->setStyleSheet("font: " + QString::number(fontSize) + "pt 'Roboto Regular'; background-color: #2A2D44; color: #FFFFFF;");

    ui->label->setText(labelText);
    ui->label->setMinimumSize(145 - width, height); ui->label->setMaximumSize(145 - width, height);
    ui->label->setStyleSheet("font: " + QString::number(fontSize) + "pt 'Roboto Regular';");
}

DarkLabel::DarkLabel(QString mainText, QString labelText, int width, int height, int fontSize, bool prof, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DarkLabel)
{
    ui->setupUi(this);

    this->setMaximumSize(145, height); this->setMinimumSize(145, height);

    ui->darkLabel->setText(mainText);
    ui->darkLabel->setMinimumSize(width, height); ui->darkLabel->setMaximumSize(width, height);
    ui->darkLabel->setStyleSheet("font: " + QString::number(fontSize) + "pt 'Roboto Regular'; background-color: #2A2D44;");

    ui->label->setText(labelText);
    ui->label->setMinimumSize(145 - width, height); ui->label->setMaximumSize(145 - width, height);
    ui->label->setStyleSheet("font: " + QString::number(fontSize) + "pt 'Roboto Regular';" + ((prof) ?  " text-decoration: underline;" : ""));
}

void DarkLabel::SetColor(QString col) { ui->label->setStyleSheet("color: " + col + ";"); }

void DarkLabel::FlipDirection()
{
    ui->label->setStyleSheet("font: 16pt 'Roboto Regular';");
    ui->horizontalLayout->removeWidget(ui->darkLabel); ui->horizontalLayout->removeWidget(ui->label);
    ui->horizontalLayout->addWidget(ui->label, 0); ui->horizontalLayout->addWidget(ui->darkLabel, 1);
}

void DarkLabel::ExpandTotalSize(int width, int height)
{
    this->setMaximumSize(width, height); this->setMinimumSize(width, height);
    if (ui->label->width() > 0)
    {
        ui->label->setMaximumSize(width - (ui->darkLabel->maximumWidth()), height); ui->label->setMinimumSize(width - (ui->darkLabel->maximumWidth()), height);
    }
}

QString DarkLabel::GetMainText() { return ui->darkLabel->text(); }

QString DarkLabel::GetLabelText() { return ui->label->text(); }

void DarkLabel::SetMainText(QString text) { ui->darkLabel->setText(text); }

void DarkLabel::SetLabelText(QString text) { ui->label->setText(text); }

void DarkLabel::SetLeftSpacer(int spcWidth) { ui->horizontalSpacer->changeSize(spcWidth, 0); }

DarkLabel::~DarkLabel()
{
    delete ui;
}
