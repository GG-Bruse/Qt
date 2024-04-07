#ifndef THREAD_H
#define THREAD_H

#include <QWidget>
#include <QThread>
#include <QTime>
#include <QDebug>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();
public:
    void run();//重写
signals:
    void sendTime(QString time);//声明信号函数
};

#endif // THREAD_H
