#include "jsonmsg.h"

jsonmsg::jsonmsg()
{

}

int jsonmsg::Parse_Seniverse_Now_Json(const QByteArray &message)
{
    QJsonParseError err_rpt;
        QJsonDocument  root_Doc = QJsonDocument::fromJson(message, &err_rpt);//字符串格式化为JSON
        if(err_rpt.error != QJsonParseError::NoError)
        {
            qDebug() << "JSON格式错误";
            return -1;
        }
        else    //JSON格式正确
        {
            QJsonObject root_Obj = root_Doc.object();
            QJsonObject head = root_Obj.value("head").toObject();
            QJsonObject data = root_Obj.value("data").toObject();

            up_head.dev_id = head.value("dev_id").toInt();
            up_head.msg_id = head.value("dev_id").toInt();
            up_head.msg_no = head.value("msg_no").toInt();
            up_head.timestamp = head.value("timestamp").toInt();

            up_data.Battery = data.value("Battery").toInt();
            up_data.Longitude = data.value("Longitude").toInt();
            up_data.Latitude = data.value("Longitude").toInt();
            up_data.Altitude = data.value("Longitude").toInt();
            up_data.Env_Temperature = data.value("Env_Temperature").toInt();
            up_data.Env_Humidity = data.value("Env_Humidity").toInt();
            up_data.Env_Pressure = data.value("Env_Pressure").toInt();
            up_data.Rainfall = data.value("Rainfall").toInt();
            up_data.Wind_Speed = data.value("Wind_Speed").toInt();
            up_data.Wind_Direction = data.value("Wind_Direction").toInt();
            up_data.Switch = data.value("Switch").toInt();
            up_data.Variable_Val_0 = data.value("Variable_Val_0").toInt();
            up_data.Variable_Val_1 = data.value("Variable_Val_1").toInt();
            up_data.Variable_Val_2 = data.value("Variable_Val_2").toInt();

            qDebug() << "JSON格式正确：\n" << root_Doc;
        }
        return 0;
}



/*
 {
  "head":{
   "dev_id": 00000,
   "msg_id": 50004,
   "msg_no": 1,
  "timestamp": 1492488028395
      },
 "data":{
     "Switch": 00000000000000000000000000000000, //这里为开关量的二进制表示0 为关 1为开 实际转换为UInt32的十进制 (实例为1号开关开其他关)
      "Variable_Val_0": 1 , //这里为一个可变长度值 （int）
       "Variable_Val_1": 1 , //这里为一个可变长度值 （int）
      "Variable_Val_2": 1 //这里为一个可变长度值 （int）
       }
   }
*/
void jsonmsg::create_json_5004_msg()
{
    QJsonObject head;
    QJsonObject data;
    QString timestamp = QString::number(QDateTime::currentMSecsSinceEpoch());
     //添加键值对，值的类型自动识别，顺序不可自定义
        head.insert("dev_id","000001");
        head.insert("msg_id",5004);
        head.insert("msg_no",1);
        head.insert("timestamp",timestamp);
     json_down_msg.insert("head",head);
        data.insert("Switch",down_data.Switch);
        data.insert("Variable_Val_0",down_data.Variable_Val_0);
        data.insert("Variable_Val_1",down_data.Variable_Val_1);
        data.insert("Variable_Val_2",down_data.Variable_Val_2);
     json_down_msg.insert("data",data);

    qDebug() << json_down_msg << endl;
}
