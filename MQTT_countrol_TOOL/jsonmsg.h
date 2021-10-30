#ifndef JSONMSG_H
#define JSONMSG_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QDebug>

class jsonmsg
{
public:
    jsonmsg();

    int Parse_Seniverse_Now_Json(const QByteArray &message);

    void create_json_5004_msg();

    QJsonObject json_down_msg;

    struct up_head_t
    {
        int32_t dev_id;
        int32_t msg_id;
        int32_t msg_no;
        int32_t timestamp;
    }up_head;

    struct up_data_t
    {
        uint8_t Battery;
        int32_t Longitude;
        int32_t Latitude;
        int32_t Altitude;
        int32_t Env_Temperature;
        int32_t Env_Humidity;
        int32_t Env_Pressure;
        uint8_t Rainfall;
        int32_t Wind_Speed;
        int32_t Wind_Direction;
        int32_t Switch;
        uint8_t Variable_Val_0;
        uint8_t Variable_Val_1;
        uint8_t Variable_Val_2;
    }up_data;

    struct down_data_t
    {
        int32_t Switch;
        uint8_t Variable_Val_0;
        uint8_t Variable_Val_1;
        uint8_t Variable_Val_2;
    }down_data;
};

#endif // JSONMSG_H
