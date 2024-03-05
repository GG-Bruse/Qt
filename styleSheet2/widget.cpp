#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonLight_clicked()
{
    this->setStyleSheet("background-color: #f3f3f3");
    ui->textEdit->setStyleSheet("background-color: #fff; color: #000;");
    ui->pushButtonLight->setStyleSheet("color: #000");
    ui->pushButtonDark->setStyleSheet("color: #000");
}

void Widget::on_pushButtonDark_clicked()
{
    this->setStyleSheet("background-color: #333");
    ui->textEdit->setStyleSheet("background-color: #333; color: #fff;");
    ui->pushButtonLight->setStyleSheet("color: #fff");
    ui->pushButtonDark->setStyleSheet("color: #fff");
}
