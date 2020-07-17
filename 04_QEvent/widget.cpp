#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timeId = this->startTimer(1000);//以毫秒为单位  每隔1s触发一次定时器

    this->timeId2 = this->startTimer(500);//0.5秒触发一次
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< (char)event->key();

    if(event->key() == Qt::Key_A)
    {
        qDebug()<< "Qt::Key_A";
    }
}

void Widget::timerEvent(QTimerEvent *e)
{

    if(e->timerId() == this->timeId){
        static int sec = 0;
        ui->label->setText(QString("<center><h1>计时器1 :%1</h1></center>").arg(sec++));

        if(sec == 5)
        {
            //停止定时器
            this->killTimer(this->timeId);
        }
    }
    else if(e->timerId() == this->timeId2){
        static int sec = 0;
        ui->label_2->setText(QString("<center><h1>计时器2 :%1</h1></center>").arg(sec++));

    }

}





