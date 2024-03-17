#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::ifstream file("D:\\repositorys\\Qt\\QComboBox_2\\config.txt");
    std::string line;
    while(std::getline(file, line))
        ui->comboBox->addItem(QString::fromStdString(line));
    file.close();
}

Widget::~Widget()
{
    delete ui;
}

