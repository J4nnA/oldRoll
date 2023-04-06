// 接收数据，转换数据，发送数据；调用底层函数，底层函数为抽象后的操作
#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <QtGlobal>
#include "visa.h"
#include "visatype.h"
#include "DataAccess.h"

class Service
{
public:
    // 通信服务建立
    qint32 startService(QString ip);
private:
    //
};

#endif // SERVICE_H
