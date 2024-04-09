#include "widget.h"
#include "ui_widget.h"

const QString SERVER_IP = "127.0.0.1";
const qint16 SERVER_PORT = 9090;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    //实例化socket
    socket = new QUdpSocket(this);
    //连接按钮的信号槽
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::sendRequest);
    //连接socket的信号槽
    connect(socket, &QUdpSocket::readyRead, this, &Widget::recvResponse);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendRequest()
{
    //获取输入框的内容
    const QString& text = ui->lineEdit->text();
    //构造请求数据
    QNetworkDatagram requestDatagram(text.toUtf8(), QHostAddress(SERVER_IP), SERVER_PORT);
    //发送请求
    socket->writeDatagram(requestDatagram);
    //消息添加到列表框中
    ui->listWidget->addItem("客户端:" + text);
    //清空输入框
    ui->lineEdit->setText("");
}

void Widget::recvResponse()
{
    //读取请求
    const QNetworkDatagram& responseDatagram = socket->receiveDatagram();
    QString response = responseDatagram.data();
    //消息添加入列表
    ui->listWidget->addItem(QString("服务器:") + response);
}

