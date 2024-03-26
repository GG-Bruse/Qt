#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar* toolbar1 = new QToolBar(this);
    QToolBar* toolbar2 = new QToolBar(this);
    //创建工具栏时，指定工具栏在左侧显示
    this->addToolBar(Qt::LeftToolBarArea, toolbar1);
    //创建工具栏时，指定工具栏在右侧显示
    this->addToolBar(Qt::RightToolBarArea, toolbar2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

