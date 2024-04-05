#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("简易记事本");
    resize(1200, 1000);

    QMenuBar* menubar = menuBar();
    setMenuBar(menubar);

    QMenu* menu1 = new QMenu("文件");
    QMenu* menu2 = new QMenu("编辑");
    QMenu* menu3 = new QMenu("查看");
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);

    QAction* action1 = new QAction("打开");
    QAction* action2 = new QAction("保存");
    menu1->addAction(action1);
    menu1->addAction(action2);

    QFont font;
    font.setPixelSize(25);
    edit = new QPlainTextEdit();
    edit->setFont(font);
    setCentralWidget(edit);

    connect(action1, &QAction::triggered, this, &MainWindow::handleAction1);
    connect(action2, &QAction::triggered, this, &MainWindow::handleAction2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleAction1()
{
    //弹出打开文件的对话框
    QString path = QFileDialog::getOpenFileName();
    //将文件路径显示到状态栏
    QStatusBar* statusbar = statusBar();
    statusbar->showMessage(path);
    //构造QFile对象,打开文件
    QFile file(path);
    bool ret = file.open(QIODevice::ReadOnly);
    if(!ret) statusbar->showMessage(path + "打开失败");
    //读取文件
    QString text = file.readAll();
    //关闭文件
    file.close();
    //将读取的内容设置到文本框中
    edit->setPlainText(text);
}

void MainWindow::handleAction2()
{
    //弹出保存文件的对话框
    QString path = QFileDialog::getSaveFileName();
    //将文件路径显示到状态栏
    QStatusBar* statusbar = statusBar();
    statusbar->showMessage(path);
    //构造QFile对象,打开文件
    QFile file(path);
    bool ret = file.open(QIODevice::WriteOnly);
    if(!ret) statusbar->showMessage(path + "打开失败");
    //写文件
    const QString& text = edit->toPlainText();
    file.write(text.toUtf8());
    //关闭文件
    file.close();
}

