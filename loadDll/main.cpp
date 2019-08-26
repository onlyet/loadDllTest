#include "loadDll.h"
#include <QWidget>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadDll w;
    w.show();
    return a.exec();
}
