#include "DataAccess.h"

ViRsrc Access::resource;
ViSession Access::analyzer;
ViSession Access::defaultRM;
SCPI_DATA_FMT Access::queryDataFmt;
SCPI_DATA_FMT Device::queryDataFmt;

/**
 * @brief Access::deviceInit
 * 已实现，于2023.4.7
 * @return
 */
//————————————————————————————————————————————————————————————————————————————————————
ViStatus Access::collectAndSaveData(const QString &fileName)
{
    ViStatus status;

    // 触发数据采集（请根据实际的 SCPI 命令进行修改）
    QString collectDataCmd = ":SENS:DATA:COLL";
    status = setCmdSend(analyzer, collectDataCmd, nullptr);
    if (status != VI_SUCCESS)
    {
        qDebug() << "DataAccess.cpp_Access::collectAndSaveData collectData error.";
        return status;
    }
    else
    {
        qDebug() << "collect success";
    }

    QString test_0_A = ":MMEM:STOR:SCR";
    QString test_0_B = "'vnaScreen.jpg'";
    status = setCmdSend(analyzer, test_0_A, test_0_B);
    //
    //QString createDirectoryCmd = ":MMEM:MDIR";
    //QString directoryPath = "\"/my_data\""; // 设置要创建的目录路径
    //status = setCmdSend(analyzer, createDirectoryCmd, directoryPath);

    /*
    // 保存
    QString saveDataCmd = ":MMEM:STOR";
    QString dataFileParam = QString("\"%1\"").arg(fileName); // 根据实际的 SCPI 命令，可能需要调整参数格式
    status = setCmdSend(analyzer, saveDataCmd, dataFileParam);
    if (status != VI_SUCCESS)
    {
        qDebug() << "DataAccess.cpp_Access::collectAndSaveData saveData error.";
        return status;
    }
    else
    {
        qDebug() << "save success";
    }*/
    return status;
}
//————————————————————————————————————————————————————————————————————————————————————
ViStatus Access::deviceInit()
{
    ViStatus status;

    // 建立默认资源管理器会话
    status = viOpenDefaultRM(&defaultRM);
    if(status == VI_SUCCESS)qDebug() << "DataAccess.cpp: openDefaultRM success.";
    else qDebug() << "DataAccess.cpp: openDefaultRM error.";
    // 建立设备连接会话
    // @paramter: 默认资源管理器会话， ip（字符串），，，会话

    // 设置默认数据返回类型
    Access::queryDataFmt =SCPI_DATA_FMT::s_datafmt_ASC;
    return status;
}

/**
 * @brief Access::deviceConnect
 * 已实现 于2023.4.7
 * @param resource
 * @return
 */
ViStatus Access::deviceConnect(ViRsrc resource)
{
    ViStatus status;

    // 会话绑定设备
    status = viOpen(defaultRM, resource, VI_NULL, VI_NULL, &analyzer);
    QString tempTest = resource;
    qDebug() << "Access::resource = " << tempTest;
    if(status == VI_SUCCESS)qDebug() << "DataAccess.cpp: open success.";
    else qDebug() << "DataAccess.cpp: open error.";
    // 对设备进行初始化
    viSetAttribute(analyzer,VI_ATTR_TMO_VALUE, 2000);
    viSetAttribute(analyzer, VI_ATTR_SEND_END_EN, VI_TRUE);
    viSetAttribute(analyzer, VI_ATTR_SUPPRESS_END_EN, VI_FALSE);
    viSetAttribute(analyzer, VI_ATTR_TERMCHAR_EN, VI_FALSE);

    // 设置数据返回类型
    status = setQueryDataFmt(Access::queryDataFmt);
    return status;
}

ViStatus Access::deviceClose()
{
    return 0;
}

