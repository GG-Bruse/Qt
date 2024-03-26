#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStatusBar* stbar = statusBar();
    this->setStatusBar(stbar);

//    //状态栏中显示约2秒的"Hello_Qt"
//    stbar->showMessage("Hello_Qt", 2000);

    //创建标签
    QLabel* label = new QLabel("提示消息", this);
    //将标签放入状态栏
    stbar->addWidget(label);

    //创建标签
    QLabel* label2 = new QLabel("右侧提示消息", this);
    //将标签放入状态栏
    stbar->addPermanentWidget(label2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

