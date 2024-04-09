#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("服务器");
    //实例化socket
    socket = new QUdpSocket(this);
    //连接信号槽
    connect(socket, &QUdpSocket::readyRead, this, &Widget::processRequest);
    //绑定端口
    bool ret = socket->bind(QHostAddress::Any, 9090);
    if(!ret) {
        QMessageBox::critical(nullptr, "服务器启动出错", socket->errorString());
        return;
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::processRequest()
{
    //读取请求
    const QNetworkDatagram& requestDatagram = socket->receiveDatagram();
    QString request = requestDatagram.data();
    //根据请求计算响应
    const QString& response = process(request);
    //将响应写回客户端
    QNetworkDatagram responseDatagram(response.toUtf8(), requestDatagram.senderAddress(), requestDatagram.senderPort());
    socket->writeDatagram(responseDatagram);
    //打印日志
    QString log = "[" + requestDatagram.senderAddress().toString() + ":" + \
            QString::number(requestDatagram.senderPort()) + "] request:" + \
            request + ", response:" + response;
    ui->listWidget->addItem(log);
}

//本代码实现的是回显服务器，所以process方法中不包含实质性的业务代码
QString Widget::process(const QString &request) {
    return request;
}
