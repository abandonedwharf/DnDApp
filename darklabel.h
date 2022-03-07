#ifndef DARKLABEL_H
#define DARKLABEL_H

#include <QWidget>

namespace Ui {
class DarkLabel;
}

class DarkLabel : public QWidget
{
    Q_OBJECT

public:
    DarkLabel(QString mainText, int width, int height, int fontSize, QWidget *parent = nullptr);
    DarkLabel(QString mainText, QString labelText, int width, int height, int fontSize, QWidget *parent = nullptr);
    DarkLabel(QString mainText, QString labelText, int width, int height, int fontSize, bool prof, QWidget *parent = nullptr);
    ~DarkLabel();
    void SetColor(QString col);
    void FlipDirection();
    void ExpandTotalSize(int width, int height);
    QString GetMainText();
    QString GetLabelText();
    void SetMainText(QString text);
    void SetLabelText(QString text);
    void SetLeftSpacer(int spcWidth);
private:
    Ui::DarkLabel *ui;
};

#endif // DARKLABEL_H
