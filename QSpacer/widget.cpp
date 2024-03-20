#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    // 创建 Spacer
    QSpacerItem* spacer = new QSpacerItem(200, 20);
    layout->addWidget(btn1);
    // 在两个 widget 中间添加空⽩
    layout->addSpacerItem(spacer);
    layout->addWidget(btn2);
}

Widget::~Widget()
{
    delete ui;
}

