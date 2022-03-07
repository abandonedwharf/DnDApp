#include "introwindow.h"
#include "ui_introwindow.h"

IntroWindow::IntroWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IntroWindow)
{
    ui->setupUi(this);

    this->setStyleSheet(
                "QWidget { background-color: #A1B2CA; }"
                "QPushButton { color: #FFFFFF; font: 16pt 'Roboto Regular'; background-color: #5F6983; border: none; }"
                "QPushButton#ExitButton { font: 30pt 'Roboto Regular'; color: #A1B2CA; }"
                "QPushButton#ExitButton::hover { background-color: #2A2D44; }"
                "QPushButton#ExitButton::clicked { background-color: #A1B2CA; }"
                "QPushButton#MinimiseButton { font: 30pt 'Roboto Regular'; color: #A1B2CA; }"
                "QPushButton#MinimiseButton::hover { background-color: #2A2D44; }"
                "QPushButton#MinimiseButton::clicked { background-color: #A1B2CA; }"
                );

    this->setWindowFlags(Qt::FramelessWindowHint);
}

IntroWindow::~IntroWindow()
{
    delete ui;
}

void IntroWindow::on_MinimiseButton_clicked()
{
    this->hide();
}

void IntroWindow::on_ExitButton_clicked()
{
    this->close();
}

