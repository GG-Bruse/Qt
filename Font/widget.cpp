#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置 label 的⽂本内容
    ui->label->setText("这是⼀段⽂本");
    // 创建字体对象
    QFont font;
    // 设置字体家族
    font.setFamily("仿宋");
    // 设置字体⼤⼩
    font.setPointSize(20);
    // 设置字体加粗
    font.setBold(true);
    // 设置字体倾斜
    font.setItalic(true);
    // 设置字体下划线
    font.setUnderline(true);
    // 设置字体删除线
    font.setStrikeOut(true);
    // 设置字体对象到 label 上
    ui->label->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}