ViStatus Access::startFreqSet(QString strStartFreq)
{
    ViStatus status;
    // 生成指令原料
    QString strCmd = ":SENS:FREQ:STAR";

    // 生成指令并发送，查看发送状态
    status = this->setCmdSend(analyzer, strCmd, strStartFreq);
    if(status == VI_SUCCESS)qDebug() << "DataAccess.cpp_Access::startFreqSet.setCmdSend success.";
    else qDebug() << "DataAccess.cpp_Access::startFreqSet.setCmdSend error.";
    return status;
}

ViStatus Access::startFreqQuery(ViReal64 &valHz)
{
    ViStatus status;

    // 生成指令操作码
    QString strCmd = ":SENS:FERQ:STAR?";

    // 生成缓冲区
    ViChar wrtBuf[BUFFER_SIZE];

    // 调用查询模块
    status = Access::queryCmdSend(Access::analyzer, strCmd, wrtBuf);

    // 将缓冲区数据进行提取处理
    /*
     * 待添加，待修改：仪器有多种返回数据类型，但不确定默认值，以及不确定在哪里设置
     */
    if(Access::queryDataFmt == SCPI_DATA_FMT::s_datafmt_HEX)
    {
        std::memcpy(&valHz, wrtBuf, sizeof(ViReal64));
    }
    else
    {
        QString strResult = wrtBuf;
        valHz = strResult.toDouble();
    }

    return status;
}

ViStatus Access::setQueryDataFmt(SCPI_DATA_FMT fmtType)
{
    QString cmdStr = ":FORM";
    QString dataType;
    switch(fmtType)
    {
    case SCPI_DATA_FMT::s_datafmt_ASC:
        dataType = "ASC";break;
    case SCPI_DATA_FMT::s_datafmt_HEX:
        dataType = "HEX";break;
    }
    ViStatus status = setCmdSend(Access::analyzer, cmdStr, dataType);
    if(status == VI_SUCCESS) qDebug() << "DataAccess.cpp Access::setQueryDataFmt success.";
    else qDebug() << "DataAccess.cpp Access::setQueryDataFmt error.";
    return status;
}

ViStatus Access::setCmdSend(ViSession analyzer, QString cmd, QString data)
{
    ViStatus status;
    ViUInt32 retCnt;
    ViChar wrtBuff[BUFFER_SIZE];
    QString tempStr;

    // 组合指令
    if(data == nullptr)
    {
        tempStr = cmd;
    }
    else
    {
        tempStr = cmd + " " + data;
    }

    // 转换指令格式
    QByteArray tempArray = tempStr.toLocal8Bit();

    // 写入缓冲区
    std::memcpy(wrtBuff, tempArray, BUFFER_SIZE);

    status = viWrite(analyzer, ViBuf(wrtBuff), BUFFER_SIZE, &retCnt);
    return status;
}

ViStatus Access::queryCmdSend(ViSession analyzer, QString cmd, ViChar wrtBuf[BUFFER_SIZE])
{
    ViStatus status;
    ViUInt32 retCnt;

    // 转换指令格式
    QByteArray tempArray = cmd.toLocal8Bit();

    // 写入缓冲区
    std::memcpy(wrtBuf, tempArray, BUFFER_SIZE);

    // 发送查询指令
    status = viWrite(analyzer, ViBuf(wrtBuf), BUFFER_SENDSIZE, &retCnt);
    if(status == VI_SUCCESS)qDebug() << "DataAccess.cpp_Access::queryCmdSend  sendQuery success.";
    else qDebug() << "DataAccess.cpp_Access::queryCmdSend  sendQuery error.";
    // 等待响应
    QThread::msleep(200);

    memset(wrtBuf, 0, BUFFER_SIZE);
    ViChar tempBuf[BUFFER_SIZE];
    // 接收数据
    status = viRead(analyzer, (ViBuf)tempBuf, BUFFER_SIZE, &retCnt);
    QString temp(tempBuf);
    qDebug() << temp;
    if(status == VI_SUCCESS)qDebug() << "DataAccess.cpp_Access::queryCmdSend  revQuery success.";
    else qDebug() << "DataAccess.cpp_Access::queryCmdSend  revQuery error.";
    return status;
}

