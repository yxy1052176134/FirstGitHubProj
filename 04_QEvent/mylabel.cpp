#include "mylabel.h"
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    this->setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();

    QString text;
    if(ev->button() == Qt::LeftButton){
        text = QString("<center><h1>左键按下坐标: (%1,%2)</h1></center>").arg(i).arg(j);
    }else if(ev->button() == Qt::RightButton){
        text = QString("<center><h1>右键按下坐标: (%1,%2)</h1></center>").arg(i).arg(j);
    }else{
        text = QString("<center><h1>其他按键按下坐标: (%1,%2)</h1></center>").arg(i).arg(j);
    }

    this->setText(text);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>鼠标离开: (%1,%2)</h1></center>").arg(ev->x()).arg(ev->y());

    this->setText(text);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>鼠标正在移动: (%1,%2)</h1></center>").arg(ev->x()).arg(ev->y());

    this->setText(text);
}

void MyLabel::enterEvent(QEvent *e)
{
    QString text = QString("<center><h1>鼠标进入窗口</h1></center>");
    this->setText(text);
}

void MyLabel::leaveEvent(QEvent *e)
{
    QString text = QString("<center><h1>鼠标离开窗口</h1></center>");
    this->setText(text);
}






