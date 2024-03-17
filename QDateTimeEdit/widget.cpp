#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //获取到两个时间框的时间日期
    QDateTime timeOld = ui->dateTimeEdit->dateTime();
    QDateTime timeNew = ui->dateTimeEdit_2->dateTime();
    //计算日期差值
    int days = (timeOld.secsTo(timeNew) / 3600) / 24;
    int hours = (timeOld.secsTo(timeNew) / 3600) % 24;
    //设置label的内容
    QString text = "计算结果为:" + QString::number(days) + "天 零 " + QString::number(hours) + "小时";
    ui->label->setText(text);
}
