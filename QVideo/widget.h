#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout> //⽔平布局
#include <QVBoxLayout> //垂直布局
#include <QVideoWidget> //显⽰视频
#include <QMediaPlayer> //播放声⾳
#include <QPushButton> //按钮
#include <QStyle> //设置图标
#include <QFileDialog> //选择⽂件/⽂件夹

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void chooseVideo();

private:
    Ui::Widget *ui;

    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    QVBoxLayout *vbox;
    QPushButton *chooseBtn,*playBtn;
};
#endif // WIDGET_H
