#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* btn1 = new QPushButton("Yes", this);
    btn1->setToolTip("这是一个Yes按钮");
    btn1->setToolTipDuration(3000);

    QPushButton* btn2 = new QPushButton("No", this);
    btn2->move(100, 100);
    btn2->setToolTip("这是一个No按钮");
    btn2->setToolTipDuration(7000);
}

Widget::~Widget()
{
    delete ui;
}

