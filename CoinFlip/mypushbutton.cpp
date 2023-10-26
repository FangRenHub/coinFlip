#include "mypushbutton.h"

//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImgPath);
    if (!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }

    //设置图片固定大小(画框大小)
    this->setFixedSize( pix.width(),pix.height() );
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图片大小（图片大小）
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyPushButton::zoomUp()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(100);
    animation->setStartValue(QVariant(QRect(this->x(),this->y()+5,this->width(),this->height())));
    animation->setEndValue(QVariant(QRect(this->x(),this->y(),this->width(),this->height())));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::zoomDown()
{
    static QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(50);
    animation->setStartValue(QVariant(QRect(this->x(),this->y(),this->width(),this->height())));
    animation->setEndValue(QVariant(QRect(this->x(),this->y()+5,this->width(),this->height())));
    animation->setStartValue(QVariant(QRect(this->x(),this->y()+5,this->width(),this->height())));
    animation->setEndValue(QVariant(QRect(this->x(),this->y(),this->width(),this->height())));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if (this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(pressImgPath);
        if (!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }
        //设置图片固定大小(画框大小)
        this->setFixedSize( pix.width(),pix.height() );
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        qDebug() << pix.height();
        //设置图片大小（图片大小）
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{

    if (this->normalImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(normalImgPath);
        if (!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }

        //设置图片固定大小(画框大小)
        this->setFixedSize( pix.width(),pix.height() );
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        qDebug() << "松开加载图片测试";
        //设置图片大小（图片大小）
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
    QPushButton::mouseReleaseEvent(e);
}



