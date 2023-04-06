#include "Service.h"


qint32 Service::startService(QString ip)
{
    // 转换类型
    QByteArray byteArray = ip.toLocal8Bit();
    ViRsrc rsc = byteArray.data();

    // 生成下层对象
    Access acs;

    ViStatus resp;
    // 初始化设备
    resp = acs.deviceInit();

    // 建立连接
    resp = acs.deviceConnect(rsc);

    return 0;
}
