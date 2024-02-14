#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget* parent):QLabel(parent)
{

}

MyLabel::~MyLabel()
{
    qDebug() << "MyLabel对象释放";
}
