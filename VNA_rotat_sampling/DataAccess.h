// 拼接指令，发送出去，接收后，提取原始数据，返回
#ifndef DATAACCESS_H
#define DATAACCESS_H

#define BUFFER_SIZE        1024    //缓存大小     /* File I/O buffer size */
#define BUFFER_SENDSIZE    64
#define SIZE_PER_READ      2048  //每次读取的最大长度
#define MAX_POINT_NUM      1600

#include <QDebug>
#include <QString>
#include <QThread>
#include "visa.h"
#include "visatype.h"

/*
 * 数据传输类型
 *
 */
enum class SCPI_DATA_FMT
{
    s_datafmt_ASC = 0,
    s_datafmt_HEX,
};

/**
 * @brief The Access class
 */
class Access
{
//——————————————————————————————————————————————————————————————————————————————————
public:
    ViStatus collectAndSaveData(const QString& fileName);
//——————————————————————————————————————————————————————————————————————————————————
public:
    // 仪器初始化
    ViStatus deviceInit();
    // 连接设备
    ViStatus deviceConnect(ViRsrc resource);
    // 断开连接设备
    ViStatus deviceClose();
    // 设置起始频率
    ViStatus startFreqSet(QString strStartFreq);
    // 查询起始频率
    ViStatus startFreqQuery(ViReal64 &valHz);
private:
    // 设置数据返回类型
    ViStatus setQueryDataFmt(SCPI_DATA_FMT fmtType);
    // 发送设置指令
    ViStatus setCmdSend(ViSession analyzer, QString cmd, QString data);
    // 发送查询指令
    ViStatus queryCmdSend(ViSession analyzer, QString cmd, ViChar wrtBuf[BUFFER_SIZE]);

public:
    static ViRsrc resource;                         //设备连接方式及ip
    static ViSession analyzer;                      //与设备的会话
    static ViSession defaultRM;                     //与资源管理器的会话
private:
    const static int analyzerTimeout = 10000;
    static SCPI_DATA_FMT queryDataFmt;
};

class Device
{
public:
    Device();
    ~Device();

    // 设备连接与初始化
    ViStatus deviceInit();

    // 查询起始频率
    ViStatus queryStartSend(ViReal64 &valHz);   //参数为返回值（字符串）

private:
    // 发送设置指令
    ViStatus setCmd(ViSession device, QString operateStr, QString dataStr); //设备，操作码，数据码
    // 查询设置指令
    ViStatus queryCmd(ViSession device, QString operateStr, ViChar wrtBuf[BUFFER_SIZE]);  //无操作码，多了个装返回值的字符数组

public:

    ViSession m_device;                 // 设备会话
    ViSession m_defaultRM;              // 默认资源管理器会话

private:
    const static int TIMEOUT = 10000;
    static SCPI_DATA_FMT queryDataFmt;
};

#endif // DATAACCESS_H
