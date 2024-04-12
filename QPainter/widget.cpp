#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>

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

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(200, 300);
    painter.rotate(90);
    painter.translate(-200, -300);
    painter.drawPixmap(0, 0, QPixmap(":/down.png"));
}

