#include "combatwidget.h"
#include "ui_combatwidget.h"
#include "dropdowndarklabel.h"
#include "dropdownlabel.h"
#include "actionwidget.h"
#include <QScrollArea>
#include <QComboBox>
#include <QLabel>

CombatWidget::CombatWidget(dndobjs::DDPlayerCharacter *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CombatWidget)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel { color: #2A2D44; font: 20pt 'Roboto Regular'; }");

    this->player = p;

    qDebug().nospace() << player->GetWeapons()[0]->GetDie();

    armours = player->GetArmours();
    shields = player->GetShields();
    weapons = player->GetWeapons();

    qDebug().nospace() << weapons[0]->GetDie();

    //Setup Layout

    QVBoxLayout *lLayout = new QVBoxLayout();
    QVBoxLayout *rLayout = new QVBoxLayout();
    QSpacerItem *space = new QSpacerItem(100, 2);
    ui->horizontalLayout->addLayout(lLayout);
    ui->horizontalLayout->addItem(space);
    ui->horizontalLayout->addLayout(rLayout);
    lLayout->setSpacing(10);rLayout->setSpacing(10);

    // Setup AC Widget

    acLabel = new DarkLabel(QString::number(player->GetAC()), "AC", 65, 65, 20, this);
    acLabel->SetColor("#2A2D44;");
    lLayout->addWidget(acLabel, 0, Qt::AlignTop);

    // Setup Speed Widget

    DarkLabel *speedLabel = new DarkLabel(QString::number(player->GetSpeed(dndobjs::walking)), "Speed", 65, 45, 20, this);
    speedLabel->ExpandTotalSize(200, 45); speedLabel->SetColor("#2A2D44;");
    lLayout->addWidget(speedLabel, 0, Qt::AlignTop);

    //Setup Shield Widget

    QLabel *shieldHead = new QLabel(this);
    shieldHead->setText("Shield");
    lLayout->addWidget(shieldHead, 0, Qt::AlignTop);

    DropDownDarkLabel *shieldDDL = new DropDownDarkLabel("none", 250, 45, this);
    for (int i = 0; i < (int)shields.size(); i++)
    {
        shieldDDL->AddNode(shields[i]->GetName());
    }
    lLayout->addWidget(shieldDDL, 0, Qt::AlignTop);

    connect(shieldDDL, &DropDownDarkLabel::selectionChanged, this, &CombatWidget::EquipShield);

    //Setup Armour Widget

    QLabel *armourHead = new QLabel(this);
    armourHead->setText("Armour");
    lLayout->addWidget(armourHead, 0, Qt::AlignTop);

    DropDownDarkLabel *armourDDL = new DropDownDarkLabel("none", 250, 45, this);
    for (int i = 0; i < (int)armours.size(); i++)
    {
        armourDDL->AddNode(armours[i]->GetName());
    }
    lLayout->addWidget(armourDDL, 0, Qt::AlignTop);

    connect(armourDDL, &DropDownDarkLabel::selectionChanged, this, &CombatWidget::EquipArmour);

    //Setup Damage VRI Label

    QLabel *vriHead = new QLabel(this);
    vriHead->setText("Damage V/R/I");
    lLayout->addWidget(vriHead, 0, Qt::AlignTop);

    QString vriText = "Immunities: " + player->GetImmunityText() + "\nResistances: " + player->GetResistanceText() + "\nVulnarabilities: " + player->GetVulnarabilityText();

    DarkLabel *vriLabel = new DarkLabel(vriText, 375, 75, 16, this);
    lLayout->addWidget(vriLabel, 0, Qt::AlignTop);

    //Setup Initiative Bonus Widget

    DarkLabel *initLabel = new DarkLabel(((player->GetInitBonus() > 0) ? "+" : "") + QString::number(player->GetInitBonus()), "Initiative Bonus", 65, 65, 20, this);
    initLabel->SetColor("#2A2D44;");  initLabel->FlipDirection(); initLabel->ExpandTotalSize(400, 65); initLabel->SetLeftSpacer(150);
    rLayout->addWidget(initLabel, 0, Qt::AlignRight);

    //Setup Attack Number Widget

    DarkLabel *attackWidget = new DarkLabel("2", "Number of Attacks", 65, 45, 20, this);
    attackWidget->ExpandTotalSize(400, 45); attackWidget->SetColor("#2A2D44;"); attackWidget->FlipDirection(); attackWidget->SetLeftSpacer(150);
    rLayout->addWidget(attackWidget, 0, Qt::AlignRight);

    // Setup Weapon Widgets

    QLabel *weaponHead = new QLabel(this);
    weaponHead->setText("Weapons");
    rLayout->addWidget(weaponHead, 0, Qt::AlignRight);

    QScrollArea *weaponArea = new QScrollArea(this);
    weaponArea->setFixedSize(420, 350);
    weaponArea->setWidgetResizable(true);
    rLayout->addWidget(weaponArea, 0, Qt::AlignTop);
    QWidget *wpnWdg = new QWidget(this);
    weaponArea->setWidget(wpnWdg);
    QVBoxLayout *weaponLayout = new QVBoxLayout(wpnWdg);
    weaponLayout->setContentsMargins(0,0,0,0);
    weaponLayout->setAlignment(Qt::AlignTop);
    weaponArea->setStyleSheet("background-color: #A1B2CA; border: none;");

    for (int i = 0; i < (int)weapons.size(); i++)
    {
        weapons[i]->GetDie()->SetModifier(weapons[i]->GetMagicLevel() + (weapons[i]->HasWeaponProperty(dndobjs::finesse) ? std::max(player->GetStatModifier(dndobjs::dexterity), player->GetStatModifier(dndobjs::strength))
                                                                                           : player->GetStatModifier(dndobjs::strength)));
        int atkBonus = (weapons[i]->HasWeaponProperty(dndobjs::finesse) ? std::max(player->GetStatModifier(dndobjs::dexterity), player->GetStatModifier(dndobjs::strength))
                : player->GetStatModifier(dndobjs::strength)) + weapons[i]->GetMagicLevel();
        DropDownLabel *wpnDDl = new DropDownLabel(weapons[i], atkBonus, wpnWdg);
        weaponLayout->addWidget(wpnDDl, 0, Qt::AlignRight);
    }

    DropDownLabel *unarmedDDL = new DropDownLabel(player->GetUnarmed(), player->GetStatModifier(dndobjs::strength), this);
    weaponLayout->addWidget(unarmedDDL, 0, Qt::AlignRight);

    //Setup Action Widgets

    QLabel *actionLabel = new QLabel(this);
    actionLabel->setText("Actions"); actionLabel->setFixedWidth(100);
    actionLabel->setAlignment(Qt::AlignCenter);
    actionLabel->setStyleSheet("font: 20pt 'Roboto Regular';");
    ui->verticalLayout->addWidget(actionLabel, 0, Qt::AlignCenter);

    QHBoxLayout *act1 = new QHBoxLayout;
    ui->verticalLayout->addLayout(act1);
    QSpacerItem *vSpacer = new QSpacerItem(5, 15);
    ui->verticalLayout->addItem(vSpacer);
    QHBoxLayout *act2 = new QHBoxLayout;
    ui->verticalLayout->addLayout(act2);

    ActionWidget *attk = new ActionWidget("Attack", "Make an attack on a target with a weapon. Certain classes at certain levels can perform multiple attacks per action.");
    ActionWidget *casp = new ActionWidget("Cast a spell", "Cast a spell or cantrip that you know. The requirements and effects are outlined by the spell's description.");
    ActionWidget *dash = new ActionWidget("Dash", "Double your movement speed for this turn.");
    ActionWidget *dsng = new ActionWidget("Disengage", "Prevents enemys from making opportunity attacks against you until your next turn.");

    act1->addWidget(attk);
    act1->addWidget(casp);
    act1->addWidget(dash);
    act1->addWidget(dsng);

    ActionWidget *ddge = new ActionWidget("Dodge", "Impose disadvantages on attacks made against you until your next turn.");
    ActionWidget *help = new ActionWidget("Help", "Grant advantage to an ally's next ability check, as long as it is made before your next turn.");
    ActionWidget *hide = new ActionWidget("Hide", "Make a Stealth check to hide from opponents");
    ActionWidget *redy = new ActionWidget("Ready", "Delay another action to be used as a reaction to another creatures turn, before your next turn");

    act2->addWidget(ddge);
    act2->addWidget(help);
    act2->addWidget(hide);
    act2->addWidget(redy);
}

