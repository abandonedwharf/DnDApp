#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deathsaves.h"
#include "statdisplay.h"
#include "temphpwidget.h"
#include <QLabel>
#include <QSpinBox>
#include <QScreen>
#include <QLineEdit>
#include <QSpacerItem>
#include <QMouseEvent>

using namespace dndobjs;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ! ! ! TEMP CHARACTER THAT I HAVE MADE
    //AT SOME POINT JUST MAKE JAVERT, THE MULTICLASS DEMON
    DDSubClass *oathOfVengance = new DDSubClass ("Oath of Vengance");

    std::vector<armourType> paladinArmour = std::vector<armourType> { lightArmour, medArmour, heavyArmour };
    stats savingThrows[2] = { wisdom, charisma };
    skills potential[6] = { athletics, insight, intimidation, medicine, persuasion, religion };
    DDClass *paladin = new DDClass("Paladin", dice::d10,  paladinArmour, true, savingThrows, potential, oathOfVengance, charisma);
    DDPlayerClass* pladin = new DDPlayerClass(paladin, 6);
    DDSubClass *favoursedsoul = new DDSubClass("Favoured Soul");
    DDClass *sorceror = new DDClass("Sorceror", dice::d6,  paladinArmour, true, savingThrows, potential, favoursedsoul, charisma);
    DDPlayerClass *srceer = new DDPlayerClass(sorceror, 4);
    std::vector<DDPlayerClass*> cls = {pladin, srceer};

    AbilityScoreImprovement *sr = new AbilityScoreImprovement; AbilityScoreImprovement *r = new AbilityScoreImprovement;
    r->stat = dexterity; r->improveAmount = 2; sr->stat = charisma; sr->improveAmount = 1;
    DDSpecialProperty *sp = new DDSpecialProperty("Fey Ancestry", "you do not need to sleep. you simply, meditate. also no charming lmao", normalProperty);
    DDSubRace *drow = new DDSubRace ("Drow", sr);
    DDRace *elf = new DDRace ("Elf", r, drow, medium, fey);
    elf->AddSpecialProperty(sp);

    ushort st[6] = { 15, 18, 10, 12, 16, 18 };
    std::vector<skills> sk = { intimidation, perception, religion, sleightOfHand, stealth };
    std::vector<stats> sv = {constitution, charisma};
    std::vector<DDSpecialProperty*> spec;
    std::vector<DDSpell*> spll;
    std::vector<language> lng = { commonSpeech, undercommonSpeech, elvishSpeech, abyssalSpeech };

    DDSpecialProperty *ironBreakerProperty = new DDSpecialProperty("Weapon Breaker", "On a critical attack, this weapon can break your opponents weapon, as long as it isnt magical. This is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is colThis is col", normalProperty);

    DDWeapon *ironBreaker = new DDWeapon("IronBreaker", "A longsword with a serrated edge", longsword, 1, 1, uncommon);
    ironBreaker->AddSpecialProperty(ironBreakerProperty);
    DDWeapon *spiderScythe = new DDWeapon("Spider Scythe", "A scythe with webbed decorations", scythe, 1, 1, uncommon);
    spiderScythe->AddSpecialProperty(new DDSpecialProperty ("Web", "Upon successfully attacking, you can cast web", specialpropertyTypes::spellProperty));

    std::vector<skills> d { stealth };
    DDArmour *chainMail = new DDArmour("Chain Mail", "Its Chain mail", common, medium, 50, 16, d, std::vector<skills>(), heavyArmour);

    playerCharacter = new DDPlayerCharacter("Javert", ln, 60, st, sk, sv, spec, spll, lng, 213, elf, cls, 315);
    playerCharacter->AddItem(ironBreaker); playerCharacter->AddItem(chainMail);
    playerCharacter->AddItem(new DDWeapon("Dagger", "dagger", dagger)); playerCharacter->AddItem(spiderScythe);
    playerCharacter->AddItem(new DDWeapon("Light Crossbow", "crossbow but Light", crossbowLight));

    DDSpell *fireball = new DDAOEAttackSpell("Fireball", "You throw a ball of fire and do a teamkill", "1 Action", "Instantaneous", evocation, 3, 60, new DDDamageDice(d6, 4, 0, fire), 15, "sphere");
    DDSpell *divineSmite = new DDAttackSpell("Branding Smite", "You can do a Smite", "1 bonus action", "Instantaneous", evocation, 2, 0, new DDDamageDice(d6, 2, 0, radiant));
    DDSpell *cureWounds = new DDHealingSpell("Cure Wounds", "wow you helped a friend", "1 action", "Instantaneous", evocation, 2, 0, new DDDice(d8, 1, playerCharacter->GetStatModifier(charisma)));
    fireball->SetMagicComponents(true, true, true); fireball->AddClass(sorceror);
    divineSmite->SetMagicComponents(true, false, false); divineSmite->AddClass(paladin);
    cureWounds->SetMagicComponents(true, false, false); cureWounds->AddClass(paladin);
    playerCharacter->AddSpell(fireball); playerCharacter->AddSpell(divineSmite); playerCharacter->AddSpell(cureWounds);

    // TEMP STUFF ENDS (KINDA) (FEEL FREE TO DELETE EVERYTHING) (I AM TALKING TO FUTURE ME)

    // * * * * Left Window : Left Side * * * *

    //Character name label

    DarkLabel *nameLabel = new DarkLabel(playerCharacter->GetName(), 135, 70, 16, this);
    ui->LLLayout->addWidget(nameLabel, 0);

    //Race label

    DarkLabel *raceLabel = new DarkLabel(playerCharacter->GetRace()->GetName() + "(" + playerCharacter->GetRace()->GetSubRace()->GetName() + ")", 135, 45, 12, this);
    ui->LLLayout->addWidget(raceLabel, 1);

    //Class label

    QString classText;
    for (int i = 0; i < playerCharacter->GetClassCount(); i++)
    {
        classText += playerCharacter->GetClass(i)->GetName() + " (" + QString::number(playerCharacter->GetClass(i)->GetLevel()) + ")\n";
    }
    DarkLabel *classLabel = new DarkLabel(classText, 135, 65, 12, this);
    ui->LLLayout->addWidget(classLabel, 2);

    //Death Saving Throw widget

    DeathSaves *ds = new DeathSaves(this);
    ui->LLLayout->addWidget(ds, 3);

    //Stat display widgets

    StatDisplay *statDisplays[6];

    for (int i = 0; i < 6; i++)
    {
        statDisplays[i] = new StatDisplay(StatsTextShort(i), playerCharacter->GetStat(i), this);
        ui->LLLayout->addWidget(statDisplays[i], 4 + i);
    }

    // * * * * Left Window : Right Side * * * *

    //HP Label

    DarkLabel *hpWidget = new DarkLabel(QString::number(playerCharacter->GetHP()) + "/" + QString::number(playerCharacter->GetMaxHP()), "HP", 105, 70, 20);
    ui->LRLayout->addWidget(hpWidget, 0);

    //Temp HP Spin Box

    TempHPWidget *tmpHP = new TempHPWidget(this);
    ui->LRLayout->addWidget(tmpHP, 1);

    //Hit Die Label

    hdWidget = new HitDie (playerCharacter->GetHitDice(), this);
    ui->LRLayout->addWidget(hdWidget, 2);

    //Saving Throws

    QLabel *svThrowLabel = new QLabel (this);
    svThrowLabel->setText("Saving Throws:");
    ui->LRLayout->addWidget(svThrowLabel, 3);

    DarkLabel *svThrows[6];

    for (int i = 0; i < 6; i++)
    {
        svThrows[i] = new DarkLabel((playerCharacter->GetSavingThrow(i) > 0 ? "+" : "") + QString::number(playerCharacter->GetSavingThrow(i)), StatsText(i), 25, 25, 10, playerCharacter->IsProficient((stats) i));
        ui->LRLayout->addWidget(svThrows[i], 4 + i);
    }

    //Skills

    QLabel *skillLabel = new QLabel (this);
    skillLabel->setText("Skills:");
    ui->LRLayout->addWidget(skillLabel, 11);

    QLineEdit *skillSearch =  new QLineEdit(this);
    skillSearch->setStyleSheet("background-color: #2A2D44; font: 10pt 'Roboto Regular'; color: #FFFFFF; qproperty-frame: false; padding-left: 5px;");
    skillSearch->setMinimumSize(130, 20); skillSearch->setMaximumSize(130, 20);
    skillSearch->setPlaceholderText("Search");
    ui->LRLayout->addWidget(skillSearch, 12);

    connect(skillSearch, &QLineEdit::textChanged, this, &MainWindow::SearchForSkill);

    for (int  i = 0; i < 18; i++)
    {
        skillWidgets[i] = new DarkLabel((playerCharacter->GetSkill(i) > 0 ? "+" : "") + QString::number(playerCharacter->GetSkill(i)), SkillsText(i), 25, 25, 10, playerCharacter->IsProficient((skills)i));
        ui->LRLayout->addWidget(skillWidgets[i] , 13 + i);
    }

    // * * * * Nav Window * * * *

    ui->NavBar->setStyleSheet(
                "QPushButton { background-color: #A1B2CA; border: none; font: 16pt 'Roboto Regular'; color: #2A2D44; }"
                "QPushButton::hover { background-color: #B9CBE5; }"
                "QPushButton#ExitButton { font: 30pt 'Roboto Regular'; background-color: #5F6983; color: #A1B2CA; }"
                "QPushButton#ExitButton::hover { background-color: #2A2D44; }"
                "QPushButton#ExitButton::clicked { background-color: #A1B2CA; }"
                "QPushButton#MinimiseButton { font: 30pt 'Roboto Regular'; background-color: #5F6983; color: #A1B2CA; }"
                "QPushButton#MinimiseButton::hover { background-color: #2A2D44; }"
                "QPushButton#MinimiseButton::clicked { background-color: #A1B2CA; }"
                );

    ui->CharacterButton->setGeometry(ui->CharacterButton->x(), 10, 200, 55);
    selectedNavButton = ui->CharacterButton;

    ui->NavBar->installEventFilter(this);


    // * * * * Main Widget * * * *

    //Initialise Tabs

    characterWidget = new CharacterWidget(playerCharacter, this);
    combatWidget = new CombatWidget(playerCharacter, this);
    spellsWidget = new SpellsWidget(playerCharacter, this);
    inventoryWidget = new InventoryWidget(playerCharacter, this);
    ui->RightLayout->addWidget(characterWidget, Qt::AlignTop);
    ui->RightLayout->addWidget(combatWidget, Qt::AlignTop);
    ui->RightLayout->addWidget(spellsWidget, Qt::AlignTop);
    ui->RightLayout->addWidget(inventoryWidget, Qt::AlignTop);

    mainWidget = characterWidget;

    //Hide other windows

    combatWidget->hide();
    spellsWidget->hide();
    inventoryWidget->hide();

    //remove window frame

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    //move window to centre of screen

    move(screen()->geometry().center() - frameGeometry().center());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AnimateButtons (QPushButton *clicked)
{
    selectedAnim = new QPropertyAnimation(clicked, "geometry");
    selectedAnim->setDuration(50);
    selectedAnim->setStartValue(clicked->geometry());
    selectedAnim->setEndValue(QRect(clicked->x(), 10, 200, 55));

    deselectedAnim = new QPropertyAnimation(selectedNavButton, "geometry");
    deselectedAnim->setDuration(50);
    deselectedAnim->setKeyValueAt(0, selectedNavButton->geometry());
    deselectedAnim->setKeyValueAt(0.5, QRect(selectedNavButton->x(), 30, 200, 38));
    deselectedAnim->setKeyValueAt(0.8, QRect(selectedNavButton->x(), 35, 200, 30));
    deselectedAnim->setKeyValueAt(1, QRect(selectedNavButton->x(), 35, 200, 25));

    selectedAnim->start(QAbstractAnimation::DeleteWhenStopped);
    deselectedAnim->start(QAbstractAnimation::DeleteWhenStopped);

    selectedNavButton = clicked;
}

