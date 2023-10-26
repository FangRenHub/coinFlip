#include "dataconfig.h"
#include <QDebug>

DataConfig::DataConfig(QObject *parent) : QObject(parent)
{

    int array1[4][4] = {{1,1,1,1},
                        {1,1,0,1},
                        {1,0,0,0},
                        {1,1,0,1}};
    addMission(1,array1);

    int array2[4][4] = {{1,0,1,1},
                        {0,0,1,1},
                        {1,1,0,0},
                        {1,1,0,1}};
    addMission(2,array2);

    int array3[4][4] = {{0,0,0,0},
                        {0,1,1,0},
                        {0,1,1,0},
                        {0,0,0,0}};
    addMission(3,array3);

    int array4[4][4] = {{0,1,1,1},
                        {1,0,0,1},
                        {1,0,1,1},
                        {1,1,1,1}};
    addMission(4,array4);

    int array5[4][4] = {{1, 0, 0, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {1, 0, 0, 1}};
    addMission(5,array5);

    int array6[4][4] = {{1, 0, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}};
    addMission(6,array6);

    int array7[4][4] = {{0, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0}};
    addMission(7,array7);

    int array8[4][4] = {{0, 1, 0, 1},
                        {1, 0, 0, 0},
                        {0, 0, 0, 1},
                        {1, 0, 1, 0}};
    addMission(8,array8);

    int array9[4][4] = {{1, 0, 1, 0},
                        {1, 0, 1, 0},
                        {0, 0, 1, 0},
                        {1, 0, 0, 1}};
    addMission(9,array9);

    int array10[4][4] = {{1, 0, 1, 1},
                         {1, 1, 0, 0},
                         {0, 0, 1, 1},
                         {1, 1, 0, 1}};
    addMission(10,array10);

    int array11[4][4] = {{0, 1, 1, 0},
                         {1, 0, 0, 1},
                         {1, 0, 0, 1},
                         {0, 1, 1, 0}};
    addMission(11,array11);

    int array12[4][4] = {{0, 1, 1, 0},
                         {0, 1, 1, 0},
                         {1, 0, 0, 1},
                         {1, 0, 0, 1}};
    addMission(12,array12);

    int array13[4][4] = {{0, 1, 1, 0},
                         {0, 0, 0, 0},
                         {1, 1, 1, 1},
                         {0, 0, 0, 0}};
    addMission(13,array13);

    int array14[4][4] = {{1, 0, 1, 1},
                         {0, 1, 0, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 1}};
    addMission(14,array14);

    int array15[4][4] = {{0, 1, 0, 1},
                         {1, 0, 0, 0},
                         {1, 0, 0, 0},
                         {0, 1, 0, 1}};
    addMission(15,array15);

    int array16[4][4] = {{0, 1, 1, 0},
                         {1, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}};
    addMission(16,array16);

    int array17[4][4] = {{0, 1, 1, 1},
                         {0, 1, 0, 0},
                         {0, 0, 1, 0},
                         {1, 1, 1, 0}};
    addMission(17,array17);

    int array18[4][4] = {{0, 0, 0, 1},
                         {0, 0, 1, 0},
                         {0, 1, 0, 0},
                         {1, 0, 0, 0}};
    addMission(18,array18);

    int array19[4][4] = {{0, 1, 0, 0},
                         {0, 1, 1, 0},
                         {0, 0, 1, 1},
                         {0, 0, 0, 0}};
    addMission(19,array19);

    int array20[4][4] = {{0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0}};
    addMission(20,array20);
}

void DataConfig::addMission(int missionNum, int arr[][4])
{
    QVector< QVector<int>> v;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 4; j++)
        {
            v1.push_back(arr[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(missionNum,v);
}
