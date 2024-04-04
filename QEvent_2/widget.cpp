#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
       qDebug() << "鼠标左键被按下";
}

bool Widget::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress) {
        qDebug() << "事件分发器捕捉到鼠标按下事件";
        return true;//拦截
    }
    if(event->type() == QEvent::MouseButtonDblClick) {
        qDebug() << "事件分发器捕捉到鼠标双击事件";
        return true;//拦截
    }
    //其他事件交给父类处理(默认处理)
    return QWidget::event(event);
}

