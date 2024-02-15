#include "widget.h"

#include <QApplication> // Qt系统提供的标准类名声明头⽂件，没有.h后缀
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;                   //实例化窗⼝对象
    w.show();                   //调⽤show函数显⽰窗⼝

//    QPushButton quit("Quit");
//    QWidget window;
//    quit.setParent(&window);
//    window.show();
    return a.exec();
}
