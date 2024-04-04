#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer* timer = new QTimer(this);

    connect(ui->pushButtonStart, &QPushButton::clicked, [=]() {
        timer->start(1000);
    });
    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;
        ui->label->setText(QString::number(num++));
    });
    connect(ui->pushButtonStop, &QPushButton::clicked, [=](){
        timer->stop();
    });
}

Widget::~Widget()
{
    delete ui;
}

