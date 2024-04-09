#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //对象实例化
    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    //设置播放画⾯的窗⼝
    videoWidget->setMinimumSize(600,600);

    //实例化窗⼝布局---垂直布局
    this->vbox = new QVBoxLayout(this);
    this->setLayout(this->vbox);

    //实例化选择视频按钮
    chooseBtn = new QPushButton("选择视频",this);

    //实例化播放按钮
    playBtn = new QPushButton(this);
    //设置图标
    playBtn->setIcon(this->style()->standardIcon(QStyle::SP_MediaPlay));

    //实例化⼀个⽔平布局，将按钮放⼊⽔平布局中
    QHBoxLayout *hbox = new QHBoxLayout;
    //添加控件
    hbox->addWidget(chooseBtn);
    hbox->addWidget(playBtn);

    //将播放窗⼝和⽔平布局都添加到垂直布局中
    vbox->addWidget(videoWidget);
    vbox->addLayout(hbox);

    //将选择视频对应的按钮和槽函数进⾏关联
    connect(chooseBtn,&QPushButton::clicked,this,&Widget::chooseVideo);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::chooseVideo()
{
    //选择视频，返回⼀个播放视频的名字
    QString name = QFileDialog::getSaveFileName(this, "选择视频", ".", "MP4(*.mp4)");
    //设置媒体源
    mediaPlayer->setMedia(QUrl(name));
    //将视频输出附加到媒体播放器上
    mediaPlayer->setVideoOutput(videoWidget);
    //播放
    mediaPlayer->play();
}

