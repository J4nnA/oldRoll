#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void printToBrowser(QString retStr);

private slots:
    void on_btnConnect_clicked();

    void on_btnSetStartFreq_clicked();

    void on_btnQueryStartFreq_clicked();

    void on_btnCore_clicked();

private:
    Ui::MainWindow *ui;
    Service m_service;
    Server m_server;
};
#endif // MAINWINDOW_H
