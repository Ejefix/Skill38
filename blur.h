#ifndef BLUR_H
#define BLUR_H

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>



class Blur : public QGridLayout
{
public:
    Blur(QWidget *parent = nullptr);
    ~Blur();
private:
    QLabel* label;
    QPushButton* button;
    QSlider *slider;
};

#endif // BLUR_H
