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

void Widget::on_pushButtonAdd_clicked()
{
    float opacity = this->windowOpacity();
    if(opacity >= 1.0) return;
    else this->setWindowOpacity(opacity + 0.1);
    qDebug() << opacity + 0.1;
}

void Widget::on_pushButtonSub_clicked()
{
    float opacity = this->windowOpacity();
    if(opacity <= 0.0) return;
    else this->setWindowOpacity(opacity - 0.1);
    qDebug() << opacity - 0.1;
}
