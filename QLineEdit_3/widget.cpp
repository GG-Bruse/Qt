#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textEdited(const QString &arg1) {
    (void)arg1;
    Compare();
}
void Widget::on_lineEdit_2_textEdited(const QString &arg1) {
    (void)arg1;
    Compare();
}

void Widget::Compare()
{
    const QString str1 = ui->lineEdit->text();
    const QString str2 = ui->lineEdit_2->text();
    if(str1.isEmpty() && str2.isEmpty())
        ui->label->setText("密码为空");
    else if(str1 == str2)
        ui->label->setText("两次输入密码相同");
    else
        ui->label->setText("两次输入密码不同");
}
