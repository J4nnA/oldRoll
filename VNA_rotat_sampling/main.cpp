#include "mainwindow.h"

#include <QApplication>
//#define TEST

#include <iostream>
#include "DataAccess.h"


int main(int argc, char *argv[])
{

#ifndef TEST
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
#endif
#ifdef TEST
    Service service;
    QString str = "TCPIP0::169.254.227.100::5000::SOCKET";
    // 建立连接
    qint32 status = service.startService(str);
    std::cout << "connect status: " << status << std::endl;

    // 采集数据
    QString fileName = "test_data_file";

    Access access;
    access.collectAndSaveData(fileName);

    std::cout << "test" << std::endl;

    return 0;
#endif
}
