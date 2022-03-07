#include <QApplication>
#include <QFontDatabase>
#include "introwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/font/resources/fonts/Roboto-Regular.ttf");
    QFontDatabase::addApplicationFont(":/font/resources/fonts/Roboto-BoldItalic.ttf");

    a.setStyleSheet(
                "QMainWindow { background-color: #A1B2CA; }"
                "QLabel { color: #FFFFFF; font: 16pt 'Roboto Regular'; }"
                "QWidget#LeftWindow { background-color: #5F6983; }"
                "QWidget#NavBar { background-color: #5F6983; }"
                );

    IntroWindow i;
    i.show();
    return a.exec();
}
