#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("窗口标题");

    QPushButton* btn = new QPushButton("按钮", this);
    btn->setWindowTitle("按钮标题");//无作用,不报错
}

Widget::~Widget()
{
    delete ui;
}

