#ifndef STATDISPLAY_H
#define STATDISPLAY_H

#include <QWidget>

namespace Ui {
class StatDisplay;
}

class StatDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit StatDisplay(QString statName, ushort stat, QWidget *parent = nullptr);
    ~StatDisplay();

private:
    Ui::StatDisplay *ui;
};

#endif // STATDISPLAY_H
