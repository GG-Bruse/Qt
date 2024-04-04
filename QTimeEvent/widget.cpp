#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器
    timerId1 = startTimer(1000);
    timerId2 = startTimer(2000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timerId1) {
        static int count1 = 1;
        ui->label->setText(QString::number(count1++));
    }
    if(event->timerId() == timerId2) {
        static int count2 = 1;
        ui->label_2->setText(QString::number(count2++));
    }
}

