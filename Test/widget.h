#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>  //QWidget窗口类头文件
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT    //该宏允许类中使用信号和槽的机制

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;//通过该指针可以访问UI设计界面中的任意控件
};
#endif // WIDGET_H
