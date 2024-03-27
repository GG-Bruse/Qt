#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar* menubar = menuBar();
    this->setMenuBar(menubar);

    QMenu* menu1 = new QMenu("文件");
    QMenu* menu2 = new QMenu("编辑");
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);

    QAction* action = new QAction("新建");
    menu1->addAction(action);

    QToolBar* toolbar = new QToolBar(this);
    this->addToolBar(toolbar);
    toolbar->addAction(action);

    //当点击新建时，弹出一个模态对话框
    connect(action, &QAction::triggered, [=](){
        QDialog dialog;
        dialog.resize(300, 200);
        dialog.exec();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
