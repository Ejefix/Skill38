#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <blur.h>
#include "html_editor.h"
#include "sound_button.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void click_button(const int i);
    void resizeEvent(QResizeEvent *event) override ;
    QPushButton* button[3];
    QWidget* widget;
    QGridLayout* layout;
    SOUND_BUTTON* sound_button;
    HTML_editor * html_edit;
    Blur * blur;
};
#endif // MAINWINDOW_H
