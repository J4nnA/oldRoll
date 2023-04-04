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
    QLineEdit *leDeviceId;
    QPushButton *btnConnect;
    QLabel *label;
    QPushButton *btnDisconnect;
    QGroupBox *groupBox_2;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_3;
    QPushButton *btnVnaModeSwitch;
    QGroupBox *groupBox_4;
    QLineEdit *leStartFreq;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *leStopFreq;
    QComboBox *cbStartFreqUnit;
    QComboBox *comboBox_2;
    QPushButton *btnSetStartFreq;
    QPushButton *btnQueryStopFreq;
    QPushButton *btnQueryStartFreq;
    QPushButton *btnSetStopFreq;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 751, 80));
        leDeviceId = new QLineEdit(groupBox);
        leDeviceId->setObjectName(QString::fromUtf8("leDeviceId"));
        leDeviceId->setGeometry(QRect(110, 40, 271, 27));
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
        groupBox_2->setGeometry(QRect(20, 330, 751, 231));
        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 731, 191));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 100, 751, 81));
        btnVnaModeSwitch = new QPushButton(groupBox_3);
        btnVnaModeSwitch->setObjectName(QString::fromUtf8("btnVnaModeSwitch"));
        btnVnaModeSwitch->setGeometry(QRect(20, 40, 92, 29));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 190, 741, 131));
        leStartFreq = new QLineEdit(groupBox_4);
        leStartFreq->setObjectName(QString::fromUtf8("leStartFreq"));
        leStartFreq->setGeometry(QRect(90, 40, 141, 27));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 69, 20));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 69, 20));
        leStopFreq = new QLineEdit(groupBox_4);
        leStopFreq->setObjectName(QString::fromUtf8("leStopFreq"));
        leStopFreq->setGeometry(QRect(90, 90, 141, 27));
        cbStartFreqUnit = new QComboBox(groupBox_4);
        cbStartFreqUnit->addItem(QString());
        cbStartFreqUnit->setObjectName(QString::fromUtf8("cbStartFreqUnit"));
        cbStartFreqUnit->setGeometry(QRect(250, 40, 89, 28));
        comboBox_2 = new QComboBox(groupBox_4);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(250, 90, 89, 28));
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
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

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Hz", nullptr));

        btnSetStartFreq->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        btnQueryStopFreq->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        btnQueryStartFreq->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        btnSetStopFreq->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
