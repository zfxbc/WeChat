#include "logindialog.h"
#include "ui_logindialog.h"


/* 用户登录 */
loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("微信");
    ui->usrlineEdit->setFocus();  /* 输入焦点初始置于密码框 */

    ui->usrlineEdit->setPlaceholderText("请输入用户名");
    ui->pwdLineEdit->setPlaceholderText("请输入密码");

    QPixmap pixmap;
    pixmap.load("D:/Github_code/WeChat/WeChat/image/login.png");
    ui->loginLabel->setPixmap(pixmap);
}

loginDialog::~loginDialog()
{
    delete ui;
}
/* 登录按钮 */
void loginDialog::on_loginBtn_clicked()
{
    showWeChatWindows();      /* 用于验证聊天窗口 */
}

void loginDialog::showWeChatWindows()
{
    /* 创建XML文件对象 */
    QFile file("D:/Github_code/WeChat/WeChat/userlog.xml");

    /* 将XML对象赋给QDomDocument类型的QT文档句柄 */
    mydoc.setContent(&file);

    /* 获取XML文档的DOM根元素 */
    QDomElement root = mydoc.documentElement();

    if(root.hasChildNodes())
    {
        /* 获取根元素的所有子节点 */
        QDomNodeList userList = root.childNodes();

        /* 指示用户是否存在 */
        bool exist = false;
        for(int i = 0; i < userList.count(); i++)
        {
             /* 根据当前索引i获取用户节点元素 */
            QDomNode user = userList.at(i);
            /* 该用户的全部属性元素 */
            QDomNodeList record = user.childNodes();

            QString uname = record.at(0).toElement().text();
            QString pword = record.at(1).toElement().text();
            if(uname == ui->usrlineEdit->text())
            {
                exist = true;
                if(!(pword == ui->pwdLineEdit->text()))
                {
                    QMessageBox::warning(0,"提示","密码错误，请重新输入！");
                    ui->pwdLineEdit->clear();
                    ui->usrlineEdit->clear();
                }
            }
        }

        if(!exist)
        {
             QMessageBox::warning(0,"提示","此用户不存在,请重新输入！");
             ui->pwdLineEdit->clear();
             ui->usrlineEdit->clear();
             ui->usrlineEdit->setFocus();
             return;
        }

    /* 用户存在且验证通过 */
    WeChatWindow = new MainWindow(0);
    WeChatWindow->setWindowTitle(ui->usrlineEdit->text());  //显示聊天窗口
    WeChatWindow->show();
    }
}
