#include "DataAccess.h"

ViRsrc Access::resource;
ViSession Access::analyzer;
ViSession Access::defaultRM;


ViStatus Access::deviceInit()
{
    ViStatus status;

    // 建立默认资源管理器会话
    status = viOpenDefaultRM(&defaultRM);

    // 建立设备连接会话
    // @paramter: 默认资源管理器会话， ip（字符串），，，会话
    status = viOpen(defaultRM, resource, VI_NULL, VI_NULL, &analyzer);

    // 对设备进行初始化
    viSetAttribute(analyzer,VI_ATTR_TMO_VALUE, 2000);
    viSetAttribute(analyzer, VI_ATTR_SEND_END_EN, VI_TRUE);
    viSetAttribute(analyzer, VI_ATTR_SUPPRESS_END_EN, VI_FALSE);
    viSetAttribute(analyzer, VI_ATTR_TERMCHAR_EN, VI_FALSE);
    return 0;
}

ViStatus Access::deviceConnect(ViRsrc resource)
{
    return 0;
}

ViStatus Access::deviceClose()
{
    return 0;
}
