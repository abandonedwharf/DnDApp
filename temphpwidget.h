#ifndef TEMPHPWIDGET_H
#define TEMPHPWIDGET_H

#include <QWidget>

namespace Ui {
class TempHPWidget;
}

class TempHPWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TempHPWidget(QWidget *parent = nullptr);
    ~TempHPWidget();

private:
    Ui::TempHPWidget *ui;
};

#endif // TEMPHPWIDGET_H
