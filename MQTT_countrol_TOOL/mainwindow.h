#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMqtt/mqtt/qmqttclient.h>
#include <QDateTime>
#include <QMessageBox>
#include <QTimer>

#include "jsonmsg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void publish_msg_down();
private slots:
    void onTimeOut();

    void on_pushButton_connect_clicked(bool checked);

    void updateLogStateChange();

    void brokerDisconnected();

    void onMQTT_Received(const QByteArray &message, const QMqttTopicName &topic);

    void on_pushButton_sub_clicked();

    void on_pushButton_pub_clicked();

    void on_pushButton_SW_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_comboBox_dev_currentTextChanged(const QString &arg1);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_textEdit_recvmsg_textChanged();

private:
    QMqttClient *m_client;
    jsonmsg *json;

    QString dev_id;
    QString pub_topic;
    QString sub_topic;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
