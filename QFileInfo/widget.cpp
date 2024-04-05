#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QFileInfo>
#include <QFileDialog>
#include <QDateTime>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton("按钮", this);
    connect(button, &QPushButton::clicked, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "查看文件信息", "./");

        QFileInfo fileinfo(path);
        //文件名
        qDebug() << "文件名为：" << fileinfo.fileName().toUtf8().data();
        //文件后缀名
        qDebug() << "后缀名为：" << fileinfo.suffix().toUtf8().data();
        //文件大小
        qDebug() << "文件大小为：" << fileinfo.size();
        //文件路径
        qDebug() << "文件路径为：" << fileinfo.path().toUtf8().data();
        //判断是否为⽂件
        qDebug() << "是否为文件："<< fileinfo.isFile();
        //文件创建时间
        QDateTime time1 = fileinfo.fileTime(QFileDevice::FileBirthTime);
        qDebug() << "创建时间为：" << time1.toString("yyyy-MM-dd hh:mm:ss").toUtf8().data();
        //文件的最后修改⽇期
        QDateTime time2 = fileinfo.lastModified();
        qDebug() << "最后修改时间为："<< time2.toString("yyyy-MM-dd hh:mm:ss").toUtf8().data();
        //判断是否为文件夹
        qDebug() << "是否为目录：" << fileinfo.isDir();

    });
}

Widget::~Widget()
{
    delete ui;
}

