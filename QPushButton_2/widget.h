#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void on_pushButtonUp_clicked();

    void on_pushButtonDown_clicked();

    void on_pushButtonLeft_clicked();

    void on_pushButtonRight_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
