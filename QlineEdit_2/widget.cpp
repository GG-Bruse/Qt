#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置按钮默认是禁用状态
    ui->pushButton->setEnabled(false);
    //注册一个validator
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("^1\\d{10}$")));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    qDebug() << arg1;
    QString content = arg1;
    int pos = 0;
    if(ui->lineEdit->validator()->validate(content, pos) == QValidator::Acceptable)
        ui->pushButton->setEnabled(true);
    else
        ui->pushButton->setEnabled(false);
}
