#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    //实例化manager
    manager = new QNetworkAccessManager(this);
    //信号槽处理发送请求
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::processRequest);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::processRequest()
{
    //获取输入框中url
    QUrl url(ui->lineEdit->text());
    //构造HTTP请求
    QNetworkRequest request(url);
    //发送GET请求
    QNetworkReply* response = manager->get(request);

    //通过信号槽处理响应
    connect(response, &QNetworkReply::finished, [=]() {
        if(response->error() == QNetworkReply::NoError) {
            QString html(response->readAll());
            ui->plainTextEdit->setPlainText(html);
        }
        else {
            ui->plainTextEdit->setPlainText(response->errorString());
        }
        response->deleteLater();
    });
}

