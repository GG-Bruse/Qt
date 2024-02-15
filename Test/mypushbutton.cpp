#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "我的按钮的构造函数被调用";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "我的按钮的析构函数被调用";
}
