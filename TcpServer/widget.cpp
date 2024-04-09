#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("服务端");
    //实例化tcpServer
    tcpServer = new QTcpServer(this);
    //信号槽处理新连接
    connect(tcpServer, &QTcpServer::newConnection, this, &Widget::processConnection);
    //监听端口
    bool ret = tcpServer->listen(QHostAddress::Any, 9090);
    if(!ret) {
        QMessageBox::critical(nullptr, "服务器启动出错", tcpServer->errorString());
        return;
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processConnection()
{
    //获取新连接对应的socket
    QTcpSocket* socket = tcpServer->nextPendingConnection();
    //打印日志
    QString log = "[" + socket->peerAddress().toString() + ":" + \
            QString::number(socket->peerPort()) + "]客户端上线";
    ui->listWidget->addItem(log);

    //通过信号槽处理接收到的请求
    connect(socket, &QTcpSocket::readyRead, [=]() {
        //读取请求
        QString request = socket->readAll();
        //根据请求处理响应
        QString response = process(request);
        //将响应写回客户端
        socket->write(response.toUtf8());
        //打印日志
        QString log = QString("[") + socket->peerAddress().toString() \
                + ":" + QString::number(socket->peerPort()) + "] request: " + \
                request + ", response: " + response;
        ui->listWidget->addItem(log);
    });

    //通过信号槽处理断开连接的情况
    connect(socket, &QTcpSocket::disconnected, this, [=]() {
        QString log = QString("[") + socket->peerAddress().toString() \
                + ":" + QString::number(socket->peerPort()) + "] 客⼾端下线";
        ui->listWidget->addItem(log);
        // 删除 clientSocket
        socket->deleteLater();
    });
}

QString Widget::process(const QString& request) {
    return request;
}






