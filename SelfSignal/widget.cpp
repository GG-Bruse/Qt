#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* btn = new QPushButton("按钮", this);
    btn->move(100, 100);
    connect(btn, &QPushButton::clicked, this, &Widget::handleClicked);

    connect(this, &Widget::mySignal, this, &Widget::handleMySignal);
    emit mySignal("带参数的信号");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClicked()
{
    //按下按钮修改窗口标题
    setWindowTitle("按钮已按下");
}

void Widget::handleMySignal(const QString& text)
{
    setWindowTitle(text);
}

void Widget::on_pushButton_clicked()
{
    setWindowTitle("按钮已按下");
}
