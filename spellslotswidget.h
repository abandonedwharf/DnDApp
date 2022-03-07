#ifndef SPELLSLOTSWIDGET_H
#define SPELLSLOTSWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class SpellSlotsWidget;
}

class SpellSlotsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpellSlotsWidget(int count, QString labelText, QWidget *parent = nullptr);
    ~SpellSlotsWidget();
    void AddLayer(int count, QString labelText);

private:
    Ui::SpellSlotsWidget *ui;
    std::vector<QWidget*> nodes;
    QPropertyAnimation *minAnim, *maxAnim;
    bool dropped;
    QWidget *headWidget;

    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // SPELLSLOTSWIDGET_H
