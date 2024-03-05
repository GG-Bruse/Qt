#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QIcon icon(":/rose.png");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}

