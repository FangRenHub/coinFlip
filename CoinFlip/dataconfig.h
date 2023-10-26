#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>
#include <QDebug>

class DataConfig : public QObject
{
    Q_OBJECT
public:
    explicit DataConfig(QObject *parent = nullptr);

    //关卡数据
    QMap<int, QVector< QVector<int> > > mData;

private:
    void addMission(int missionNum, int arr[][4]);

signals:

};

#endif // DATACONFIG_H
