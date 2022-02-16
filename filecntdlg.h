#ifndef FILECNTDLG_H
#define FILECNTDLG_H

#include <QDialog>

namespace Ui {
class FileCntDlg;
}

class FileCntDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FileCntDlg(QWidget *parent = 0);
    ~FileCntDlg();

private:
    Ui::FileCntDlg *ui;
};

#endif // FILECNTDLG_H
