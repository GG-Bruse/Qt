#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    //调整窗口大小
    resize(800, 600);
    //创建按钮并设置其位置
    QPushButton* btn = new QPushButton("关闭窗口", this);
    btn->move(350, 260);
    //管理信号和槽，实现点击按钮则关闭窗口
    connect(btn, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
    delete ui;
}

