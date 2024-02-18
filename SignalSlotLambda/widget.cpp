#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* btn = new QPushButton("按钮", this);
    btn->move(200, 200);

    connect(btn, &QPushButton::clicked, this, [=](){
        btn->move(300, 300);
    });
}

Widget::~Widget()
{
    delete ui;
}

