# WS_MQTT_COUNTROL_TOOL
使用QT5开发WS设备的环境监测及控制客户端

## qmqtt库的引入使用
在qt5中使用qtmqtt库qtmqtt库源码下载链接  
链接：https://pan.baidu.com/s/1TyqbLX5x17mwhAX-OJiorw 提取码：i6wwperl安装下载链接。  
链接：https://pan.baidu.com/s/1xQTMjChlr2mSothEHbMRzA 提取码：jqxs下载qtmqtt库源码，打开qtmqtt文件夹中的qtmqtt.pro工程文件。  
1.使用release编译，期间出现perl错误，下载perl安装  
2. 编译完成后将qtmqtt/src/mqtt拷贝到Qt/5.13/mingw53_32/include（qt安装路径），并删除mqtt目录下的所有非头文件在qt安装路径  D:\Qt\Qt5.10.0\5.10.0\mingw53_32\include目录下新建文件夹QtMqtt。将第二步中的mqtt文件夹复制到这个路径下复制完mqtt文件夹的路径为 C:\Qt\5.12.3\mingw73_64\include\QtMqtt\mqtt  
3.将mqtt编译出来的lib目录下的2个dll和两个.a和2个prl拷贝到Qt/5.13/mingw53_32/lib  
4.将mqtt编译出来的bin目录下的2个dll拷贝到Qt/5.13/mingw53_32/bin  
5.将mqtt编译出来的mkspecs\modules下的pri文件拷贝到Qt/5.13/mingw53_32/mkspecs/modules  
qtmqtt库的使用：  
在项目工程文件中添加：QT += mqtt  
在程序文件中：#include <QtMqtt/QtMqtt>  

或者参考下边是网络上的qmqtt下载安装教程（供参考）
其中项目需要使用到qmqtt的库 以zip的形式打包在文件中
库的安装方法参考 https://blog.csdn.net/luoyayun361/article/details/104671603

该PC软件与WS开头的各种物联网设备端通过MQTT通讯
通讯协议使用XC_Link 具体如下
[TOC]
# XC_Link
## 协议格式概览

所有的消息体不论是请求消息还是响应消息都应该由消息头，数据，额外数据三部分组成。
```
{
    "head":{ 
     //消息头 
      }, 
    "data":{
      //数据 
        }, 
    "extern":{
       //额外数据
    }
}
```
## 消息头具体格式如下
```
"head":{
    "dev_id": 1,        //设备ID号
    "msg_id":50001,         //消息号
    "msg_no": 1,            //消息序号
    "timestamp" 1492488028395 // 时间戳
}
```
消息头说明如下

| 名称 |解释  | 类型 |
| --- | --- | --- |
|dev_id|设备的ID号用来区分是哪个设备|int|
| msg_id | 消息编号,消息接收方根据该编号区分消息类型 | int |
| msg_no |消息序号.发送方序号依次递增,接收方响应序号与请求 序号相同  | int |
| timestamp |UNIX 时间戳, 单位毫秒| long |

消息编号说明

| 消息编号 |响应编号 |消息内容 |
| --- | --- | --- |
| 50001 | 60001 | 开机上报数据 |
| 50002 | 60002 | 数据链心跳 |
| 50003 | 60003 | 上行数据包 |
| 50004 | 60004 | 下行数据包 |
## 具体消息内容实例
以下个命令字段根据实际使用场景和设备进行选择使用
### 1.开机上报数据 （50001）
```
{
    "head":{
         "dev_id": 1,
        "msg_id": 50001,
        "msg_no": 1,
        "timestamp":  1492488028395  
    },
    "data":{
        "Battery":55,
        "Longitude": 1142354321,        //经度 *10^7 后传输 
        "Latitude":225342178,       //纬度 * 10^7 后传输
        "Altitude":900      //海拔高度 （m）
    }
}
```
### 2.开机上报响应 （60001）
```
{
"head":{
        "dev_id": 0,
        "msg_id": 60001,
        "msg_no": 1,
        "timestamp":  1492488028495 
    },
    "data":{
        "Code":1001//验证结果 1001 OK    1002 ERR
    }
}
```
### 3.心跳  （50002）
```
{
    "head":{
        "dev_id":1,
        "msg_id":50002,
        "msg_no":1,
        "timestamp":1492488028495
    },
    "data":{
        "Count":1,  //收到平台响应，无人机就继续发送原数字，未收到响应的情况下次发送 在原数字上加 1
    }
}
```
### 4.心跳响应 （60002）
```
{    
"head":{
        "dev_id":0,
        "msg_id":60002,
        "msg_no":1,
        "timestamp":1492488028495
    },    "data":{
        "Count":1,      //对齐上行心跳包 count
        "Code":1001   //验证结果 1001 OK    1002 ERR
    }
}
```
### 5.数据实时上报 （50003）

设备实时上报信息，频率 1HZ（自定义）。Extra 中所有内容均为可选项， 即 extra 中内容可为空，data 中所有内容中均为必填项。
```
{ "head":{
    "dev_id": 1, 
    "msg_id": 50003, 
    "msg_no": 1, 
    "timestamp": 1492488028395 
    },
 "data":{ 
    "Battery":55,                             // 55%
    "Longitude": 1142354321,           //经度*10^7后传输
    "Latitude":225342178,                //维度*10^7后传输
    "Altitude":930,                          //93.0m  保留一位小数*10后传输 （米）
    "Env_Temperature":263,              //26.3C  保留一位小数*10后传输
    "Env_Humidity": 870,                  // 87.0%RH   保留一位小数*10后传输
    "Env_Pressure":1013,               // 大气压hpa
    "Rainfall":12,                            //当天0时以来累计雨量 mm
    "Wind_Speed": 30,                     //3.0m/s     保留一位小数*10后传输
    "Wind_Direction": 450,                //45.0度  保留一位小数*10后传输 （正北为0度顺时针计算）
    "Switch":1,                               // 开关值32位状态 0关 1开 （UInt32）
    "Variable_Val_0": 23,                  //可变数据 0-255  （uint8）
    "Variable_Val_1": 0,                   //可变数据 0-255  （uint8）
    "Variable_Val_2": 0                    //可变数据 0-255  （uint8）
    }
}
```
### 6下行数据包   （50004）
下行数据包为平台及其他控制客户端向指定设备发出的控制命令
```
{
    "head":{
         "dev_id": 0,
        "msg_id": 50004,
        "msg_no": 1,
        "timestamp":  1492488028395 
    },
    "data":{
        “Switch”: 1,   //00000000000000000000000000000001 这里为开关量的二进制表示0 为关 1为开 实际转换为UInt32的十进制 (实例为1号开关开其他关) 
          "Variable_Val_0": 1 ,    //这里为一个可变长度值 （int）
          "Variable_Val_1": 1  ,   //这里为一个可变长度值 （int）
          "Variable_Val_2": 1     //这里为一个可变长度值 （int）
    }
}
```
