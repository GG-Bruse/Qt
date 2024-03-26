#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar* menubar = menuBar();
    this->setMenuBar(menubar);
    //创建菜单
    QMenu* menu1 = new QMenu("文件");
    QMenu* menu2 = new QMenu("编辑");
    QMenu* menu3 = new QMenu("构建");
    //将菜单添加到菜单栏中
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);
    //创建菜单项
    QAction* action1 = new QAction("open");
    QAction* action2 = new QAction("close");
    QAction* action3 = new QAction("create");
    //将菜单项添加到菜单上
    menu1->addAction(action1);
    menu1->addAction(action2);
    menu1->addAction(action3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
