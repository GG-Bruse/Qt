#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化第一个输入框
    ui->lineEditName->setPlaceholderText("请输入姓名");
    ui->lineEditName->setClearButtonEnabled(true);
    //初始化第二个输入框
    ui->lineEditPassword->setPlaceholderText("请输入密码");
    ui->lineEditPassword->setClearButtonEnabled(true);
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    //初始化第三个输入框
    ui->lineEditPhone->setPlaceholderText("请输入电话号码");
    ui->lineEditPhone->setClearButtonEnabled(true);
    //验证手机号必须是11位数字,并且按照"334"的格式输入
    ui->lineEditPhone->setInputMask("000-0000-0000");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString gender = ui->radioButtonMale->isChecked()? "男" : "女";
    qDebug() << "姓名:" << ui->lineEditName->text()
             << "密码:" << ui->lineEditPassword->text()
             << "性别:" << gender
             << "电话:" << ui->lineEditPhone->text();
}
