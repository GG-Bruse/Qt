#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QToolBar* toolbar1 = new QToolBar(this);
    QToolBar* toolbar2 = new QToolBar(this);
    this->addToolBar(Qt::LeftToolBarArea, toolbar1);
    this->addToolBar(Qt::RightToolBarArea, toolbar2);
    toolbar1->setFloatable(true);//允许工具栏浮动
    toolbar2->setFloatable(false);//不允许工具栏浮动
}

MainWindow::~MainWindow()
{
    delete ui;
}

