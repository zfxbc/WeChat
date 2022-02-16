#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginDialog logindlg;
    logindlg.show();

    return a.exec();
}
