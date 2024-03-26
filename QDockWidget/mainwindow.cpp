#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //浮动窗口
    QDockWidget* dockwidget = new QDockWidget("浮动窗口", this);
    //将浮动窗口设置与当前窗口中
    this->addDockWidget(Qt::BottomDockWidgetArea, dockwidget);
    //只允许上下停靠
    dockwidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

