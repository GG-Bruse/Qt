#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    //实例化socket
    socket = new QTcpSocket(this);
    //与服务端建立连接
    socket->connectToHost("127.0.0.1", 9090);
    //等待并确认连接是否出错
    if(!socket->waitForConnected()) {
        QMessageBox::critical(nullptr, "连接服务器出错", socket->errorString());
        exit(1);
    }
    //信号槽处理接收请求并响应
    connect(socket, &QTcpSocket::readyRead, this, &Widget::processResponse);
    //信号槽处理发送请求
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::processRequest);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processRequest()
{
    //获取输入框中的内容
    const QString& text = ui->lineEdit->text();
    //清空输入框中的内容
    ui->lineEdit->setText("");
    //将消息显示在界面上
    ui->listWidget->addItem(QString("客户端:") + text);
    //将消息发送给服务端
    socket->write(text.toUtf8());
}

void Widget::processResponse()
{
    QString response = socket->readAll();
    ui->listWidget->addItem(QString("服务端:") + response);
}

