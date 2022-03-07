#include "characterwidget.h"
#include "ui_characterwidget.h"
#include <QGridLayout>
#include <QLabel>
#include "darklabel.h"
#include "dropdownlabel.h"
#include "dropdowndarklabel.h"
#include "dndobjects.h"
#include <QTextEdit>
#include <QComboBox>
#include <QScrollArea>

CharacterWidget::CharacterWidget(dndobjs::DDPlayerCharacter *pl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterWidget)
{
    ui->setupUi(this);
    player = pl;

    this->setStyleSheet("QLabel { color: #2A2D44; font: 20pt 'Roboto Regular'; }");

    //Setup layouts

    QVBoxLayout *lLayout = new QVBoxLayout();
    QVBoxLayout *rLayout = new QVBoxLayout();
    QSpacerItem *hSpace = new QSpacerItem(100, 10);
    ui->horizontalLayout->addLayout(lLayout);
    ui->horizontalLayout->addItem(hSpace);
    ui->horizontalLayout->addLayout(rLayout);

    //Alignment Label

    QLabel *alignHead = new QLabel(this);
    alignHead->setText("Alignment");
    lLayout->addWidget(alignHead);

    DarkLabel *alignLabel = new DarkLabel(player->GetAlignmentText(), 200, 40, 16, this);
    lLayout->addWidget(alignLabel, 0, Qt::AlignTop);

    //Setup Background Label

    QLabel *bckgrndHead = new QLabel(this);
    bckgrndHead->setText("Background");
    lLayout->addWidget(bckgrndHead, 0, Qt::AlignTop);

    DarkLabel *backgroundLabel = new DarkLabel("Drow Urchin", 200, 40, 16, this);
    lLayout->addWidget(backgroundLabel, 0, Qt::AlignTop);

    //Setup Size Label

    QLabel *sizeHead = new QLabel(this);
    sizeHead->setText("Creature Size");
    lLayout->addWidget(sizeHead, 0, Qt::AlignTop);

    DarkLabel *sizeLabel = new DarkLabel(player->GetSizeText(), 200, 40, 16, this);
    lLayout->addWidget(sizeLabel, 0, Qt::AlignTop);

    //Setup the Character Classes DropDown Widget

    QLabel *classHead = new QLabel(this);
    classHead->setText((player->GetClassCount() > 1) ? "Classes" : "Class");
    lLayout->addWidget(classHead, 0, Qt::AlignTop);

    for (int i = 0; i < player->GetClassCount(); i++)
    {
        DropDownLabel *clssLabel = new DropDownLabel(player->GetClass(i)->GetName() + ": " + player->GetClass(i)->GetSubClass()->GetName(), "tha class subclass Description (add those)", this);
        lLayout->addWidget(clssLabel, 0, Qt::AlignTop);
    }

    //Setup the Character Race DropDown Widget

    QLabel *raceHead = new QLabel(this);
    raceHead->setText("Race");
    lLayout->addWidget(raceHead, 0, Qt::AlignTop);

    DropDownLabel *raceLabel = new DropDownLabel(player->GetRace()->GetName() + ": " + player->GetRace()->GetSubRace()->GetName(), "tha Race Subrace Description (add this!!)", this);
    lLayout->addWidget(raceLabel, 0, Qt::AlignTop);

    //Setup Description

    QLabel *dscrpHead = new QLabel(this);
    dscrpHead->setText("Description");
    lLayout->addWidget(dscrpHead, 0, Qt::AlignTop);

    QTextEdit *description = new QTextEdit(this);
    description->setMinimumSize(400, 450);
    description->setStyleSheet("background-color: #2A2D44; color: #FFFFFF;");
    lLayout->addWidget(description, 0, Qt::AlignTop);

    //Setup Passive Perception

    DarkLabel *psvPerc = new DarkLabel(QString::number(player->GetPassivePerception()), "Passive Perception", 45, 45, 16, this);
    psvPerc->SetColor("#2A2D44;"); psvPerc->FlipDirection(); psvPerc->ExpandTotalSize(250, 45);
    rLayout->addWidget(psvPerc, 0, Qt::AlignRight);

    //Setup Speeds

    QLabel *speedHead = new QLabel(this);
    speedHead->setText("Speed"); speedHead->setFixedWidth(250);
    rLayout->addWidget(speedHead, 0, Qt::AlignRight);

    DropDownDarkLabel *speedDDDL = new DropDownDarkLabel(QString::number(player->GetSpeed(dndobjs::walking)) + " feet", dndobjs::SpeedText(dndobjs::walking), 75, 45, this);
    speedDDDL->AddNode(QString::number(player->GetSpeed(dndobjs::swimming)) + " feet", dndobjs::SpeedText(dndobjs::swimming));
    speedDDDL->AddNode(QString::number(player->GetSpeed(dndobjs::climbing)) + " feet", dndobjs::SpeedText(dndobjs::climbing));
    speedDDDL->AddNode(QString::number(player->GetSpeed(dndobjs::flying)) + " feet", dndobjs::SpeedText(dndobjs::flying));
    speedDDDL->SetSize(400);
    rLayout->addWidget(speedDDDL, 0, Qt::AlignRight);

    //Setup Sight

    QLabel *sightHead = new QLabel(this);
    sightHead->setText("Sight"); sightHead->setFixedWidth(250);
    rLayout->addWidget(sightHead, 0, Qt::AlignRight);

    DropDownDarkLabel *sightDDDL = new DropDownDarkLabel(QString::number(player->GetSight(dndobjs::darkvision)) + " feet", dndobjs::SightText(dndobjs::darkvision), 75, 45, this);
    sightDDDL->AddNode(QString::number(player->GetSight(dndobjs::blindsight)) + " feet", dndobjs::SightText(dndobjs::blindsight));
    sightDDDL->AddNode(QString::number(player->GetSight(dndobjs::truesight)) + " feet", dndobjs::SightText(dndobjs::truesight));
    sightDDDL->SetSize(400);
    rLayout->addWidget(sightDDDL, 0, Qt::AlignRight);

    //Setup Languages Widget

    QLabel *languagesHead = new QLabel(this);
    languagesHead->setText("Languages"); languagesHead->setFixedWidth(250);
    rLayout->addWidget(languagesHead, 0, Qt::AlignRight);

    DarkLabel *languagesLabel = new DarkLabel(player->GetLanguagesText(), 250, 60, 16, this);
    languagesLabel->ExpandTotalSize(250, 60);
    rLayout->addWidget(languagesLabel, 0, Qt::AlignRight);

    //Setup Special Properties

    QLabel *specialPropertiesHead = new QLabel(this);
    specialPropertiesHead->setText("Special Properties");
    specialPropertiesHead->setFixedWidth(400);
    rLayout->addWidget(specialPropertiesHead, 0, Qt::AlignRight);

    QScrollArea *specialPropertiesArea = new QScrollArea(this);
    specialPropertiesArea->setMinimumSize(400, 500);
    specialPropertiesArea->setWidgetResizable(true);
    rLayout->addWidget(specialPropertiesArea, 0, Qt::AlignTop);
    QWidget *spWdg = new QWidget(this);
    specialPropertiesArea->setWidget(spWdg);
    QVBoxLayout *specialPropertiesLayout = new QVBoxLayout(spWdg);
    specialPropertiesLayout->setContentsMargins(0,0,0,0);
    specialPropertiesArea->setStyleSheet("background-color: #A1B2CA; border: none;");

    for (int i = 0; i < player->GetSpecialPropertyCount(); i++)
    {
        DropDownLabel *spDDL = new DropDownLabel(player->GetSpecialProperty(i)->GetName(), player->GetSpecialProperty(i)->GetDescription(), spWdg);
        specialPropertiesLayout->addWidget(spDDL);
    }

    for (int i = 0; i < player->GetClassCount(); i++)
    {
        for (int o = 0; o < player->GetClass(i)->GetLevelFeatureCount(); o++)
        {
            if (player->GetClass(i)->GetLevelFeature(o)->level <= player->GetClass(i)->GetLevel())
            {
                DropDownLabel *clDDL = new DropDownLabel(player->GetClass(i)->GetLevelFeature(o)->feature->GetName(), player->GetClass(i)->GetLevelFeature(o)->feature->GetDescription(), this);
                specialPropertiesLayout->addWidget(clDDL, 0, Qt::AlignRight);
            }
        }
    }

    for (int i = 0; i < player->GetRace()->GetSpecialPropertyCount(); i++)
    {
        DropDownLabel *rcDDL = new DropDownLabel(player->GetRace()->GetSpecialProperty(i)->GetName(), player->GetRace()->GetSpecialProperty(i)->GetDescription(), this);
        specialPropertiesLayout->addWidget(rcDDL, 0, Qt::AlignRight);
    }
}

CharacterWidget::~CharacterWidget()
{
    delete ui;
}
