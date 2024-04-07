#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::startShow);
    connect(&thread, &Thread::sendTime, this, &Widget::showTime);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startShow()
{
    thread.start();
}

void Widget::showTime(QString time)
{
    ui->label->setText(time);
}
