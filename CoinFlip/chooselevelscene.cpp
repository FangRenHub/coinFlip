#include "chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(400,700);
    this->setWindowTitle("FFR的翻金币Demo");
    this->setStyleSheet("ChooseLevelScene{background-image:url(:/vector-frame-border-bohemian-arrow-ornament/v37-wit-34e-job129.jpg)}");
    //this->setStyleSheet("border-image:url(:/vector-frame-border-bohemian-arrow-ornament/v37-wit-34e-job129.jpg)");
    this->setWindowIcon(QIcon(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/front_1.png"));

    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/exit.png"
                                             ,":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/exit_2.png");
    backBtn->setParent(this);
    backBtn->move( this->width() - backBtn->width(), this->height() - backBtn->height() * 1.8);
    connect(backBtn,&MyPushButton::clicked,[=](){
        qDebug() << "test";
        emit this->choseSceneBack();
    });


    //选关界面
    for (int i = 0; i < 20 ; i++){
        MyPushButton *menuBtn = new MyPushButton(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/Back_1.png");
        menuBtn->setFixedSize(60,60);
        menuBtn->setIconSize(QSize(60,60));
        menuBtn->setParent(this);
        menuBtn->move( i%4 * 80 + 50, i/4 * 80 + 160);

        //选择关卡并进入
        connect(menuBtn, &MyPushButton::clicked, [=](){
           QString str = QString("您选择的是第%1关").arg(i + 1);
           qDebug() << str;
           play = new PlayScene(i + 1,this);
           play->setGeometry(this->geometry());
           play->show();
           this->hide();

        });

        //设置关卡数字并穿透
        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(60,60);
        label->setText(QString::number(i+1));
        label->move(i%4 * 80 + 50, i/4 * 80 + 160);
        label->setAlignment(Qt::AlignCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    QPixmap pic;
//    pic.load(":/vector-frame-border-bohemian-arrow-ornament/v37-wit-34e-job129.jpg");
//    painter.drawPixmap(0,0,this->width(),this->height(),pic);
}
