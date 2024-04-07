#ifndef THREAD_H
#define THREAD_H

#include <QWidget>
#include <QThread>
#include <QMutex>
#include <QDebug>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(QObject* parent = nullptr);
    void run();
private:
    static QMutex mutex; //多个线程使用一把锁
    static int number;	 //多个线程访问同一个数据
};

#endif // THREAD_H
