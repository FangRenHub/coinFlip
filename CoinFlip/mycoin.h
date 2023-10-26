#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QIcon>
#include <QPainter>
#include <QSound>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
   // explicit MyCoin(QWidget *parent = nullptr);

    MyCoin(QString btnIma);

    int posX;
    int posY;
    bool flag;

    //改变硬币
    void changeFlag();
    QTimer *timer1;
    QTimer *timer2;
    int coinNum1 = 2;
    int coinNum2 = 7;

signals:

};

#endif // MYCOIN_H
