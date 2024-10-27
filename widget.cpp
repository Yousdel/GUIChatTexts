#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    chatTexts = new ConcreteGUIChatTexts();

    ui->textEdit->clear();
}

Widget::~Widget()
{
    delete chatTexts;
    delete ui;
}

//enviar
void Widget::on_pushButton_clicked()
{
    if (ui->user->text().isEmpty() ||
            ui->lineEdit->text().isEmpty()) return;

    chatTexts->addText(
                ui->user->text()+": "+
                ui->lineEdit->text(),1);
    //poner en el LAbel en forma de HTML-----------------

    ui->textEdit->setText(chatTexts->getHTML());
}

//visto
void Widget::on_pushButton_2_clicked()
{
    chatTexts->quitNewMsgsMark();
        //poner en el LAbel en forma de HTML-----------------
    ui->textEdit->setText(chatTexts->getHTML());
}
