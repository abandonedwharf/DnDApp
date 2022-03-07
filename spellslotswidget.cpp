#include "spellslotswidget.h"
#include "ui_spellslotswidget.h"
#include <QMouseEvent>
#include <QLayout>
#include <QLabel>
#include <QCheckBox>

SpellSlotsWidget::SpellSlotsWidget(int count, QString labelText, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpellSlotsWidget)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel { font: 16pt 'Roboto Regular'; }"
                        "QWidget { background-color: #A1B2CA; }"
                        "QCheckBox::indicator { background-color: #5F6983; width: 25px; height: 25px; }"
                        "QCheckBox::indicator::checked { background-color: #2A2D44; }");

    headWidget = new QWidget(this);
    headWidget->setFixedSize(75 + (count * 50), 50);
    this->setFixedWidth(headWidget->width());
    QHBoxLayout *slotLayout = new QHBoxLayout(headWidget);
    headWidget->setLayout(slotLayout);
    headWidget->layout()->setAlignment(Qt::AlignRight);
    nodes.push_back(headWidget);

    QLabel *label = new QLabel(this);
    label->setText(labelText);
    slotLayout->addWidget(label);

    for (int i = 0; i < count; i++)
    {
        slotLayout->addWidget(new QCheckBox(headWidget));
    }

    dropped = false;

    headWidget->installEventFilter(this);
}

SpellSlotsWidget::~SpellSlotsWidget()
{
    delete ui;
}

void SpellSlotsWidget::AddLayer(int count, QString labelText)
{
    QWidget *newLayer = new QWidget(this);
    newLayer->setGeometry(0, 0, this->width(), 50);
    QHBoxLayout *slotLayout = new QHBoxLayout(headWidget);
    newLayer->setLayout(slotLayout);
    newLayer->layout()->setAlignment(Qt::AlignRight);

    QLabel *label = new QLabel(this);
    label->setText(labelText);
    slotLayout->addWidget(label);

    for (int i = 0; i < count; i++)
    {
        slotLayout->addWidget(new QCheckBox(headWidget));
    }

    newLayer->installEventFilter(this);

    nodes.push_back(newLayer);

    headWidget->raise();
}

bool SpellSlotsWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == headWidget && !dropped)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mE = dynamic_cast<QMouseEvent*>(event);
            if (mE->button() == Qt::LeftButton)
            {
                minAnim = new QPropertyAnimation(this, "minimumHeight");
                minAnim->setStartValue(this->height());
                minAnim->setEndValue(50 * nodes.size());

                maxAnim = new QPropertyAnimation(this, "maximumHeight");
                maxAnim->setStartValue(this->height());
                maxAnim->setEndValue(50 * nodes.size());

                for (int i = 0; i < (int) nodes.size(); i++)
                {
                    QPropertyAnimation *anim = new QPropertyAnimation(nodes[i], "geometry");
                    anim->setStartValue(nodes[i]->geometry());
                    anim->setEndValue(QRect(nodes[i]->x(), 50 * i, nodes[i]->width(), nodes[i]->height()));
                    anim->start(QAbstractAnimation::DeleteWhenStopped);
                }

                minAnim->start(QAbstractAnimation::DeleteWhenStopped);
                maxAnim->start(QAbstractAnimation::DeleteWhenStopped);
                dropped = true;
            }
        }
    }
    else if (std::count(nodes.begin(), nodes.end(), obj) && dropped)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mE = dynamic_cast<QMouseEvent*>(event);
            if (mE->button() == Qt::LeftButton)
            {
                QWidget *temp = dynamic_cast<QWidget*>(obj);
                if (temp != headWidget)
                {
                    headWidget = temp;
                    headWidget->raise();
                }

                minAnim = new QPropertyAnimation(this, "minimumHeight");
                minAnim->setStartValue(this->height());
                minAnim->setEndValue(50);

                maxAnim = new QPropertyAnimation(this, "maximumHeight");
                maxAnim->setStartValue(this->height());
                maxAnim->setEndValue(50);

                for (int i = 0; i < (int) nodes.size(); i++)
                {
                    QPropertyAnimation *anim = new QPropertyAnimation(nodes[i], "geometry");
                    anim->setStartValue(nodes[i]->geometry());
                    anim->setEndValue(QRect(nodes[i]->x(), 0, nodes[i]->width(), nodes[i]->height()));
                    anim->start(QAbstractAnimation::DeleteWhenStopped);
                }

                minAnim->start(QAbstractAnimation::DeleteWhenStopped);
                maxAnim->start(QAbstractAnimation::DeleteWhenStopped);
                dropped = false;
            }
        }
    }
    return false;
}

