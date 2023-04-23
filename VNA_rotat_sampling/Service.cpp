#include "Service.h"


qint32 Service::startService(QString ip)
{
    qDebug() << "Service::startService: ip :" << ip;
    // 转换类型
    QByteArray byteArray = ip.toLocal8Bit();
    ViRsrc rsc = byteArray.data();

    // 生成下层对象
    Access::resource = rsc;
    ViStatus resp;
    // 初始化设备
    resp = m_access.deviceInit();
    if(resp == VI_SUCCESS)qDebug() <<"Service.cpp: deviceInit success.";
    else qDebug() << "Service.cpp: deviceInit error";
    // 建立连接
    resp = m_access.deviceConnect(rsc);

    return resp;
}

qint32 Service::setStartFreq(double startFreq)
{
    // 转换成字符串
    QString strStartFreq = QString::number(startFreq);


    // 调用下层功能
    return m_access.startFreqSet(strStartFreq);
}



QString Service::queryStartFreq()
{
    // 将下层返回数据进行处理
    ViReal64 result;

    ViStatus status = m_access.startFreqQuery(result);
    if(status == VI_SUCCESS)qDebug() << "Service.cpp Service::queryStartFreq success.";
    else qDebug() << "Service.cpp Service::queryStartFreq error.";
    // 返回
    QString strRet;
    strRet.sprintf("%.0f", result);
    return strRet;
}

Server::Server()
{

}

qint32 Server::connectDevice(QString ip)
{
    // 转换指令格式
    QByteArray tempIp = ip.toLocal8Bit();
    ViRsrc resource = tempIp.data();
    m_device.deviceInit(resource);

    return 0;
}

QString Server::queryStartFreq()
{
    QString str;
    ViReal64 value = 0;
    m_device.queryStartSend(value);

    str.sprintf("%.0f",value);

    return str;
}
