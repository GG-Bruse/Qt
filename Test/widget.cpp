#include "widget.h"
#include "ui_widget.h"
#include "mypushbutton.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* btn1 = new QPushButton("按钮1", this);
    btn1->move(200, 300);
    QPushButton* btn2 = new QPushButton("按钮2", this);
    qDebug() << "按钮1的坐标为：[" << btn1->x() << "," << btn1->y() << "]";
    qDebug() << "按钮2的坐标为：[" << btn2->x() << "," << btn2->y() << "]";
}

Widget::~Widget()
{
    delete ui;
}

