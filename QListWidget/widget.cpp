#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("Python");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current != nullptr && previous != nullptr)
        qDebug() << "当前选中:" << current->text() << ",之前选中:" << previous->text();
}

void Widget::on_pushButtonAdd_clicked()
{
    const QString& text = ui->lineEdit->text();
    if(!text.isEmpty())
        ui->listWidget->addItem(text);
}

void Widget::on_pushButtonDel_clicked()
{
    int row = ui->listWidget->currentRow();
    ui->listWidget->takeItem(row);
}
