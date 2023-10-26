#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include "mypushbutton.h"
#include <QLabel>
#include <QFont>
#include <QPixmap>
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QWidget>
#include <QSound>
#include <QThread>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNum,QWidget *choise);
    int levelIndex;
    void paintEvent(QPaintEvent *);

    int gameArray[4][4];

    MyCoin *coinBtn[4][4];

    bool iswin = false;

signals:

};

#endif // PLAYSCENE_H
