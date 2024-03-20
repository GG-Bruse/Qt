#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建三个按钮
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    QPushButton* btn3 = new QPushButton("按钮3");
    //创建布局管理器，并将按钮添加进去
    //若创建时指定父元素为this,则后面不需要setLayout了
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    //将布局管理器设置到widget中
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