void MainWindow::SearchForSkill(QString search)
{
    for (int i = 0; i < 18; i++)
    {
        if (SkillsText((skills) i).contains(search))
        {
            skillWidgets[i]->setStyleSheet("color: #FFFFFF;");
        }
        else
        {
            skillWidgets[i]->setStyleSheet("color: #2A2D44;");
        }
    }
}

void MainWindow::on_MinimiseButton_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_ExitButton_clicked()
{
    this->close();
}

void MainWindow::on_CharacterButton_clicked()
{
    if (selectedNavButton != ui->CharacterButton)
    {
        AnimateButtons(ui->CharacterButton);
    }

    mainWidget->hide();
    mainWidget = characterWidget;
    mainWidget->show();
}

void MainWindow::on_CombatButton_clicked()
{
    if (selectedNavButton != ui->CombatButton)
    {
        AnimateButtons(ui->CombatButton);
    }

    mainWidget->hide();
    mainWidget = combatWidget;
    mainWidget->show();
}

void MainWindow::on_SpellsButton_clicked()
{
    if (selectedNavButton != ui->SpellsButton)
    {
        AnimateButtons(ui->SpellsButton);
    }

    mainWidget->hide();
    mainWidget = spellsWidget;
    mainWidget->show();
}

void MainWindow::on_InventoryButton_clicked()
{
    if (selectedNavButton != ui->InventoryButton)
    {
        AnimateButtons(ui->InventoryButton);
    }

    mainWidget->hide();
    mainWidget = inventoryWidget;
    mainWidget->show();
}

//Event Filter

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == (QObject*)ui->NavBar)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton)
            {
                startPos = (mouseEvent->globalPosition() - frameGeometry().topLeft()).toPoint();
                return false;
            }
        }
        else if (event->type() == QEvent::MouseMove)
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
            if (mouseEvent->buttons() & Qt::LeftButton)
            {
                move(mouseEvent->globalPosition().toPoint() - startPos);
                return false;
            }
        }
    }
    return false;
}

