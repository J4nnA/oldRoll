// 拼接指令，发送出去，接收后，提取原始数据，返回
#ifndef DATAACCESS_H
#define DATAACCESS_H



#include "visa.h"
#include "visatype.h"

class Access
{
public:
    // 仪器初始化
    ViStatus deviceInit();
    // 连接设备
    ViStatus deviceConnect(ViRsrc resource);
    // 断开连接设备
    ViStatus deviceClose();

public:
    static ViRsrc resource;                         //设备连接方式及ip
private:
    static ViSession analyzer;                      //与设备的会话
    static ViSession defaultRM;                     //与资源管理器的会话
    const static int analyzerTimeout = 10000;
};

#endif // DATAACCESS_H
