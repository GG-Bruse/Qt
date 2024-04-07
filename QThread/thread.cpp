#include "thread.h"

Thread::Thread() {}

void Thread::run()
{
    while(true)
    {
        QString time = QTime::currentTime().toString("hh:mm:ss");
        qDebug() << time;
        emit sendTime(time);//发送信号
        sleep(1);
    }
}
