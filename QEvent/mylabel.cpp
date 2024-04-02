#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::enterEvent(QEvent *event)
{
    qDebug() << "鼠标进入";
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    QString str = QString("鼠标按下了 x = %1, y = %2").arg(event->x()).arg(event->y());
    qDebug() << str;
}
