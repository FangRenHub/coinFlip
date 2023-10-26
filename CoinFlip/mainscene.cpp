#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setStyleSheet("MainScene{background-image:url(:/vector-frame-border-bohemian-arrow-ornament/v37-wit-34e-job129.jpg)}");
    //this->setStyleSheet("border-image:url(:/vector-frame-border-bohemian-arrow-ornament/v37-wit-34e-job129.jpg)");
    this->setWindowIcon(QIcon(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/front_1.png"));
    this->setWindowTitle("FFR的翻金币Demo");
    this->setFixedSize(400,700);

    //开始按钮
    MyPushButton *startBtn = new MyPushButton(":/realistic-coins-transparent-set-isolated-icons-with-gold-silver-bronze-colored-money-dime-items-vector-illustration/startBtn_2.png");
    startBtn->setFixedSize(startBtn->width(),startBtn->height());
    startBtn->setIconSize(QSize(200,100));
    startBtn->setParent(this);
    startBtn->move( this->width() * 0.5 - startBtn->width() * 0.5 , this->height() * 0.7);
    chooseScene = new ChooseLevelScene;

    //进入选关
    connect(startBtn,&MyPushButton::clicked,[=](){
        qDebug() << "startTest";
        startBtn->move( this->width() * 0.5 - startBtn->width() * 0.5 , this->height() * 0.7);
        startBtn->zoomDown();
        //startBtn->zoomUp();
        QTimer::singleShot(200,this,[=](){
            //设置choose场景的位置
            chooseScene->setGeometry(this->geometry());
            chooseScene->show();
            this->hide();
        });

    });

    //监听返回
    connect(chooseScene, &ChooseLevelScene::choseSceneBack, [=](){
        QTimer::singleShot(20,this,[=](){
            this->setGeometry(chooseScene->geometry());
            this->show();
            chooseScene->hide();
        });
    });

}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    QPixmap pic;
//    pic.load(":/vector-frame-border-bohemian-arrow-ornament/v37-wit-34e-job129.jpg");
//    painter.drawPixmap(0,0,this->width(),this->height(),pic);

}

