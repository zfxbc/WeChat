#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QFile>
#include <QDomDocument>
#include <QMessageBox>
#include <QPixmap>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

private slots:
    void on_loginBtn_clicked();
    void showWeChatWindows();

private:
    Ui::loginDialog *ui;

    MainWindow *WeChatWindow;
    QDomDocument mydoc;

};

#endif // LOGINDIALOG_H
