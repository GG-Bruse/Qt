#include "widget.h"
#include "ui_widget.h"
#include "mylabel.h"

#include <QObject>
#include <QLabel>
#include <QLineEdit>


Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QLabel* label1 = new QLabel(this);
//    label1->setText("Hello world too");
//    MyLabel* label2 = new MyLabel(this);
//    label2->setText("Hello world too too");
//    QLineEdit* edit = new QLineEdit(this);
//    edit->setText("hello LineEdit too");

    myPushButton = new QPushButton(this);
    myPushButton->setText("Hello Push Button");
    myPushButton->move(200, 300);
    connect(myPushButton, &QPushButton::clicked, this, &Widget::handleClick);
    this->move(700, 500);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    //当点击按钮后，将按钮中的文字进行切换
    if(myPushButton->text() == QString("hello Qt"))
        myPushButton->setText("Hello Push Button");
    else
        myPushButton->setText("hello Qt");
}
