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

void Widget::on_pushButton_clicked()
{
    QString result;
    if(ui->checkBoxEat->isChecked())
        result += ui->checkBoxEat->text();
    if(ui->checkBoxSleep->isChecked())
        result += ui->checkBoxSleep->text();
    if(ui->checkBoxPlay->isChecked())
        result += ui->checkBoxPlay->text();
    qDebug() << "选中的内容:" << result;
}
