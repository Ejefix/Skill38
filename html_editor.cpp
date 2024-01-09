#include "html_editor.h"


HTML_editor::HTML_editor(QWidget *parent):QHBoxLayout(parent),text{new QPlainTextEdit},web{new QWebEngineView}
{

    addWidget(text,1);
    text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    addWidget(web,1);
    web->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    connect(text, &QPlainTextEdit::textChanged, this,[this]() {
        web->setHtml(text->toPlainText());
    });
    start_text(text);

}

HTML_editor::~HTML_editor()
{
    qDebug() << "~HTML_editor()";
    delete web;
    delete text;
}

void HTML_editor::hide()
{
    web->hide();
    text->hide();
}

void HTML_editor::show()
{
    web->show();
    text->show();
}

void HTML_editor::start_text(QPlainTextEdit *text)
{

    const QString htmlContent = R"(
<h5 fr-original-style="" style="font-size: 1.25rem; margin-top: 0px; margin-bottom: 0.5rem;
color: inherit; line-height: 1.2; font-weight: 500; box-sizing: border-box;">Что оценивается</h5>
<ul fr-original-style="" style="margin-top: 0px; margin-bottom: 1rem;
box-sizing: border-box; font-size: 16px; line-height: 22px;">
    <li fr-original-style="" style="box-sizing: border-box;">
Приложение отображает одно окно, в котором есть два текстовых виджета.&nbsp;</li>
    <li fr-original-style="" style="box-sizing: border-box;">
Каждый виджет занимает свою половину экрана.&nbsp;</li>
    <li fr-original-style="" style="box-sizing: border-box;">
Левый виджет содержит текстовое представление HTML-документа, правый — нарисованную веб-страницу.</li>
    <li fr-original-style="" style="box-sizing: border-box;">
При изменении исходного кода страницы в левом виджете представление в правом сразу меняется.</li>
</ul>
)";

    text->setPlainText(htmlContent);
}
