#include "dropdownlabel.h"
#include "ui_dropdownlabel.h"
#include "dropdisplay.h"
#include <QLabel>

DropDownLabel::DropDownLabel(QString buttonText, QString dropDownText, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDownLabel)
{
    ui->setupUi(this);

    float lines = dropDownText.size() / 33;
    heightDrop = (std::ceil(lines) * 18) + 10;

    ui->dropDownButton->setStyleSheet("border: none; background-color: #5F6983; color: #FFFFFF; font: 16pt 'Roboto Regular'; text-align: left;");
    ui->dropDownButton->setText(buttonText);

    QLabel *textLabel = new QLabel(this);
    textLabel->setText(dropDownText);
    textLabel->setStyleSheet("font: 16pt 'Roboto Regular'; text-align: left;");
    textLabel->setGeometry(0, 0, this->width(), this->height());
    textLabel->lower();
    textLabel->setWordWrap(true);

    dropWidget = textLabel;

    dropped = false;
}

DropDownLabel::DropDownLabel(dndobjs::DDWeapon* weapon, int atkBonus, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDownLabel)
{
    ui->setupUi(this);

    ui->dropDownButton->setStyleSheet("border: none; background-color: #5F6983; color: #FFFFFF; font: 16pt 'Roboto Regular'; text-align: left;");
    ui->dropDownButton->setText(weapon->GetName() + " (" + (weapon->IsMagical() ? "magical " : "") + weapon->GetWeaponTypeText() + ")");

    DropDisplay* wpnWdg = new DropDisplay(weapon, atkBonus, this);
    wpnWdg->setGeometry(0, 0, this->width(), this->height());
    wpnWdg->lower();

    heightDrop = wpnWdg->GetHeight();

    dropWidget = wpnWdg;

    dropped = false;
}

DropDownLabel::DropDownLabel(dndobjs::DDSpell* spell, QWidget *parent, int atkBonus) :
    QWidget(parent),
    ui(new Ui::DropDownLabel)
{
    ui->setupUi(this);

    ui->dropDownButton->setStyleSheet("border: none; background-color: #5F6983; color: #FFFFFF; font: 16pt 'Roboto Regular'; text-align: left;");
    ui->dropDownButton->setText(spell->GetName() + " (Level " + QString::number(spell->GetLevel()) + " " + spell->GetSchoolText() + ")");

    DropDisplay *splWdg = new DropDisplay(spell, atkBonus, this);
    splWdg->setGeometry(0, 0, this->width(), this->height());
    splWdg->lower();

    heightDrop = splWdg->GetHeight();

    dropWidget = splWdg;

    dropped = false;
}

DropDownLabel::DropDownLabel(dndobjs::DDObject* object, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDownLabel)
{
    ui->setupUi(this);

    ui->dropDownButton->setStyleSheet("border: none; background-color: #5F6983; color: #FFFFFF; font: 16pt 'Roboto Regular'; text-align: left;");
    ui->dropDownButton->setText(object->GetName() + " (" + object->GetRarityText() + " " + object->GetTypeText() + ")");

    DropDisplay *objWdg = new DropDisplay(object, this);
    objWdg->setGeometry(0, 0, this->width(), this->height());
    objWdg->lower();

    heightDrop = objWdg->GetHeight();

    dropWidget = objWdg;

    dropped = false;
}

DropDownLabel::~DropDownLabel()
{
    delete ui;
}

void DropDownLabel::on_dropDownButton_clicked()
{
    if (!dropped)
    {
        labelAnim = new QPropertyAnimation(dropWidget, "geometry");
        labelAnim->setStartValue(dropWidget->geometry());
        labelAnim->setEndValue(QRect(dropWidget->x(), 25, dropWidget->width(), heightDrop));

        wholeAnim = new QPropertyAnimation(this, "minimumHeight");
        wholeAnim->setStartValue(25);
        wholeAnim->setEndValue(heightDrop + 25);

        labelAnim->start(QAbstractAnimation::DeleteWhenStopped);
        wholeAnim->start(QAbstractAnimation::DeleteWhenStopped);
    }
    else
    {
        labelAnim = new QPropertyAnimation(dropWidget, "geometry");
        labelAnim->setStartValue(dropWidget->geometry());
        labelAnim->setEndValue(QRect(dropWidget->x(), 0, dropWidget->width(), 25));

        wholeAnim = new QPropertyAnimation(this, "minimumHeight");
        wholeAnim->setStartValue(this->height());
        wholeAnim->setEndValue(25);

        labelAnim->start(QAbstractAnimation::DeleteWhenStopped);
        wholeAnim->start(QAbstractAnimation::DeleteWhenStopped);
    }
    dropped = !dropped;
}

