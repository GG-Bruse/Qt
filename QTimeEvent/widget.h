#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //重写定时器事件
    void timerEvent(QTimerEvent* event);
private:
    Ui::Widget *ui;
    int timerId1 = 0;
    int timerId2 = 0;
};
#endif // WIDGET_H
