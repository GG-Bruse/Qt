#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建⼀个位图对象, 加载⾃定义光标图⽚
    QPixmap pixmap(":/rose.png");
    // 缩放图⽚为 64 * 64 的尺⼨
    pixmap = pixmap.scaled(64, 64);
    // 创建 QCursor 对象, 并指定 "热点" 为 (2, 2) 坐标位置
    // 所谓 "热点" 就是⿏标点击时⽣效的位置
    QCursor cursor(pixmap, 2, 2);
    // 设置光标
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

