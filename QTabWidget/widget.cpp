#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel* label = new QLabel(ui->tab);
    label->setText("标签页1");
    label->resize(100, 50);

    QLabel* label2 = new QLabel(ui->tab_2);
    label2->setText("标签页2");
    label->resize(100, 50);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAdd_clicked()
{
    //获取当前标签页的数量
    int count = ui->tabWidget->count();
    //创建新的widget
    QWidget* widget = new QWidget();
    ui->tabWidget->addTab(widget, QString("Tab ") + QString::number(count + 1));
    //往widget中添加label
    QLabel* label = new QLabel(widget);
    label->setText(QString("标签页") + QString::number(count + 1));
    label->resize(100, 50);
    //选中这个新标签页
    ui->tabWidget->setCurrentIndex(count);
}

void Widget::on_pushButtonDel_clicked()
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->removeTab(index);
}
