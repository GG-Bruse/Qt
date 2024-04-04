#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //鼠标按下事件
    void mousePressEvent(QMouseEvent* event);
    //事件分发器
    bool event(QEvent* event);

    //声明eventfilter事件
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
