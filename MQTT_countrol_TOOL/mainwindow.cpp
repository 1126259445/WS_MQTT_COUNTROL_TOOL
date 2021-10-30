#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_client = new QMqttClient(this);
    json = new jsonmsg();

    dev_id = ui->comboBox_dev->currentText();
    pub_topic = dev_id + "_DOWN";
    sub_topic = dev_id + "_UP";

    ui->lineEdit_host->setText("1.12.255.251");
    ui->spinBox_port->setValue(1883);
    ui->lineEdit_pub->setText(pub_topic);
    ui->lineEdit_sub->setText(sub_topic);


    /*mqtt信号槽相关*/
    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);
    connect(m_client, &QMqttClient::messageReceived, this, &MainWindow::onMQTT_Received);

    /*按键信号槽相关*/
    connect(ui->pushButton_SW_00,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_01,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_02,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_03,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_04,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_05,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_06,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_07,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_08,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));
    connect(ui->pushButton_SW_09,SIGNAL(clicked()), this, SLOT(on_pushButton_SW_clicked()));

    QTimer *pTimer = new QTimer(this);
    // 设置定时间隔
    pTimer->setInterval(10);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    // 启动定时器
    pTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*DEVid 发生变化 改变订阅和发布的topic 并端开连接*/
void MainWindow::on_comboBox_dev_currentTextChanged(const QString &arg1)
{
    dev_id = ui->comboBox_dev->currentText();
    qDebug() << dev_id <<endl;

    QString pub_topic = ui->comboBox_dev->currentText() + "_DOWN";
    QString sub_topic = ui->comboBox_dev->currentText() + "_UP";

    ui->lineEdit_pub->setText(pub_topic);
    ui->lineEdit_sub->setText(sub_topic);

    ui->lineEdit_host->setEnabled(true);
    ui->spinBox_port->setEnabled(true);
    ui->pushButton_connect->setText(tr("Connect"));
    m_client->disconnectFromHost();
}

/*连接到指定MQTT服务器*/
void MainWindow::on_pushButton_connect_clicked(bool checked)
{
    m_client->setHostname(ui->lineEdit_host->text());
    m_client->setPort(ui->spinBox_port->value());

    if (m_client->state() == QMqttClient::Disconnected) {
        m_client->connectToHost();
    } else {
        m_client->disconnectFromHost();
    }
}

/*连接状态发生改变做出相应的动作*/
void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    // ui->textEdit_recvmsg->setText(content);

    if(m_client->state() == QMqttClient::Connected)
    {
        ui->pushButton_connect->setText(tr("Disconnect"));
        ui->lineEdit_host->setEnabled(false);
        ui->spinBox_port->setEnabled(false);

        auto subscription = m_client->subscribe(ui->lineEdit_sub->text());
        if (!subscription) {
            QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
            return;
        }
    }else if(m_client->state() == QMqttClient::Disconnected)
    {
         ui->pushButton_connect->setText(tr("Connect"));
         ui->lineEdit_host->setEnabled(true);
         ui->spinBox_port->setEnabled(true);
    }
}

void MainWindow::brokerDisconnected()
{
    ui->lineEdit_host->setEnabled(true);
    ui->spinBox_port->setEnabled(true);
    ui->textEdit_recvmsg->setText(tr("Connect"));
}

void MainWindow::on_pushButton_sub_clicked()
{
    auto subscription = m_client->subscribe(ui->lineEdit_sub->text());
    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }
}

