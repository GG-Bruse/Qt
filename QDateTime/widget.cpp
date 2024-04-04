#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        timer->start(1000);
    });
    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        timer->stop();
    });
    connect(timer, &QTimer::timeout, this, &Widget::UpDateTime);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::UpDateTime()
{
    QString str = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->label->setText(str);
}
