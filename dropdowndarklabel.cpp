#include "dropdowndarklabel.h"
#include "ui_dropdowndarklabel.h"
#include <QMouseEvent>
#include <QLayout>
#include <algorithm>
#include <QCursor>

DropDownDarkLabel::DropDownDarkLabel(QString headText, int w, int h, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDownDarkLabel)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel { background-color: #A1B2CA; font: 16pt 'Roboto Regular'; }");

    this->dlWidth = w; this->dlHeight = h;

    this->setMaximumSize(dlWidth, dlHeight); this->setMinimumSize(dlWidth, dlHeight);

    QCursor *cursor = new QCursor();
    cursor->setShape(Qt::CursorShape::PointingHandCursor);

    nodes.push_back(new DarkLabel(headText, dlWidth, dlHeight, 16, this));
    nodes[0]->SetColor("#2A2D44"); nodes[0]->setCursor(*cursor);

    headLabel = nodes[0];
    headLabel->installEventFilter(this);
    headLabel->show();

    dropped = false;
}

DropDownDarkLabel::DropDownDarkLabel(QString headText, QString labelText, int w, int h, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDownDarkLabel)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel { background-color: #A1B2CA; font: 16pt 'Roboto Regular'; }");

    this->dlWidth = w; this->dlHeight = h;

    QCursor *cursor = new QCursor();
    cursor->setShape(Qt::CursorShape::PointingHandCursor);

    nodes.push_back(new DarkLabel(headText, labelText, dlWidth, dlHeight, 16, this));
    nodes[0]->ExpandTotalSize(dlWidth + 175, dlHeight); nodes[0]->FlipDirection(); nodes[0]->SetColor("#2A2D44"); nodes[0]->setCursor(*cursor);

    headLabel = nodes[0];
    headLabel->installEventFilter(this);
    headLabel->show();

    dropped = false;
}

DropDownDarkLabel::~DropDownDarkLabel()
{
    delete ui;
}

void DropDownDarkLabel::AddNode(QString newText)
{
    QCursor *cursor = new QCursor();
    cursor->setShape(Qt::CursorShape::PointingHandCursor);
    nodes.push_back(new DarkLabel(newText, dlWidth, dlHeight, 16, this));
    nodes[nodes.size() - 1]->SetColor("#2A2D44"); nodes[nodes.size() - 1]->setCursor(*cursor);
    nodes[nodes.size() - 1]->installEventFilter(this);
    nodes[nodes.size() - 1]->setGeometry(nodes[0]->geometry());

    headLabel->raise();
}

void DropDownDarkLabel::AddNode(QString newText, QString newLabel)
{
    QCursor *cursor = new QCursor();
    cursor->setShape(Qt::CursorShape::PointingHandCursor);
    nodes.push_back(new DarkLabel(newText, newLabel, dlWidth, dlHeight, 16, this));
    nodes[nodes.size() - 1]->ExpandTotalSize(dlWidth + 175, dlHeight); nodes[nodes.size() - 1]->FlipDirection(); nodes[nodes.size() - 1]->SetColor("#2A2D44"); nodes[nodes.size() - 1]->setCursor(*cursor);
    nodes[nodes.size() - 1]->installEventFilter(this);
    nodes[nodes.size() - 1]->setGeometry(nodes[0]->geometry());

    headLabel->raise();
}

int GetIndex(std::vector<DarkLabel*> v, DarkLabel *obj)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] == obj)
        {
            return i;
        }
    }
    return -1;
}

void DropDownDarkLabel::SetSize(int width)
{
    int widthShift = width - this->width();
    this->setFixedWidth(width);
    for (DarkLabel *node : nodes)
    {
        node->setGeometry(widthShift, 0, node->width(), node->height());
    }
}

bool DropDownDarkLabel::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == headLabel && !dropped)
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
                DarkLabel *temp = dynamic_cast<DarkLabel*>(obj);
                if (temp != headLabel)
                {
                    headLabel = temp;
                    headLabel->raise();
                }

                minAnim = new QPropertyAnimation(this, "minimumHeight");
                minAnim->setStartValue(this->height());
                minAnim->setEndValue(45);

                maxAnim = new QPropertyAnimation(this, "maximumHeight");
                maxAnim->setStartValue(this->height());
                maxAnim->setEndValue(45);

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

                emit selectionChanged(GetIndex(nodes, temp));
            }
        }
    }
    return false;
}
