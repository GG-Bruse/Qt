#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <QWidget>
#include <ctime>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonAccept_clicked();

    void on_pushButtonReject_pressed();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
