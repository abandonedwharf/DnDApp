#ifndef DEATHSAVES_H
#define DEATHSAVES_H

#include <QWidget>

namespace Ui {
class DeathSaves;
}

class DeathSaves : public QWidget
{
    Q_OBJECT

public:
    explicit DeathSaves(QWidget *parent = nullptr);
    ~DeathSaves();

private:
    Ui::DeathSaves *ui;
};

#endif // DEATHSAVES_H
