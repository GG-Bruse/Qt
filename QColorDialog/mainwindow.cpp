#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800, 600);

    QPushButton* btn = new QPushButton("颜色对话框", this);
    //创建颜色对话框
    QColorDialog* cdlog = new QColorDialog(this);

    connect(btn, &QPushButton::clicked, [=]() {
        //打开颜色对话框，并设置默认颜色为红色
        QColor color = cdlog->getColor(QColor(255, 0, 0));
        qDebug() << "r = " << color.red();
        qDebug() << "g = " << color.green();
        qDebug() << "b = " << color.blue();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

