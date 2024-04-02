#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
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

    //声明按键按下事件
    void keyPressEvent(QKeyEvent* event);

    //声明鼠标释放事件
    void mouseReleaseEvent(QMouseEvent* event);

    //声明鼠标双击事件
    void mouseDoubleClickEvent(QMouseEvent* event);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
