#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置默认选中该按钮
    ui->radioButtonMale->setChecked(true);
    ui->label->setText("你选择的性别为:男");

    //禁用other选项
//    ui->radioButtonOther->setCheckable(false);
    //禁用other选项
    ui->radioButtonOther->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_radioButtonMale_clicked()
{
    ui->label->setText("你选择的性别为:男");
}

void Widget::on_radioButtonFemale_clicked()
{
    ui->label->setText("你选择的性别为:女");
}

void Widget::on_radioButtonOther_clicked()
{
    ui->label->setText("你选择的性别为:其他");
}