void CombatWidget::EquipArmour(int index)
{
    index--;
    if (index == -1 || index > (int)armours.size() - 1)
    {
        equippedArmour = nullptr;
        ac = player->GetAC();
        acLabel->SetMainText(QString::number(ac));
        return;
    }

    equippedArmour = armours[index];
    switch (equippedArmour->GetType())
    {
    case (dndobjs::lightArmour):
        ac = equippedArmour->GetAC() + player->GetStatModifier(dndobjs::dexterity);
        break;
    case (dndobjs::medArmour):
        ac = equippedArmour->GetAC() + std::min((int)player->GetStatModifier(dndobjs::dexterity), 2);
        break;
    case (dndobjs::heavyArmour):
        ac = equippedArmour->GetAC();
        break;
    default:
        ac = equippedArmour->GetAC();
        break;
    }

    acLabel->SetMainText(QString::number(ac));
    return;
}

void CombatWidget::EquipWeapon(int index)
{
    if (index == -1 || index <= (int)armours.size())
    {
        equippedWeapon = nullptr;
        return;
    }

    equippedWeapon = weapons[index];
    return;
}

void CombatWidget::EquipShield(int index)
{
    if (index == -1 || index <= (int)armours.size())
    {
        equippedShield = nullptr;
        return;
    }

    equippedShield = shields[index];
    ac += equippedShield->GetACBonus();
    acLabel->SetMainText(QString::number(ac));
    return;
}

CombatWidget::~CombatWidget()
{
    delete ui;
}
