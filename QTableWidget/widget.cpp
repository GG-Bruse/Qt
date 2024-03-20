#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建3行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);
    //创建3列
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);
    //给3列设定列名
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("年龄"));
    //设置初始数据
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("20"));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("1002"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("21"));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("1003"));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem("22"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAddRow_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
}

void Widget::on_pushButtonAddColumn_clicked()
{
    int colCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(colCount);
    const QString& name = ui->lineEdit->text();
    ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(name));
}

void Widget::on_pushButtonDeleteRow_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(currentRow);
}

void Widget::on_pushButtonDeleteColumn_clicked()
{
    int currentCol = ui->tableWidget->currentColumn();
    ui->tableWidget->removeColumn(currentCol);
}