Device::Device()
{
    // 对成员变量进行初始化
    this->queryDataFmt = SCPI_DATA_FMT::s_datafmt_HEX;
    ViSession status = viOpenDefaultRM(&m_defaultRM);
}

ViStatus Device::deviceInit(ViRsrc deviceIp)
{
    ViStatus status;

    status = viOpen(m_defaultRM, deviceIp, VI_NULL, VI_NULL, &m_device);
    if(status == 0)
    {
        qDebug() << "viOpen success.";
    }
    viSetAttribute(m_device, VI_ATTR_TMO_VALUE, 2000);
    viSetAttribute(m_device, VI_ATTR_SEND_END_EN, VI_TRUE);
    viSetAttribute(m_device, VI_ATTR_SUPPRESS_END_EN, VI_FALSE);
    viSetAttribute(m_device, VI_ATTR_TERMCHAR_EN, VI_FALSE);

    // 修改数据格式？
    Device::queryDataFmt = SCPI_DATA_FMT::s_datafmt_ASC;
    // 设置仪器？如何实现
    status = setQueryResultDataFormat(Device::queryDataFmt);
    if(status == 0)
    {
        qDebug() << "setQueryResultDataFormat success.";
    }
    return status;
}

ViStatus Device::queryStartSend(ViReal64 &valHz)
{
    QString operateStr = ":SENS:FREQ:STAR";
    ViChar wrtBuf[BUFFER_SIZE];
    ViStatus status = queryCmd(m_device, operateStr, wrtBuf);

    if(Device::queryDataFmt == SCPI_DATA_FMT::s_datafmt_HEX)
    {
        memcpy(&valHz,wrtBuf,sizeof(ViReal64));
    }
    else
    {
        QString strResult = wrtBuf;
        valHz = strResult.toDouble();
    }
    return status;
}

ViStatus Device::setCmd(ViSession device, QString operateStr, QString dataStr)
{
    ViStatus status;
    ViUInt32 retCnt;
    ViChar wrtBuff[BUFFER_SIZE];
    QString cmd;
    // 组合指令（未加校验版）
    cmd = operateStr + " " + dataStr;

    // 转换指令格式
    QByteArray tempArray = cmd.toLocal8Bit();

    // 写入缓冲区
    std::memcpy(wrtBuff, tempArray, BUFFER_SIZE);

    // 发送指令
    status = viWrite(m_device, ViBuf(wrtBuff), BUFFER_SIZE, &retCnt);
    return status;
}

ViStatus Device::queryCmd(ViSession device, QString operateStr, ViChar wrtBuf[])
{
    ViStatus status;
    ViUInt32 retCnt;

    QString cmd = operateStr + "?";

    // 转换指令格式
    QByteArray tempArray = cmd.toLocal8Bit();

    // 写入缓冲区
    std::memcpy(wrtBuf, tempArray, BUFFER_SIZE);

    // 发送指令
    status = viWrite(m_device, (ViBuf)wrtBuf, BUFFER_SENDSIZE, &retCnt);
    QThread::msleep(50);
    memset(wrtBuf, 0, BUFFER_SIZE);
    status = viRead (m_device,(ViBuf)wrtBuf ,BUFFER_SIZE , &retCnt);

    return status;
}

ViStatus Device::setQueryResultDataFormat(SCPI_DATA_FMT nVal)
{
    ViChar pChar[]    = ":FORM";
    ViChar pVal_ASC[] = "ASC";
    ViChar pVal_HEX[] = "HEX";
    ViChar* pVal = nullptr;
    switch (nVal)
    {
    case SCPI_DATA_FMT::s_datafmt_ASC:
        pVal = pVal_ASC;
        break;
    case SCPI_DATA_FMT::s_datafmt_HEX:
        pVal = pVal_HEX;
        break;
    }
    ViStatus result = setCmd(m_device,pChar,pVal);
    if(VI_SUCCESS == result)
    {
        Device::queryDataFmt = nVal;
    }
    return result;
}
