#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QToolBar* toolbar1 = new QToolBar(this);
    QToolBar* toolbar2 = new QToolBar(this);
    this->addToolBar(toolbar1);
    this->addToolBar(toolbar2);
    //只允许在左侧停靠
    toolbar1->setAllowedAreas(Qt::LeftToolBarArea);
    //只允许在右侧停靠
    toolbar2->setAllowedAreas(Qt::RightToolBarArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

