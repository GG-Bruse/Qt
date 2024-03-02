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


void Widget::on_pushButtonRight_clicked()
{
    QRect rect = ui->pushButtonTarget->geometry();
    ui->pushButtonTarget->setGeometry(rect.x() + 5, rect.y(), rect.width(), rect.height());
}

void Widget::on_pushButtonUp_clicked()
{
    QRect rect = ui->pushButtonTarget->geometry();
    ui->pushButtonTarget->setGeometry(rect.x(), rect.y() - 5, rect.width(), rect.height());
}

void Widget::on_pushButtonLeft_clicked()
{
    QRect rect = ui->pushButtonTarget->geometry();
    ui->pushButtonTarget->setGeometry(rect.x() - 5, rect.y(), rect.width(), rect.height());
}

void Widget::on_pushButtonDown_clicked()
{
    QRect rect = ui->pushButtonTarget->geometry();
    ui->pushButtonTarget->setGeometry(rect.x(), rect.y() + 5, rect.width(), rect.height());
}
