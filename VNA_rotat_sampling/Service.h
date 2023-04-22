// 接收数据，转换数据，发送数据；调用底层函数，底层函数为抽象后的操作
#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <QtGlobal>
#include "visa.h"
#include "visatype.h"
#include <QDebug>
#include "DataAccess.h"


class Service
{
public:
    // 通信服务建立
    qint32 startService(QString ip);

    // 设置起始频率
    qint32 setStartFreq(double startFreq);

    // 查询起始频率
    QString queryStartFreq();
private:
    //
    Access m_access;
};

// 负责校验和保证多个设备的工作配合（目前好像是多此一举）
class Server
{
public:
    Server();
    ~Server();

    // 连接设备(传递字符串）
    qint32 connectDevice(QString ip);

    // 查询设备起始频率
    QString queryStartFreq();

private:

public:

private:
    Device m_device;        //维护一个设备（扩展可变成一个数组（但这样存在另一个问题，需要加个数目））
};

#endif // SERVICE_H
