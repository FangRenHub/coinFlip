#include "playscene.h"

PlayScene::PlayScene(int levelNum,QWidget *choise)
{
    qDebug() << QString("进入了第%1关").arg(levelNum);
    this->levelIndex = levelNum;

    this->setStyleSheet("PlayScene{background-image:url(:/vector-frame-border-bohemian-arrow-ornament/v37-wit-34e-job129.jpg)}");
    this->setFixedSize(400,700);
    this->setWindowTitle("FFR的翻金币Demo");

    //音效


    //返回按钮
    this->setWindowIcon(QIcon(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/front_1.png"));

    MyPushButton *backBtn = new MyPushButton(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/exit.png"
                                             ,":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/exit_2.png");
    backBtn->setParent(this);
    backBtn->move( this->width() - backBtn->width() * 1, this->height() - backBtn->height() * 1.8);
    connect(backBtn,&MyPushButton::clicked,[=](){
        qDebug() << "主界面返回test";
        //emit this->playSceneBack();
        choise->setGeometry(this->geometry());
        choise->show();
        delete this;
    });

    //下一关按钮
    this->setWindowIcon(QIcon(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/front_1.png"));

    MyPushButton *nextBtn = new MyPushButton(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/next.png"
                                             ,":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/next_2.png");
    nextBtn->setParent(this);
    nextBtn->move( this->width() - nextBtn->width() * 1, this->height() - nextBtn->height() * 3.2);
    connect(nextBtn,&MyPushButton::clicked,[=](){
        qDebug() << "下一关test";
        if(levelNum == 20){
            choise->setGeometry(this->geometry());
            choise->show();
            delete this;
        }
        else{
            PlayScene *play = new PlayScene(levelIndex + 1,choise);
            play->setGeometry(this->geometry());
            play->show();
            delete this;
        }
    });



    //左下角提示
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    label->setText(QString("Leavel:%1").arg(this->levelIndex));
    label->setGeometry(40, this->height() - 100, 120, 50);

    //胜利图片
    QLabel *winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/pass2.png");
    winLabel->setParent(this);
    winLabel->setPixmap(tmpPix);
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->move(this->width() * 0.55,-tmpPix.height());


    //初始化关卡数组
    DataConfig config;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }


    //创建金币
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            //创建金币背景
            QLabel *CBLabel = new QLabel;
            CBLabel->setGeometry(0,0,70,70);
            CBLabel->setStyleSheet("QLabel{background-color:rgba(100,100,100,0.4);border-radius: 15px;}");
            CBLabel->setParent(this);
            CBLabel->move(60 + i*70, 200+j*70);


            //创建金币
            QString coinLocal;
            if(this->gameArray[i][j] == 1){
                coinLocal = ":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/front_1.png";
            }
            else{
                coinLocal = ":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/Back_1.png";
            }
            MyCoin *coin = new MyCoin(coinLocal);
            coin->setParent(this);
            coin->move(65 + i*70, 205+j*70);

            //给金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];

            //把金币对象放到二维数组中
            coinBtn[i][j] = coin;

            //点击金币反转

            connect(coin, &MyCoin::clicked, [=](){
                if(!coin->timer1->isActive() && !coin->timer2->isActive() &&
//                   !coinBtn[i][j + 1]->timer1->isActive() && !coinBtn[i][j + 1]->timer2->isActive() &&
//                   !coinBtn[i][j - 1]->timer1->isActive() && !coinBtn[i][j - 1]->timer2->isActive() &&
//                   !coinBtn[i - 1][j]->timer1->isActive() && !coinBtn[i - 1][j]->timer2->isActive() &&
//                   !coinBtn[i + 1][j]->timer1->isActive() && !coinBtn[i + 1][j]->timer2->isActive() &&
                        !iswin)
                {

                    qDebug() << iswin;
                    coin->changeFlag();

                    //coin->flag = !coin->flag;
                    qDebug() << QString("X = %1, Y = %2") .arg(i).arg(j);

                    QTimer::singleShot(100,this,[=](){
                        //周围金币反转下侧
                        if(coin->posY != 3)
                        {
                            coinBtn[i][j + 1]->changeFlag();
                            //coinBtn[i][j + 1]->flag = !coinBtn[i][j + 1]->flag;
                        }
                        //周围金币反转上侧
                        if(coin->posY != 0)
                        {
                            coinBtn[i][j - 1]->changeFlag();
                            //coinBtn[i][j - 1]->flag = !coinBtn[i][j - 1]->flag;
                        }
                        //周围金币反转左侧
                        if(coin->posX != 0)
                        {
                            coinBtn[i - 1][j]->changeFlag();
                            //coinBtn[i - 1][j]->flag = !coinBtn[i - 1][j]->flag;
                        }
                        //周围金币反转右侧
                        if(coin->posX != 3)
                        {
                            coinBtn[i + 1][j]->changeFlag();
                            //coinBtn[i + 1][j]->flag = !coinBtn[i + 1][j]->flag;
                        }
                    });

                    //判断是否胜利
                    QTimer::singleShot(150,this,[=](){
                        iswin = true;
                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < 4; j++)
                            {
                                if(!coinBtn[i][j]->flag)
                                {
                                    iswin = false;
                                    i = 4;
                                    j = 4;
                                }
                            }
                        }
                        //成功窗口弹出
                        if(iswin){
                            QPropertyAnimation *animation = new QPropertyAnimation(winLabel,"geometry");
                            animation->setDuration(500);
                            animation->setStartValue(QVariant(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height())));
                            animation->setEndValue(QVariant(QRect(winLabel->x(),winLabel->y()+255,winLabel->width(),winLabel->height())));
                            animation->setEasingCurve(QEasingCurve::OutBounce);
                            animation->start();
                            winLabel->raise();
                        }

                    });
                }

            });
        }
    }
}

void PlayScene::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    QPixmap pic;
//    pic.load(":/vector-frame-border-bohemian-arrow-ornament/v37-wit-34e-job129.jpg");
//    qDebug() << "paint";
//    painter.drawPixmap(0,0,this->width(),this->height(),pic);
}

