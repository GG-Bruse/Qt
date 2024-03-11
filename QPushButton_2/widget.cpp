#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置图标
    ui->pushButtonTarget->setIcon(QIcon(":/image/dog.png"));
    ui->pushButtonUp->setIcon(QIcon(":/image/Up.png"));
    ui->pushButtonDown->setIcon(QIcon(":/image/Down.png"));
    ui->pushButtonLeft->setIcon(QIcon(":/image/Left.png"));
    ui->pushButtonRight->setIcon(QIcon(":/image/Right.png"));
    //设置快捷键1
    ui->pushButtonUp->setShortcut(QKeySequence(Qt::Key_W));
    ui->pushButtonDown->setShortcut(QKeySequence(Qt::Key_S));
    ui->pushButtonLeft->setShortcut(QKeySequence(Qt::Key_A));
    ui->pushButtonRight->setShortcut(QKeySequence(Qt::Key_D));
    //设置快捷键2
//    ui->pushButtonUp->setShortcut(QKeySequence("W"));
//    ui->pushButtonDown->setShortcut(QKeySequence("S"));
//    ui->pushButtonLeft->setShortcut(QKeySequence("A"));
//    ui->pushButtonRight->setShortcut(QKeySequence("D"));

    //开启鼠标重复触发
    ui->pushButtonUp->setAutoRepeat(true);
    ui->pushButtonDown->setAutoRepeat(true);
    ui->pushButtonLeft->setAutoRepeat(true);
    ui->pushButtonRight->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonUp_clicked()
{
    const QRect& rect = ui->pushButtonTarget->geometry();
    ui->pushButtonTarget->setGeometry(rect.x(), rect.y() - 5, rect.height(), rect.width());
}

void Widget::on_pushButtonDown_clicked()
{
    const QRect& rect = ui->pushButtonTarget->geometry();
    ui->pushButtonTarget->setGeometry(rect.x(), rect.y() + 5, rect.height(), rect.width());
}

void Widget::on_pushButtonLeft_clicked()
{
    const QRect& rect = ui->pushButtonTarget->geometry();
    ui->pushButtonTarget->setGeometry(rect.x() - 5, rect.y(), rect.height(), rect.width());
}

void Widget::on_pushButtonRight_clicked()
{
    const QRect& rect = ui->pushButtonTarget->geometry();
    ui->pushButtonTarget->setGeometry(rect.x() + 5, rect.y(), rect.height(), rect.width());
}
