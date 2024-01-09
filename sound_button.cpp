#include "sound_button.h"

#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <thread>



SOUND_BUTTON::SOUND_BUTTON(QWidget *parent): QPushButton(parent),changeTimer{new QTimer(this)}
{
    backgroundPixmap.load(":/green.png");
    // setStyleSheet("QPushButton { background-image: url(':/green.png'); }");
    connect(changeTimer, &QTimer::timeout, this, [this]()
            {
                backgroundPixmap.load(":/green.png");
                changeTimer->stop();
                update();
            }
            );


}

SOUND_BUTTON::~SOUND_BUTTON()
{
    delete changeTimer;
    delete audioOutput;
    delete player;

}

void SOUND_BUTTON::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawPixmap(rect(), backgroundPixmap);
   // QPushButton::paintEvent(event);
}

void SOUND_BUTTON::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        backgroundPixmap.load(":/blue.png");
        changeTimer->start(400);
        delete audioOutput;
        delete player;
        player = new QMediaPlayer;
        audioOutput = new QAudioOutput;
        player->setSource(QUrl("qrc:/button.mp3"));
        player->setAudioOutput(audioOutput);
        audioOutput->setVolume(100);
        player->play();


    }
  //  QPushButton::mousePressEvent(event);
}
