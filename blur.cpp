#include "blur.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>


Blur::Blur(QWidget *parent):QVBoxLayout(parent),
    label{new QLabel},button{new QPushButton("Open")},slider {new QSlider(Qt::Orientation::Horizontal)}
{
    addWidget( label,1);
    addWidget( button);
    addWidget(slider);

    slider->setMinimum(0);
    slider->setMaximum(10);


    label->setAlignment(Qt::AlignCenter);

    connect(button,&QPushButton::clicked,this,&Blur::click_button);
    connect(slider,&QSlider::valueChanged ,this, [this](){
        applyBlurEffect();
    });

}

Blur::~Blur()
{
    delete label;
    delete button;
    delete slider;
    qDebug() << "~Blur()";
}

void Blur::hide()
{
    label->hide();
    button->hide();
    slider->hide();
}

void Blur::show()
{
    label->show();
    button->show();
    slider->show();
}

void Blur::click_button()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    tr("Открыть файл"),
                                                    "",
                                                    tr("Изображения (*.png *.jpg *.bmp)"));
    qDebug() << fileName;
    if( !fileName.isNull() )
    {      
        QPixmap sourceImage{fileName};
        if (!sourceImage.isNull()){
            label->setPixmap(sourceImage.scaled(label->width(),label->height(),Qt::KeepAspectRatio));
            slider->setValue(0);
            this->fileName = fileName;
        }
    }
}



void Blur::applyBlurEffect()
{

    if (!fileName.isEmpty()){
        QPixmap sourceImage{fileName};

        if (sourceImage.isNull()) // "Ошибка: файл не загружен или поврежден.
            return;
        qDebug() << "тут мы созданы! blurEffect pixmapItem";
        blurEffect = new QGraphicsBlurEffect;
        pixmapItem = new QGraphicsPixmapItem; // они самоубиваются
        pixmapItem->setPixmap(sourceImage);
        blurEffect->setBlurRadius(slider->value());
        pixmapItem->setGraphicsEffect(blurEffect);  // Применение эффекта к элементу с изображением
        QGraphicsScene scene;
        scene.addItem(pixmapItem);
        QPixmap blurredImage(sourceImage.size());
        blurredImage.fill(Qt::transparent);  // Заполнение фона прозрачным цветом
        QPainter painter(&blurredImage);
        scene.render(&painter);  // Рендеринг сцены с размытым изображением

        label->setPixmap(blurredImage.scaled(label->width(),label->height(),Qt::KeepAspectRatio));


        qDebug() << blurEffect;
        qDebug() << pixmapItem;
    }

    qDebug() << "а тут мы уже трупы!";
    qDebug() << "blurEffect" << "pixmapItem";
  //  qDebug() << blurEffect;
  //  qDebug() << pixmapItem;
/*
 * разработчик - Qt ты управляешь динамической памятью?
 * Qt - возможно...
 * разработчик - ты очищаешь память за собой ?
 * Qt - возможно...
 * разработчик - э... (_!_)
*/
}
