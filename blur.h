#ifndef BLUR_H
#define BLUR_H

#include <QGraphicsBlurEffect>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QGraphicsPixmapItem>


class Blur : public QVBoxLayout
{
public:
    Blur(QWidget *parent = nullptr);
    ~Blur();
    void hide();
    void show();
    void click_button();
    void applyBlurEffect();
private:

    QLabel* label;
    QPushButton* button;
    QSlider *slider;
    QString fileName;
    QGraphicsBlurEffect *blurEffect{nullptr};
    QGraphicsPixmapItem* pixmapItem{nullptr};
};


#endif // BLUR_H
