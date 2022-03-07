#include "spellswidget.h"
#include "ui_spellswidget.h"
#include "dropdowndarklabel.h"
#include "dropdownlabel.h"
#include "spellslotswidget.h"
#include <QLabel>
#include <QScrollArea>

SpellsWidget::SpellsWidget(dndobjs::DDPlayerCharacter *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpellsWidget)
{
    ui->setupUi(this);

    player = p;

    this->setStyleSheet("QLabel { color: #2A2D44; font: 20pt 'Roboto Regular'; }");

    //Setup Spell Save DC

    QLabel *spellDCHead = new QLabel(this);
    spellDCHead->setText("Spell Save DC");
    ui->leftLayout->addWidget(spellDCHead, 0, Qt::AlignTop);

    DropDownDarkLabel *spellDCDDL;
    bool dcInit = false;
    for (int i = 0; i < player->GetClassCount(); i++)
    {
        if (player->GetClass(i)->CanCastSpells())
        {
            int dc = 10 + player->GetProficiencyBonus() + player->GetStatModifier(player->GetClass(i)->GetSpellStat());
            if (dcInit)
            {
                spellDCDDL->AddNode(QString::number(dc), player->GetClass(i)->GetName());
            }
            else
            {
                spellDCDDL = new DropDownDarkLabel(QString::number(dc), player->GetClass(i)->GetName(), 45, 45, this);
                dcInit = true;
            }
        }
    }
    if (!dcInit)
    {
        spellDCDDL = new DropDownDarkLabel("N/A", 45, 45, this);
    }
    ui->leftLayout->addWidget(spellDCDDL, 0, Qt::AlignTop);

    // Setup Spell Slots

    QLabel *spellSlotHead = new QLabel(this);
    spellSlotHead->setText("Spell Slots");
    ui->rightLayout->addWidget(spellSlotHead, 0, Qt::AlignTop);

    SpellSlotsWidget *slotsWidget = new SpellSlotsWidget(5, "Level 1", this);
    ui->rightLayout->addWidget(slotsWidget, 0, Qt::AlignTop);
    slotsWidget->AddLayer(4, "Level 2");
    slotsWidget->AddLayer(3, "Level 3");
    slotsWidget->AddLayer(2, "Level 4");
    slotsWidget->AddLayer(1, "Level 5");

    //Setup Spell Scroll Area

    QScrollArea *spellArea = new QScrollArea(this);
    spellArea->setFixedSize(930, 870);
    spellArea->setWidgetResizable(true);
    ui->verticalLayout->addWidget(spellArea, 0, Qt::AlignTop);
    QWidget *spllWdg = new QWidget(this);
    spellArea->setWidget(spllWdg);
    QHBoxLayout *hSpell = new QHBoxLayout(spllWdg);
    spllWdg->setLayout(hSpell);
    QVBoxLayout *leftSpell = new QVBoxLayout(spllWdg); QVBoxLayout *rightSpell = new QVBoxLayout(spllWdg);
    leftSpell->setContentsMargins(0,0,0,0); rightSpell->setContentsMargins(0,0,0,0);
    leftSpell->setAlignment(Qt::AlignTop); rightSpell->setAlignment(Qt::AlignTop);
    hSpell->addLayout(leftSpell); hSpell->addLayout(rightSpell);
    spellArea->setStyleSheet("background-color: #A1B2CA; border: none;");

    for (int i = 0; i < player->GetSpellCount(); i++)
    {
        int atkBonus = player->GetStatModifier(player->GetSpell(i)->GetClass(0)->GetSpellStat()) + player->GetProficiencyBonus();
        DropDownLabel *spellDDL = new DropDownLabel(player->GetSpell(i), this, atkBonus);

        QVBoxLayout *layout = (i % 2 == 0) ? leftSpell : rightSpell;
        layout->addWidget(spellDDL, 0, Qt::AlignTop);
    }
}

SpellsWidget::~SpellsWidget()
{
    delete ui;
}
