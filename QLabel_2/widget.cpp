#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置label大小与窗口大小相同
    ui->label->setGeometry(0, 0, 800, 600);
    //设置label图片
    QPixmap pixmap(":/huaji.png");
    ui->label->setPixmap(pixmap);
    //设置label内容拉伸
    ui->label->setScaledContents(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    ui->label->setGeometry(0, 0, event->size().width(), event->size().height());
    qDebug() << event->size();
}
