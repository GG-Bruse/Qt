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

void Widget::wheelEvent(QWheelEvent *event)
{
    static int total = 0;
    total += event->delta();
    if(event->delta() > 0)
       qDebug() << "鼠标向前滚";
    else
        qDebug() << "鼠标向后滚";
    qDebug() << total;
}

