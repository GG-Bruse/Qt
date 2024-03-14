#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建QTimer实例
    timer = new QTimer(this);

    //QTimer会每隔⼀定的时间触发⼀个timeout信号，将timeout信号和updateTime连接起来
    //意味着每次触发timeout信号都会伴随updateTime函数的执⾏
    connect(timer, &QTimer::timeout, this, &Widget::updateTime);
    //启动QTimer，每个1000ms触发一次信号
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTime()
{
    int value = ui->lcdNumber->intValue();
    if(value <= 0) {
        timer->stop();
        return;
    }
    ui->lcdNumber->display(value - 1);
}

