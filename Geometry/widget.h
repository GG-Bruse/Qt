#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

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
    void on_pushButtonRight_clicked();

    void on_pushButtonUp_clicked();

    void on_pushButtonLeft_clicked();

    void on_pushButtonDown_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
