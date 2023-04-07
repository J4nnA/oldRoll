// 从上一层获取数据组合（可能添加一些部分），传递下一层； 接收下层传来数据，识别后，产生不同响应给上层
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printToBrowser(QString retStr)
{
    ui->textBrowser->append(retStr);
}


void MainWindow::on_btnConnect_clicked()
{

    // 获取ui中对应数据
    QString str = "TCPIP0::" + ui->leDeviceIp->text() + "::5000::SOCKET";

    // 调用下层功能，等待返回状态
    qint32 ret;
    Service service;
    ret = service.startService(str);

    //根据返回状态，进行不同操作_目前只是打印
    printToBrowser(QString::number(ret));

}

