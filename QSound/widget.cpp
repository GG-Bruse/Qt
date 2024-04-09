#include "widget.h"
#include "ui_widget.h"
#include <QSound>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSound* sound = new QSound(":/BackButtonSound.wav", this);
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        sound->play();
    });
}
Widget::~Widget()
{
    delete ui;
}

