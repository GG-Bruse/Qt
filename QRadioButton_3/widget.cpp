#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建三个QButtonGroup
    QButtonGroup* group1 = new QButtonGroup(this);
    QButtonGroup* group2 = new QButtonGroup(this);
    QButtonGroup* group3 = new QButtonGroup(this);
    //将QRadioButton两两一组放入QButtonGroup中
    group1->addButton(ui->radioButton);
    group1->addButton(ui->radioButton_2);

    group2->addButton(ui->radioButton_3);
    group2->addButton(ui->radioButton_4);

    group3->addButton(ui->radioButton_5);
    group3->addButton(ui->radioButton_6);
}

Widget::~Widget()
{
    delete ui;
}

