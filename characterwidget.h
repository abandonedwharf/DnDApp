#ifndef CHARACTERWIDGET_H
#define CHARACTERWIDGET_H

#include <QWidget>
#include <dndobjects.h>

namespace Ui {
class CharacterWidget;
}

class CharacterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterWidget(dndobjs::DDPlayerCharacter *pl, QWidget *parent = nullptr);
    ~CharacterWidget();

private:
    Ui::CharacterWidget *ui;
    dndobjs::DDPlayerCharacter *player;
};

#endif // CHARACTERWIDGET_H
