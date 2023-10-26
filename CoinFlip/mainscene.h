#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPicture>
#include <QPaintEvent>
#include <QPainter>
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QTimer>
#include <QDebug>
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //背景图
    void paintEvent(QPaintEvent *);
    //关卡界面
    ChooseLevelScene *chooseScene = nullptr;

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
