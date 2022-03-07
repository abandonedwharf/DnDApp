#ifndef DROPDOWNDARKLABEL_H
#define DROPDOWNDARKLABEL_H

#include <QWidget>
#include "darklabel.h"
#include <QPropertyAnimation>

namespace Ui {
class DropDownDarkLabel;
}

class DropDownDarkLabel : public QWidget
{
    Q_OBJECT

signals:
    int selectionChanged(int val);

public:
    DropDownDarkLabel(QString headText, int w, int h, QWidget *parent = nullptr);
    DropDownDarkLabel(QString headText, QString labelText, int w, int h, QWidget *parent = nullptr);
    ~DropDownDarkLabel();
    void AddNode(QString newText);
    void AddNode(QString newText, QString newLabel);
    void SetSize(int width);

private:
    Ui::DropDownDarkLabel *ui;
    DarkLabel *headLabel;
    std::vector<DarkLabel*> nodes;
    QPropertyAnimation *minAnim, *maxAnim;
    bool dropped;
    ushort dlWidth, dlHeight;

    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // DROPDOWNDARKLABEL_H
