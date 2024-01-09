#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),button{new QPushButton("38.1"),new QPushButton("38.2"),new QPushButton("38.3")},
    widget{new QWidget}, layout{new QGridLayout},sound_button{new SOUND_BUTTON}
{
    setMinimumSize(300,300);

    setCentralWidget(widget);
    widget->setLayout(layout);
    layout->setAlignment(Qt::AlignBottom);

    for(int i{}; i < 3;++i)
    {
        layout->addWidget(button[i],1,i);
        connect(button[i],&QPushButton::clicked,this,[this,i](){ click_button(i);});
    }
    layout->addWidget(sound_button,0,0,1,3);
    sound_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}

MainWindow::~MainWindow()
{
    delete widget; // так же убил кнопки и layout
}

void MainWindow::click_button(const int i)
{
    qDebug() << "click" << i;

    if (i == 0)
        sound_button->show();
    if (i == 1)
        sound_button->hide();
    if (i == 2)
        sound_button->hide();
}

