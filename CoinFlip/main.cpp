#include "mainscene.h"

#include <QApplication>
#include "dataconfig.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScene w;
    w.show();

    //测试关卡数据
//    DataConfig config;
//    for(int i = 0; i<4 ;i++){
//        for(int j = 0; j < 4; j++){
//            qDebug() << config.mData[2][i][j];
//        }
//        qDebug() << " ";
//    }

    return a.exec();
}
