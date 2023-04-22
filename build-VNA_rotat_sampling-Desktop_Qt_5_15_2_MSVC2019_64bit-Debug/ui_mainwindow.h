/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *leDeviceIp;
    QPushButton *btnConnect;
    QLabel *label;
    QPushButton *btnDisconnect;
    QGroupBox *groupBox_2;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_3;
    QPushButton *btnVnaModeSwitch;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *cbStartFreqUnit;
    QPushButton *btnSetStartFreq;
    QPushButton *btnQueryStopFreq;
    QPushButton *btnQueryStartFreq;
    QPushButton *btnSetStopFreq;
    QDoubleSpinBox *dsbStartFreq;
    QDoubleSpinBox *dsbStopFreq;
    QComboBox *cbStopFreqUnit;
    QPushButton *btnCore;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(780, 647);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 751, 80));
        leDeviceIp = new QLineEdit(groupBox);
        leDeviceIp->setObjectName(QString::fromUtf8("leDeviceIp"));
        leDeviceIp->setGeometry(QRect(110, 40, 271, 27));
        btnConnect = new QPushButton(groupBox);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(450, 40, 92, 29));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 69, 20));
        btnDisconnect = new QPushButton(groupBox);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(590, 40, 92, 29));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 380, 751, 221));
        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 731, 181));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 100, 751, 81));
        btnVnaModeSwitch = new QPushButton(groupBox_3);
        btnVnaModeSwitch->setObjectName(QString::fromUtf8("btnVnaModeSwitch"));
        btnVnaModeSwitch->setGeometry(QRect(20, 40, 92, 29));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 190, 741, 131));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 69, 20));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 69, 20));
        cbStartFreqUnit = new QComboBox(groupBox_4);
        cbStartFreqUnit->addItem(QString());
        cbStartFreqUnit->addItem(QString());
        cbStartFreqUnit->addItem(QString());
        cbStartFreqUnit->addItem(QString());
        cbStartFreqUnit->setObjectName(QString::fromUtf8("cbStartFreqUnit"));
        cbStartFreqUnit->setGeometry(QRect(250, 40, 89, 28));
        btnSetStartFreq = new QPushButton(groupBox_4);
        btnSetStartFreq->setObjectName(QString::fromUtf8("btnSetStartFreq"));
        btnSetStartFreq->setGeometry(QRect(380, 40, 92, 29));
        btnQueryStopFreq = new QPushButton(groupBox_4);
        btnQueryStopFreq->setObjectName(QString::fromUtf8("btnQueryStopFreq"));
        btnQueryStopFreq->setGeometry(QRect(520, 90, 92, 29));
        btnQueryStartFreq = new QPushButton(groupBox_4);
        btnQueryStartFreq->setObjectName(QString::fromUtf8("btnQueryStartFreq"));
        btnQueryStartFreq->setGeometry(QRect(520, 40, 92, 29));
        btnSetStopFreq = new QPushButton(groupBox_4);
        btnSetStopFreq->setObjectName(QString::fromUtf8("btnSetStopFreq"));
        btnSetStopFreq->setGeometry(QRect(380, 90, 92, 29));
        dsbStartFreq = new QDoubleSpinBox(groupBox_4);
        dsbStartFreq->setObjectName(QString::fromUtf8("dsbStartFreq"));
        dsbStartFreq->setGeometry(QRect(110, 40, 121, 28));
        dsbStopFreq = new QDoubleSpinBox(groupBox_4);
        dsbStopFreq->setObjectName(QString::fromUtf8("dsbStopFreq"));
        dsbStopFreq->setGeometry(QRect(110, 90, 121, 28));
        cbStopFreqUnit = new QComboBox(groupBox_4);
        cbStopFreqUnit->addItem(QString());
        cbStopFreqUnit->addItem(QString());
        cbStopFreqUnit->addItem(QString());
        cbStopFreqUnit->addItem(QString());
        cbStopFreqUnit->setObjectName(QString::fromUtf8("cbStopFreqUnit"));
        cbStopFreqUnit->setGeometry(QRect(250, 90, 89, 28));
        btnCore = new QPushButton(centralwidget);
        btnCore->setObjectName(QString::fromUtf8("btnCore"));
        btnCore->setGeometry(QRect(650, 340, 92, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 780, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207ip", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\344\277\241\346\201\257", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\265\213\351\207\217\346\250\241\345\274\217\345\210\207\346\215\242", nullptr));
        btnVnaModeSwitch->setText(QCoreApplication::translate("MainWindow", "VNA", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\351\242\221\347\216\207\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\265\267\345\247\213\351\242\221\347\216\207", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\273\210\346\255\242\351\242\221\347\216\207", nullptr));
        cbStartFreqUnit->setItemText(0, QCoreApplication::translate("MainWindow", "Hz", nullptr));
        cbStartFreqUnit->setItemText(1, QCoreApplication::translate("MainWindow", "kHz", nullptr));
        cbStartFreqUnit->setItemText(2, QCoreApplication::translate("MainWindow", "MHz", nullptr));
        cbStartFreqUnit->setItemText(3, QCoreApplication::translate("MainWindow", "GHz", nullptr));

        btnSetStartFreq->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        btnQueryStopFreq->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        btnQueryStartFreq->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        btnSetStopFreq->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        cbStopFreqUnit->setItemText(0, QCoreApplication::translate("MainWindow", "Hz", nullptr));
        cbStopFreqUnit->setItemText(1, QCoreApplication::translate("MainWindow", "kHz", nullptr));
        cbStopFreqUnit->setItemText(2, QCoreApplication::translate("MainWindow", "MHz", nullptr));
        cbStopFreqUnit->setItemText(3, QCoreApplication::translate("MainWindow", "GHz", nullptr));

        btnCore->setText(QCoreApplication::translate("MainWindow", "\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
