#ifndef SOUND_BUTTON_H
#define SOUND_BUTTON_H

#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>

class SOUND_BUTTON : public QPushButton
{
public:
    SOUND_BUTTON(QWidget *parent = nullptr);
    ~SOUND_BUTTON();
  //  void paintEvent(QPaintEvent *event) override;
protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QTimer* changeTimer;
    QPixmap backgroundPixmap;
    QMediaPlayer *player{nullptr};
    QAudioOutput *audioOutput{nullptr};
};

#endif // SOUND_BUTTON_H
