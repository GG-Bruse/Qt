#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    //创建菜单栏
//    QMenuBar* menubar = menuBar();
//    //将菜单栏设置进窗口中
//    this->setMenuBar(menubar);

    //创建菜单栏
    QMenuBar* menubar = new QMenuBar(this);
    //将菜单栏设置进窗口中
    this->setMenuBar(menubar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

