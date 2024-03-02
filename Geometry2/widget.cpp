#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand((unsigned int)time(nullptr));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonAccept_clicked()
{
    ui->label->setText("谢谢");
}

void Widget::on_pushButtonReject_pressed()
{
    int width = this->geometry().width();
    int height = this->geometry().height();
    int x = rand() % width, y = rand() % height;
    ui->pushButtonReject->move(x, y);
}
