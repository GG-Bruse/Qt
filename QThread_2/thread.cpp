#include "thread.h"

QMutex Thread::mutex;
int Thread::number;

Thread::Thread(QObject* parent):QThread(parent) {}

void Thread::run()
{
    while(true)
    {
        mutex.lock();
        qDebug() << "current thread:" << this << ", value:" << number++;
        mutex.unlock();
        QThread::sleep(2);//休眠两秒
    }
}
