#include "sound_button.h"

#include <QPainter>
#include <QMouseEvent>
#include <QTimer>

SOUND_BUTTON::SOUND_BUTTON(QWidget *parent): QPushButton(parent),changeTimer{new QTimer(this)}
{

    setStyleSheet("QPushButton { border-image: url(:/green.png) 0 0 0 0 stretch stretch; }");
    connect(changeTimer, &QTimer::timeout, this, [this]()
            {
                setStyleSheet("QPushButton { border-image: url(:/green.png) 0 0 0 0 stretch stretch; }");
                changeTimer->stop();
            }
            );
}

SOUND_BUTTON::~SOUND_BUTTON()
{
    qDebug() << "~SOUND_BUTTON()";
    delete changeTimer;
    delete audioOutput;
    delete player;

}

void SOUND_BUTTON::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        setStyleSheet("QPushButton { border-image: url(:/blue.png) 0 0 0 0 stretch stretch; }");
        changeTimer->start(300);

        delete audioOutput;
        delete player;
        player = new QMediaPlayer;
        audioOutput = new QAudioOutput;

        player->setSource(QUrl("qrc:/button.mp3"));
        player->setAudioOutput(audioOutput);
        audioOutput->setVolume(100);
        player->play();
    }
    QPushButton::mousePressEvent(event);
}
