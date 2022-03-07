#include "dropdisplay.h"
#include "ui_dropdisplay.h"
#include <QLabel>

DropDisplay::DropDisplay(dndobjs::DDWeapon *weapon, int atkBonus, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDisplay)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel { background-color: #2A2D44; font: 12pt 'Roboto Regular'; color: #FFFFFF; padding: 5px; }");
    ui->verticalLayout->setAlignment(Qt::AlignTop);

    this->AddLayer(0.3, "Attack: " + dndobjs::SignedModifierText(atkBonus), weapon->GetDieText() + " damage");
    this->AddLayer("Properties: " + weapon->GetWeaponPropertiesText());

    for (int i = 0; i < weapon->GetSpecialPropertyCount(); i++)
    {
        this->AddLayer(weapon->GetSpecialProperty(i)->ToString(), (std::ceil(weapon->GetSpecialProperty(i)->ToString().size() / 33) * 16) + 10);
    }
}

DropDisplay::DropDisplay(dndobjs::DDSpell *spell, int atkBonus, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDisplay)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel { background-color: #2A2D44; font: 12pt 'Roboto Regular'; color: #FFFFFF; padding: 5px; }");
    ui->verticalLayout->setAlignment(Qt::AlignTop);

    this->AddLayer(0.5, "Cast Time: " + spell->GetCastTime(), "Duration: " + spell->GetDuration());
    this->AddLayer(0.4, "Range: " + QString::number(spell->GetRange()) + " feet", "Components: " + spell->GetSpellComponentsText());
    this->AddLayer("Description: " + spell->GetDescription(), (std::ceil((spell->GetDescription().size() + 12) / 33) * 16) + 10);

    if (spell->GetMetaType() % 2 != 0)
    {
        dndobjs::DDAttackSpell *attkSpell = dynamic_cast<dndobjs::DDAttackSpell*>(spell);
        this->AddLayer(0.25, "Attack: " + dndobjs::SignedModifierText(atkBonus), attkSpell->GetDmgDiceText() + " damage", 35, 0);
    }
    if (spell->GetMetaType() == 2 || spell->GetMetaType() == 3)
    {
        dndobjs::DDShape *aoe = dynamic_cast<dndobjs::DDShape*>(spell);
        this->AddLayer(0.5, "Size: " + QString::number(aoe->GetSize()) + " feet", "Shape: " + aoe->GetShape(), 35, (spell->GetMetaType() % 2 != 0));
    }
}

DropDisplay::DropDisplay(dndobjs::DDObject *object, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDisplay)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel { background-color: #2A2D44; font: 12pt 'Roboto Regular'; color: #FFFFFF; padding: 5px; }");
    ui->verticalLayout->setAlignment(Qt::AlignTop);

    this->AddLayer(0.5, "Eqiup pos: " + object->GetEquipmentPositionText(), "Price: " + object->GetPriceText());
    this->AddLayer(object->GetDescription(), (std::ceil(object->GetDescription().size() / 33) * 16) + 10);
}

void DropDisplay::AddLayer(float ratio, QString left, QString right, int height, int pos)
{
    QLabel *leftLabel = new QLabel(left, this);

    QLabel *rightLabel = new QLabel(right, this);

    leftLabel->setFixedSize((400 * ratio) - 5, height);
    rightLabel->setFixedSize((400 * (1 - ratio)) - 5, height);

    leftLabel->setWordWrap(true);
    rightLabel->setWordWrap(true);

    QHBoxLayout *layer = new QHBoxLayout(this);
    layer->addWidget(leftLabel);
    layer->addItem(new QSpacerItem(10, 5));
    layer->addWidget(rightLabel);

    if (pos >= 0)
    {
        ui->verticalLayout->insertLayout(pos, layer);
        //ui->verticalLayout->insertItem(pos + 1, new QSpacerItem(10, 10));
    }
    else
    {
        ui->verticalLayout->addLayout(layer);
        //ui->verticalLayout->addItem(new QSpacerItem(10, 10));
    }
}

void DropDisplay::AddLayer(QString text, int height, int pos)
{
    QLabel *label = new QLabel(text, this);

    label->setFixedSize(400, height);
    label->setWordWrap(true);

    if (pos >= 0)
    {
        ui->verticalLayout->insertWidget(pos, label);
    }
    else
    {
        ui->verticalLayout->addWidget(label);
    }
}

ushort DropDisplay::GetHeight()
{
    ushort rtrn = 0;
    for (int i = 0; i < (int)ui->verticalLayout->count(); i++)
    {
        QLayoutItem *thisItem = ui->verticalLayout->itemAt(i);
        if (thisItem->layout() != nullptr)
        {
            rtrn += thisItem->layout()->itemAt(0)->widget()->height() + 5;
        }
        else if (thisItem->widget() != nullptr)
        {
            rtrn += thisItem->widget()->height() + 5;
        }
    }
    return rtrn;
}

DropDisplay::~DropDisplay()
{
    delete ui;
}
