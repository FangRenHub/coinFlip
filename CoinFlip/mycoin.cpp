#include "mycoin.h"

MyCoin::MyCoin(QString btnIma)
{
    QPixmap pix;
    bool ret = pix.load(btnIma);
    if(!ret)
    {
        QString str = QString("图片加载失败 %1").arg(btnIma);
        qDebug() << str;
        return;
    }
    this->setFixedSize(60,60);
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(60,60));



    //金币反转动画
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1, &QTimer::timeout,[=](){
        QPixmap pix;
        QString coinDrs;

        if( this->coinNum1 < 8){
            coinDrs = QString(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/front_%1.png")
                    .arg(this->coinNum1);
            this->coinNum1 += 1;
        }
        else{
            coinDrs = QString(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/Back_%1.png")
                    .arg(this->coinNum2);
            this->coinNum2 -= 1;
        }
        pix.load(coinDrs);
        //            this->setFixedSize(60,60);
        //            this->setStyleSheet("QPushButton{border:0px}");
        //            this->setIconSize(QSize(60,60));
        this->setIcon(pix);
        //翻完，停止
        if( coinNum2 <= 0)
        {
            //防止点击过快图片与正反属性不符
            pix.load(QString(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/Back_1.png"));
            this->setIcon(pix);
            coinNum1 = 2;
            coinNum2 = 7;
            this->timer1->stop();
        }
    });

    connect(timer2, &QTimer::timeout,[=](){
        QPixmap pix;
        QString coinDrs;

        if( this->coinNum1 < 8){
            coinDrs = QString(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/Back_%1.png")
                    .arg(this->coinNum1);
            this->coinNum1 += 1;
        }
        else{
            coinDrs = QString(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/front_%1.png")
                    .arg(this->coinNum2);
            this->coinNum2 -= 1;
        }
        pix.load(coinDrs);
        //            this->setFixedSize(60,60);
        //            this->setStyleSheet("QPushButton{border:0px}");
        //            this->setIconSize(QSize(60,60));
        this->setIcon(pix);
        //翻完，停止
        if( coinNum2 <= 0)
        {
            //防止点击过快图片与正反属性不符
            pix.load(QString(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/front_1.png"));
            this->setIcon(pix);
            coinNum1 = 2;
            coinNum2 = 7;
            this->timer2->stop();
        }
    });
}

void MyCoin::changeFlag()
{
    if(!timer1->isActive() && !timer2->isActive() )
    {
        if(flag)
        {
            timer1->start(8);
        }
        else
        {
            timer2->start(8);
        }
        flag = !flag;
    }

}
