#include <QApplication>
#include "leCanon.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    leCanon b;
    b.show();

    return a.exec();
}
