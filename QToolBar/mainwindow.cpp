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
}

MainWindow::~MainWindow()
{
    delete ui;
}

