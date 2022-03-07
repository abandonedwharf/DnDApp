#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QPropertyAnimation>
#include "darklabel.h"
#include "dndobjects.h"
#include "hitdie.h"
#include "characterwidget.h"
#include "combatwidget.h"
#include "spellswidget.h"
#include "inventorywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void SearchForSkill(QString search);

    void AnimateButtons(QPushButton *clicked);

    void on_MinimiseButton_clicked();

    void on_ExitButton_clicked();

    void on_CombatButton_clicked();

    void on_CharacterButton_clicked();

    void on_SpellsButton_clicked();

    void on_InventoryButton_clicked();

private:
    Ui::MainWindow *ui;
    DarkLabel *skillWidgets[18];
    HitDie *hdWidget;
    QPushButton *selectedNavButton;
    QPoint startPos;
    QPropertyAnimation *selectedAnim, *deselectedAnim;
    QWidget *mainWidget;
    dndobjs::DDPlayerCharacter *playerCharacter;

    CharacterWidget *characterWidget;
    CombatWidget *combatWidget;
    SpellsWidget *spellsWidget;
    InventoryWidget *inventoryWidget;

    bool eventFilter (QObject *obj, QEvent *event);
};
#endif // MAINWINDOW_H
