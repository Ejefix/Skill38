#ifndef HTML_EDITOR_H
#define HTML_EDITOR_H

#include <QHBoxLayout>
#include <QWebEngineView>
#include <QPlainTextEdit>


class HTML_editor : public QHBoxLayout
{
public:
    HTML_editor(QWidget *parent = nullptr);
    ~HTML_editor();
    void hide();
    void show();
private:
    static void start_text(QPlainTextEdit *text);
    QPlainTextEdit *text;
    QWebEngineView* web;
};

#endif // HTML_EDITOR_H
