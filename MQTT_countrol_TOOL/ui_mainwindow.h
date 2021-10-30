/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber_Temperature;
    QLabel *label_3;
    QLCDNumber *lcdNumber_Humidity;
    QLabel *label_4;
    QLabel *label_5;
    QLCDNumber *lcdNumber_Press;
    QLCDNumber *lcdNumber_Speed;
    QLabel *label_6;
    QLCDNumber *lcdNumber_Direction;
    QLabel *label_7;
    QPushButton *pushButton_SW_00;
    QLabel *label_8;
    QLCDNumber *lcdNumber_Rain;
    QPushButton *pushButton_SW_01;
    QPushButton *pushButton_SW_02;
    QPushButton *pushButton_SW_03;
    QPushButton *pushButton_SW_04;
    QPushButton *pushButton_SW_05;
    QPushButton *pushButton_SW_06;
    QPushButton *pushButton_SW_07;
    QPushButton *pushButton_SW_08;
    QPushButton *pushButton_SW_09;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QComboBox *comboBox_dev;
    QHBoxLayout *horizontalLayout;
    QLabel *label_host;
    QLineEdit *lineEdit_host;
    QLabel *label_port;
    QSpinBox *spinBox_port;
    QPushButton *pushButton_connect;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_sub;
    QPushButton *pushButton_sub;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_pub;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_pubmsg;
    QPushButton *pushButton_pub;
    QTextEdit *textEdit_recvmsg;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QLCDNumber *lcdNumber_number_3;
    QSlider *horizontalSlider_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLCDNumber *lcdNumber_number_2;
    QSlider *horizontalSlider_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QLCDNumber *lcdNumber_number;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1125, 649);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(175, 179, 179);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber_Temperature = new QLCDNumber(centralWidget);
        lcdNumber_Temperature->setObjectName(QStringLiteral("lcdNumber_Temperature"));
        lcdNumber_Temperature->setGeometry(QRect(680, 20, 141, 51));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(570, 30, 81, 41));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(20);
        label_3->setFont(font);
        lcdNumber_Humidity = new QLCDNumber(centralWidget);
        lcdNumber_Humidity->setObjectName(QStringLiteral("lcdNumber_Humidity"));
        lcdNumber_Humidity->setGeometry(QRect(680, 100, 141, 51));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(570, 110, 81, 41));
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(570, 190, 81, 41));
        label_5->setFont(font);
        lcdNumber_Press = new QLCDNumber(centralWidget);
        lcdNumber_Press->setObjectName(QStringLiteral("lcdNumber_Press"));
        lcdNumber_Press->setGeometry(QRect(680, 180, 141, 51));
        lcdNumber_Speed = new QLCDNumber(centralWidget);
        lcdNumber_Speed->setObjectName(QStringLiteral("lcdNumber_Speed"));
        lcdNumber_Speed->setGeometry(QRect(950, 10, 141, 51));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(840, 20, 81, 41));
        label_6->setFont(font);
        lcdNumber_Direction = new QLCDNumber(centralWidget);
        lcdNumber_Direction->setObjectName(QStringLiteral("lcdNumber_Direction"));
        lcdNumber_Direction->setGeometry(QRect(950, 100, 141, 51));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(840, 110, 81, 41));
        label_7->setFont(font);
        pushButton_SW_00 = new QPushButton(centralWidget);
        pushButton_SW_00->setObjectName(QStringLiteral("pushButton_SW_00"));
        pushButton_SW_00->setGeometry(QRect(972, 507, 91, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_SW_00->setFont(font1);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(840, 190, 81, 41));
        label_8->setFont(font);
        lcdNumber_Rain = new QLCDNumber(centralWidget);
        lcdNumber_Rain->setObjectName(QStringLiteral("lcdNumber_Rain"));
        lcdNumber_Rain->setGeometry(QRect(950, 180, 141, 51));
        pushButton_SW_01 = new QPushButton(centralWidget);
        pushButton_SW_01->setObjectName(QStringLiteral("pushButton_SW_01"));
        pushButton_SW_01->setGeometry(QRect(860, 510, 91, 41));
        pushButton_SW_01->setFont(font1);
        pushButton_SW_01->setAutoFillBackground(false);
        pushButton_SW_02 = new QPushButton(centralWidget);
        pushButton_SW_02->setObjectName(QStringLiteral("pushButton_SW_02"));
        pushButton_SW_02->setGeometry(QRect(750, 510, 91, 41));
        pushButton_SW_02->setFont(font1);
        pushButton_SW_02->setAutoFillBackground(false);
        pushButton_SW_03 = new QPushButton(centralWidget);
        pushButton_SW_03->setObjectName(QStringLiteral("pushButton_SW_03"));
        pushButton_SW_03->setGeometry(QRect(640, 510, 91, 41));
        pushButton_SW_03->setFont(font1);
        pushButton_SW_03->setAutoFillBackground(false);
        pushButton_SW_04 = new QPushButton(centralWidget);
        pushButton_SW_04->setObjectName(QStringLiteral("pushButton_SW_04"));
        pushButton_SW_04->setGeometry(QRect(530, 510, 91, 41));
        pushButton_SW_04->setFont(font1);
        pushButton_SW_04->setAutoFillBackground(false);
        pushButton_SW_05 = new QPushButton(centralWidget);
        pushButton_SW_05->setObjectName(QStringLiteral("pushButton_SW_05"));
        pushButton_SW_05->setGeometry(QRect(970, 450, 91, 41));
        pushButton_SW_05->setFont(font1);
        pushButton_SW_05->setAutoFillBackground(false);
        pushButton_SW_06 = new QPushButton(centralWidget);
        pushButton_SW_06->setObjectName(QStringLiteral("pushButton_SW_06"));
        pushButton_SW_06->setGeometry(QRect(860, 450, 91, 41));
        pushButton_SW_06->setFont(font1);
        pushButton_SW_06->setAutoFillBackground(false);
        pushButton_SW_07 = new QPushButton(centralWidget);
        pushButton_SW_07->setObjectName(QStringLiteral("pushButton_SW_07"));
        pushButton_SW_07->setGeometry(QRect(750, 450, 91, 41));
        pushButton_SW_07->setFont(font1);
        pushButton_SW_07->setAutoFillBackground(false);
        pushButton_SW_08 = new QPushButton(centralWidget);
        pushButton_SW_08->setObjectName(QStringLiteral("pushButton_SW_08"));
        pushButton_SW_08->setGeometry(QRect(640, 450, 91, 41));
        pushButton_SW_08->setFont(font1);
        pushButton_SW_08->setAutoFillBackground(false);
        pushButton_SW_09 = new QPushButton(centralWidget);
        pushButton_SW_09->setObjectName(QStringLiteral("pushButton_SW_09"));
        pushButton_SW_09->setGeometry(QRect(530, 450, 91, 41));
        pushButton_SW_09->setFont(font1);
        pushButton_SW_09->setAutoFillBackground(false);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 431, 581));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        comboBox_dev = new QComboBox(layoutWidget);
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->setObjectName(QStringLiteral("comboBox_dev"));

        horizontalLayout_5->addWidget(comboBox_dev);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_host = new QLabel(layoutWidget);
        label_host->setObjectName(QStringLiteral("label_host"));

        horizontalLayout->addWidget(label_host);

        lineEdit_host = new QLineEdit(layoutWidget);
        lineEdit_host->setObjectName(QStringLiteral("lineEdit_host"));

        horizontalLayout->addWidget(lineEdit_host);

        label_port = new QLabel(layoutWidget);
        label_port->setObjectName(QStringLiteral("label_port"));

        horizontalLayout->addWidget(label_port);

        spinBox_port = new QSpinBox(layoutWidget);
        spinBox_port->setObjectName(QStringLiteral("spinBox_port"));
        spinBox_port->setMaximumSize(QSize(71, 22));
        spinBox_port->setMaximum(200000);

        horizontalLayout->addWidget(spinBox_port);

        pushButton_connect = new QPushButton(layoutWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout->addWidget(pushButton_connect);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_sub = new QLineEdit(layoutWidget);
        lineEdit_sub->setObjectName(QStringLiteral("lineEdit_sub"));

        horizontalLayout_2->addWidget(lineEdit_sub);

        pushButton_sub = new QPushButton(layoutWidget);
        pushButton_sub->setObjectName(QStringLiteral("pushButton_sub"));

        horizontalLayout_2->addWidget(pushButton_sub);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_pub = new QLineEdit(layoutWidget);
        lineEdit_pub->setObjectName(QStringLiteral("lineEdit_pub"));

        horizontalLayout_3->addWidget(lineEdit_pub);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit_pubmsg = new QLineEdit(layoutWidget);
        lineEdit_pubmsg->setObjectName(QStringLiteral("lineEdit_pubmsg"));

        horizontalLayout_4->addWidget(lineEdit_pubmsg);

        pushButton_pub = new QPushButton(layoutWidget);
        pushButton_pub->setObjectName(QStringLiteral("pushButton_pub"));

        horizontalLayout_4->addWidget(pushButton_pub);


        verticalLayout->addLayout(horizontalLayout_4);

        textEdit_recvmsg = new QTextEdit(layoutWidget);
        textEdit_recvmsg->setObjectName(QStringLiteral("textEdit_recvmsg"));

        verticalLayout->addWidget(textEdit_recvmsg);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(490, 370, 581, 41));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        lcdNumber_number_3 = new QLCDNumber(layoutWidget1);
        lcdNumber_number_3->setObjectName(QStringLiteral("lcdNumber_number_3"));
        lcdNumber_number_3->setStyleSheet(QStringLiteral("color: rgb(0, 255, 127);"));

        horizontalLayout_6->addWidget(lcdNumber_number_3);

        horizontalSlider_3 = new QSlider(layoutWidget1);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(horizontalSlider_3);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(490, 320, 581, 41));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        lcdNumber_number_2 = new QLCDNumber(layoutWidget2);
        lcdNumber_number_2->setObjectName(QStringLiteral("lcdNumber_number_2"));
        lcdNumber_number_2->setStyleSheet(QStringLiteral("color: rgb(0, 255, 127);"));

        horizontalLayout_7->addWidget(lcdNumber_number_2);

        horizontalSlider_2 = new QSlider(layoutWidget2);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider_2);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(490, 270, 581, 41));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        lcdNumber_number = new QLCDNumber(layoutWidget3);
        lcdNumber_number->setObjectName(QStringLiteral("lcdNumber_number"));
        lcdNumber_number->setStyleSheet(QStringLiteral("color: rgb(0, 255, 0);"));

        horizontalLayout_8->addWidget(lcdNumber_number);

        horizontalSlider = new QSlider(layoutWidget3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1125, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\271\277\345\272\246", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\260\224\345\216\213", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\351\243\216\351\200\237", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\351\243\216\345\220\221", nullptr));
        pushButton_SW_00->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2631", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\351\233\250\351\207\217", nullptr));
        pushButton_SW_01->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2632", nullptr));
        pushButton_SW_02->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2633", nullptr));
        pushButton_SW_03->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2634", nullptr));
        pushButton_SW_04->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2635", nullptr));
        pushButton_SW_05->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2636", nullptr));
        pushButton_SW_06->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2637", nullptr));
        pushButton_SW_07->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2638", nullptr));
        pushButton_SW_08->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\2639", nullptr));
        pushButton_SW_09->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\26310", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\256\276\345\244\207", nullptr));
        comboBox_dev->setItemText(0, QApplication::translate("MainWindow", "DEV00001", nullptr));
        comboBox_dev->setItemText(1, QApplication::translate("MainWindow", "DEV00002", nullptr));
        comboBox_dev->setItemText(2, QApplication::translate("MainWindow", "DEV00003", nullptr));
        comboBox_dev->setItemText(3, QApplication::translate("MainWindow", "DEV00004", nullptr));
        comboBox_dev->setItemText(4, QApplication::translate("MainWindow", "DEV00005", nullptr));
        comboBox_dev->setItemText(5, QApplication::translate("MainWindow", "DEV00006", nullptr));
        comboBox_dev->setItemText(6, QApplication::translate("MainWindow", "DEV00007", nullptr));
        comboBox_dev->setItemText(7, QApplication::translate("MainWindow", "DEV00008", nullptr));
        comboBox_dev->setItemText(8, QApplication::translate("MainWindow", "DEV00009", nullptr));
        comboBox_dev->setItemText(9, QApplication::translate("MainWindow", "DEV00010", nullptr));

        label_host->setText(QApplication::translate("MainWindow", "host", nullptr));
        lineEdit_host->setText(QString());
        label_port->setText(QApplication::translate("MainWindow", "port", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "connect", nullptr));
        label->setText(QApplication::translate("MainWindow", "sub Topic", nullptr));
        pushButton_sub->setText(QApplication::translate("MainWindow", "\350\256\242\351\230\205", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "pub_Topic", nullptr));
        pushButton_pub->setText(QApplication::translate("MainWindow", "\345\217\221\345\270\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
