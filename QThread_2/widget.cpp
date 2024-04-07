#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Thread* thread1 = new Thread(this);
    Thread* thread2 = new Thread(this);
    thread1->start();
    thread2->start();
}

Widget::~Widget()
{
    delete ui;
}

