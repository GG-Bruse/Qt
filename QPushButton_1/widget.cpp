#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建图标
    QIcon icon(":/dog.png");
    //设置图标
    ui->pushButton->setIcon(icon);
    //设置图标大小
    ui->pushButton->setIconSize(QSize(66, 66));
}

Widget::~Widget()
{
    delete ui;
}