void MainWindow::on_pushButton_pub_clicked()
{
    if (m_client->publish(ui->lineEdit_pub->text(), ui->lineEdit_pubmsg->text().toUtf8()) == -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
}

void MainWindow::on_textEdit_recvmsg_textChanged()
{
    ui->textEdit_recvmsg->moveCursor(QTextCursor::End);
}


void MainWindow::onTimeOut()
{
    float Temperature = json->up_data.Env_Temperature / 10.0;
    ui->lcdNumber_Temperature->display(Temperature);
    float Humidity = json->up_data.Env_Humidity / 10.0;
    ui->lcdNumber_Humidity->display(Humidity);
    ui->lcdNumber_Press->display(json->up_data.Env_Pressure);
    float wind_speed = json->up_data.Wind_Speed / 10.0;
    ui->lcdNumber_Speed->display(wind_speed);
    float wind_direction = json->up_data.Wind_Direction / 10.0;
    ui->lcdNumber_Direction->display(wind_direction);
    ui->lcdNumber_Rain->display(json->up_data.Rainfall);

    uint32_t sw = json->up_data.Switch;
    if(sw & 1<<0)
        ui->pushButton_SW_00->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_00->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<1)
        ui->pushButton_SW_01->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_01->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<2)
        ui->pushButton_SW_02->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_02->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<3)
        ui->pushButton_SW_03->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_03->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<4)
        ui->pushButton_SW_04->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_04->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<5)
        ui->pushButton_SW_05->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_05->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<6)
        ui->pushButton_SW_06->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_06->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<7)
        ui->pushButton_SW_07->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_07->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<8)
        ui->pushButton_SW_08->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_08->setStyleSheet("background-color: rgb(175, 179, 179)");
    if(sw & 1<<9)
        ui->pushButton_SW_09->setStyleSheet("QPushButton{background:green}");
    else
        ui->pushButton_SW_09->setStyleSheet("background-color: rgb(175, 179, 179)");

    uint8_t num0 = json->up_data.Variable_Val_0;
    ui->lcdNumber_number->display(num0);
    uint8_t num1 = json->up_data.Variable_Val_1;
    ui->lcdNumber_number_2->display(num1);
    uint8_t num2 = json->up_data.Variable_Val_2;
    ui->lcdNumber_number_3->display(num2);

    static uint8_t flag = 1;
    if(flag)
    {
        flag = 0;
        ui->horizontalSlider->setValue(num0);
        ui->horizontalSlider_2->setValue(num1);
        ui->horizontalSlider_3->setValue(num2);
    }
}



/*MQTT 收到订阅的消息*/
void MainWindow::onMQTT_Received(const QByteArray &message, const QMqttTopicName &topic)
{
    const QString content = QDateTime::currentDateTime().toString()
                + QLatin1String(" Received Topic: ")
                + topic.name()
                + QLatin1String(" Message: ")
                + message
                + QLatin1Char('\n');
    ui->textEdit_recvmsg->insertPlainText(content);

    json->Parse_Seniverse_Now_Json(message);
}

/*按键消息处理MQTT的json发布数据*/
void MainWindow::on_pushButton_SW_clicked()
{
     QString btnName = QObject::sender()->objectName();
     int index = btnName.right(2).toInt();
     qDebug() << btnName << "is"<< index<< endl;

     /*上行数据和下行数据同步后与当前按键做比较*/
     json->down_data.Switch = json->up_data.Switch;
     /*赋值按键值 填充json下发数据*/
     if((json->down_data.Switch & (1<<index)) == (1<<index))
     {
        json->down_data.Switch &= ~(1<<index);
     }
     else
     {
        json->down_data.Switch |= (1<<index);
     }
     json->create_json_5004_msg();
     publish_msg_down();

     switch (index) {
     case 0:
         qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 1:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 2:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 3:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 4:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 5:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 6:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 7:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 8:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     case 9:
          qDebug() << "current button" << "is"<< index<< endl;
         break;
     default:
         break;
     }

   //  if (m_client->publish(ui->lineEdit_pub->text(), btnName.toUtf8()) == -1)
   //      QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
}




void MainWindow::publish_msg_down()
{
    QJsonDocument root_Doc;
    root_Doc.setObject(json->json_down_msg);
    QByteArray root_str = root_Doc.toJson(QJsonDocument::Compact);  //紧凑格式
    if (m_client->publish(ui->lineEdit_pub->text(),root_str) == -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
     qDebug() << "horizontalSlider_valueChanged" << value<< endl;
       /*赋值可变数据 填充json下发数据*/
     json->down_data.Variable_Val_0 = value;
     json->create_json_5004_msg();
     publish_msg_down();
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    qDebug() << "horizontalSlider_valueChanged_2" << value<< endl;
      /*赋值可变数据 填充json下发数据*/
    json->down_data.Variable_Val_1 = value;
    json->create_json_5004_msg();
    publish_msg_down();
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    qDebug() << "horizontalSlider_valueChanged_3" << value<< endl;
      /*赋值可变数据 填充json下发数据*/
    json->down_data.Variable_Val_2 = value;
    json->create_json_5004_msg();
    publish_msg_down();
}

