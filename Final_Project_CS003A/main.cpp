/**************************************************************************
 *  Author          : Gurpal Kundi
 *  Assignment      : 11
 *  Class           : CS003A
 *  Section         : MTWR: 7:30a-9:30a
 *  Due Date        : 12/07/2017
 *************************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
