#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置文字居中对齐
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label->setText("垂直水平居中的文本");
    //设置自动换行
    ui->label_2->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->label_2->setWordWrap(true);
    ui->label_2->setText("这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本");
    //设置首行缩进
    ui->label_3->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->label_3->setIndent(20);
    ui->label_3->setText("这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本");
    //设置边距
    ui->label_4->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->label_4->setMargin(20);
    ui->label_4->setText("这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本");
}

Widget::~Widget()
{
    delete ui;
}

