#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(1000, 1000);

    btn = new QPushButton("按钮", this);
    btn->move(200, 200);
    connect(btn, &QPushButton::clicked, this, &Widget::HandleClicked_1);

    QPushButton* changeBtn = new QPushButton("修改按钮功能", this);
    changeBtn->move(200, 400);
    connect(changeBtn, &QPushButton::clicked, this, &Widget::ChangeButtonRole);

    QPushButton* button = new QPushButton("点击移动", this);
    button->move(400, 800);
    connect(button, &QPushButton::clicked, this, [=](){
        qDebug() << "Lambda";
        button->move(800, 800);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::HandleClicked_1() { setWindowTitle("修改窗口标题1"); }

void Widget::HandleClicked_2() { setWindowTitle("修改窗口标题2"); }

void Widget::ChangeButtonRole()
{
    disconnect(btn, &QPushButton::clicked, this, &Widget::HandleClicked_1);
    connect(btn, &QPushButton::clicked, this, &Widget::HandleClicked_2);
    qDebug() << "修改成功";
}
