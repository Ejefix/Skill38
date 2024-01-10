#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),button{new QPushButton("38.1"),new QPushButton("38.2"),new QPushButton("38.3")},
    widget{new QWidget}, layout{new QGridLayout},sound_button{new SOUND_BUTTON},html_edit{new HTML_editor},
    blur{new Blur}
{
    setMinimumSize(300,300);
    setCentralWidget(widget);
    widget->setLayout(layout);


    for(int i{}; i < 3;++i)
    {
        layout->addWidget(button[i],3,i);
        connect(button[i],&QPushButton::clicked,this,[this,i](){ click_button(i);});
    }
    layout->addWidget(sound_button,0,0,1,3);
    layout->addLayout(html_edit,1,0,1,3);
    layout->addLayout( blur,2,0,1,3);
    layout->setAlignment(Qt::AlignBottom);
    sound_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    blur->hide();
    html_edit->hide();


}

MainWindow::~MainWindow()
{
    delete widget; // убивает всё

}

void MainWindow::click_button(const int i)
{
    qDebug() << "click" << i;

    if (i == 0)
    {
        blur->hide();
        html_edit->hide();
        sound_button->show();
    }
    if (i == 1)
    {
        blur->hide();
        sound_button->hide();
        html_edit->show();
    }
    if (i == 2)
    {
        sound_button->hide();
        html_edit->hide();
        blur->show();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    blur->applyBlurEffect();

}

