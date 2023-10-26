#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include "mypushbutton.h"
#include <QLabel>
#include "playscene.h"
#include <QPushButton>
#include <QTimer>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

    PlayScene *play = nullptr;
    //PlayScene *PlayScene = nullptr;

signals:
    void choseSceneBack();

};

#endif // CHOOSELEVELSCENE_H
