#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //安装事件过滤器
    this->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QString str = QString("鼠标按下: x = %1, y = %2").arg(event->x()).arg(event->y());
    qDebug() << str;
}

bool Widget::event(QEvent *event)
{
    //若是鼠标按下事件,在event事件分发时拦截
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* eventM = static_cast<QMouseEvent*> (event);
        QString str = QString("event中鼠标按下: x = %1, y = %2").arg(eventM->x()).arg(eventM->y());
        qDebug() << str;
        return true;
    }
    return QWidget::event(event);
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* eventM = static_cast<QMouseEvent*> (event);
            QString str = QString("事件过滤器中中鼠标按下: x = %1, y = %2").arg(eventM->x()).arg(eventM->y());
            qDebug() << str;
            return true;
        }
    }
    return QWidget::event(event);
}

