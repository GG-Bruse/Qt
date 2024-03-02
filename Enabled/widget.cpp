#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    btn1 = new QPushButton("按钮", this);
    btn1->move(200, 200);
    btn2 = new QPushButton("切换可用状态", this);
    btn2->move(200, 400);

    connect(btn1, &QPushButton::clicked, this, &Widget::Handle);
    connect(btn2, &QPushButton::clicked, this, &Widget::Change);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Handle()
{
    qDebug() << "点击按钮成功";
}

void Widget::Change()
{
    if(btn1->isEnabled()) btn1->setEnabled(false);
    else btn1->setEnabled(true);
    qDebug() << "切换状态成功";
}

