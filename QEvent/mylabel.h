#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    //鼠标进入事件
    void enterEvent(QEvent* event);
    //鼠标移动事件
    void mousePressEvent(QMouseEvent* event);

signals:

};

#endif // MYLABEL_H
