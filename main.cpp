#include "mainregular.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainRegular w;
    w.show();
    return a.exec();
}
