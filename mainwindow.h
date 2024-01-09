#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "sound_button.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void click_button(const int i);
    QPushButton* button[3];
    QWidget* widget;
    QGridLayout* layout;
    SOUND_BUTTON* sound_button;
};
#endif // MAINWINDOW_H
