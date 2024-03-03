#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QRect rect1 = this->geometry();
    QRect rect2 = this->frameGeometry();
    qDebug() << rect1;
    qDebug() << rect2;

    QPushButton* btn = new QPushButton("按钮", this);
    connect(btn, &QPushButton::clicked, this, &Widget::Handle);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Handle()
{
    QRect rect1 = this->geometry();
    QRect rect2 = this->frameGeometry();
    qDebug() << rect1;
    qDebug() << rect2;
}

