# 毕业设计

[目录](#联网模块)

- [运行环境](#运行环境)
- [【ESP32学习】联网模块](#esp32学习联网模块)
  - [ESP8266-01S上传数据到OneNet](#esp8266-01s上传数据到onenet)
    - [收藏的一些资料](#收藏的一些资料)
    - [最终的操作结果](#最终的操作结果)
  - [ESP32\&\&ESP8266-12E连接ONeNet参考资料](#esp32esp8266-12e连接onenet参考资料)
    - [ONeNet云平台报错： {"protocol":"MQTT","offline\_time":"2024-07-15 16:01:49.977","offline\_reason":"CloseDueToProtoError"}怎么解决？](#onenet云平台报错-protocolmqttoffline_time2024-07-15-160149977offline_reasoncloseduetoprotoerror怎么解决)
  - [APP连接ONeNet](#app连接onenet)
    - [json数据解析步骤](#json数据解析步骤)
  - [STM32+电脑(模拟ESP32)+ESP8266通信](#stm32电脑模拟esp32esp8266通信)
  - [设备热点配网技术——WIFIManager](#设备热点配网技术wifimanager)
    - [报错：error: 'wifi\_country\_t' does not name a type const wifi\_country\_t WM\_COUNTRY\_US{"US",1,11,WIFI\_COUNTRY\_POLICY\_AUTO};](#报错error-wifi_country_t-does-not-name-a-type-const-wifi_country_t-wm_country_usus111wifi_country_policy_auto)
  - [通信过程中遇到的问题](#通信过程中遇到的问题)
  - [这一部分所用到的资料下载地址](#这一部分所用到的资料下载地址)
  - [【实验】SPIFFS文件系统的使用](#实验spiffs文件系统的使用)
  - [【实验】TCP/UDP通信实验](#实验tcpudp通信实验)
- [【STM32F4学习】摄像头](#stm32f4学习摄像头)
  - [参考资料](#参考资料)
- [STM32F4工程代码](#stm32f4工程代码)
- [【服务器】NGINX](#服务器nginx)
  - [在Linux中搭建NGINX服务器](#在linux中搭建nginx服务器)
  - [TCP/IP协议](#tcpip协议)
  - [\[知识储备\]](#知识储备)
  - [NGINX架构](#nginx架构)
    - [NGINX中master的工作原理](#nginx中master的工作原理)
  - [nginx处理HTTP请求的过程](#nginx处理http请求的过程)
  - [安装NGINX](#安装nginx)
- [【服务器】Tomcat](#服务器tomcat)
- [【服务器】ZLMedaikit流媒体服务器](#服务器zlmedaikit流媒体服务器)
- [【第三方库】FFmpeg媒体流转码工具](#第三方库ffmpeg媒体流转码工具)
- [【深度学习】飞桨paddlepaddle实战](#深度学习飞桨paddlepaddle实战)
  - [X-CUDE—AI在线课程](#x-cudeai在线课程)
  - [相关论文参考](#相关论文参考)
- [【机器学习】HMM模型（隐马尔科夫列）](#机器学习hmm模型隐马尔科夫列)
  - [相关论文参考](#相关论文参考-1)
  - [导入库](#导入库)
- [【音视频学习】](#音视频学习)
  - [H.264编码](#h264编码)
  - [安卓音视频实战编程](#安卓音视频实战编程)
  - [YUV](#yuv)
  - [RTMP协议所在所在的网络层结构](#rtmp协议所在所在的网络层结构)
  - [【第三方库】LIBRTMP](#第三方库librtmp)
  - [【工具】类似安卓虚拟机：Total Control](#工具类似安卓虚拟机total-control)
  - [采集音频数据工具](#采集音频数据工具)
  - [视频采集工具---MediaProjection](#视频采集工具---mediaprojection)
- [【安卓APP制作】](#安卓app制作)
  - [安卓的两种登录方式](#安卓的两种登录方式)
  - [安卓中集成第三方库进行登录](#安卓中集成第三方库进行登录)
  - [安卓显示ONENet提供的可视化链接](#安卓显示onenet提供的可视化链接)
- [硬件系统](#硬件系统)

## 运行环境

## 【ESP32学习】联网模块

### ESP8266-01S上传数据到OneNet

[参考视频](https://www.bilibili.com/video/BV1jS421A7Bk/?spm_id_from=333.337.search-card.all.click&vd_source=8b3841f9fc62479f11b65d83945326a7)

1.进入OneNet创建产品和设备（具体步骤待补充）

2.复制产品和设备的详细信息（备份）

目的是为了方便使用AT指令以及代码编写。

```c
设备名称(clientlD) : test
产品ID (username) : F1AVyfXw7l

password: version=2018-10-31&res=products%2FF1AVyfXw71%2Fdevices%
2Ftest&et=2810313321&method=md5&sign=EfJtPPxHwMX6iWWf3YksbA%3D%3D.urI:mqtts.heclouds.com

端口号:1883

订阅: $sys/F1AVyfXw7I/test/thing/property/post/reply发布: $sys/F1AVyfXw7l/test/thing/property/post

设备密钥: cjFZSWRwUGNrazdRR2d6eTJ4Tm9YNXN5bTNuMGpMTIE=access key: vclTl19loOn7mcfdtT39l1eRfVffM6FfH8U/U3HhUQc=

res:products/F1AVyfXw7l/devices/test
et:时间戳
```

#### 收藏的一些资料

[OneNet云平台](https://open.iot.10086.cn/console/product/own)
![OneNet云平台](image-2.png)

[2.时间戳](https://www.beijing-time.org/shijianchuo/)
![时间戳](image.png)

[OneNet文档中心](https://open.iot.10086.cn/doc/v5/develop/detail/639)
![OneNet文档中心](image-1.png)

#### 最终的操作结果

![结果](image-3.png)

### ESP32&&ESP8266-12E连接ONeNet参考资料

- [云平台调试错误码](https://open.iot.10086.cn/doc/v5/fuse/detail/1007)
- [设备之间数据交换实战项目](https://open.iot.10086.cn/doc/v5/fuse/detail/922)
- [wifi.h库](https://github.com/arduino-libraries/WiFi)
- [SCND文章](https://blog.csdn.net/qq_40700822/article/details/116640694)

代码部分唯一不同的是引用的库函数不同，

ESP8266使用的是

```c
#include <ESP8266WiFi.h>

```

ESP32使用的是

```c
#include <WiFi.h>
```

在使用时需要注意引用的库函数，如果库函数不匹配，可能会导致编译失败，这部分的代码以放在附件中。

- **ESP-12EConnectONenet**是ESP8266-12E连接ONeNet的代码；
- **ESP32ConnectONenet** 是ESP8266-12E连接ONeNet的代码。

**注意：**我提供的代码是以onejson格式上传的，而不是数据流的格式。在云平台创建产品时需要注意这点，当然代码里博主写的就是以数据流格式上传，如果你用原来博主写的，那么创建产品时就选数据流。

-----------------------------------------------------------

上面的代码只能实现数据上传，并不能实现命令控制，下面就介绍如何实现命令控制。
主要修改的地方是callback函数，当拿到topic的时候要解析拿到一段ID，具体可以看[官方的资料](https://open.iot.10086.cn/doc/v5/fuse/detail/922),里面有提到命令下发的操作。
![alt text](image-4.png)

#### ONeNet云平台报错： {"protocol":"MQTT","offline_time":"2024-07-15 16:01:49.977","offline_reason":"CloseDueToProtoError"}怎么解决？

这个错误是协议格式不对，也就是用的topic不正确，通过下面的案例对这个作说明。

当我们在云平台下发命令的时候，在`callback`函数里使用`Serial.println(topic);`会打印订阅的topic，格式为:

```c
$sys/584938/onenet_mqtt_dev1/cmd/request/c5a7e27e-05bb-41eb-972b-abce424ade8e
```

callback函数如下：

```c
/********************************************************************************
函数：callback
功能：接收ONeNet传回的信息
返回值：无
参数：
    topic是消息的主题，
    payload是消息的有效载荷（数据部分），
    length是payload的长度
*********************************************************************************/
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.println("message rev:");
  Serial.println(topic);                    // 打印订阅的topic
  const char* lastSlash = strrchr(topic, '/');
  if (lastSlash != NULL) {
    
    const char* cmdId = lastSlash + 1;      // 命令ID位于最后一个'/'之后
    msgid = String(cmdId);                  //将命令ID复制给msgid，msgid定义为全局变量
  }
  Serial.println(msgid);                    // 打印拿到的ID

  if (strstr(topic, ONENET_GET_CAM_REQUEST)) //ONENET_GET_CAM_REQUEST="$sys/{产品ID}/{设备名}/cmd/request/"
  {
    DynamicJsonDocument doc(100);
    DeserializationError error = deserializeJson(doc, payload);
    if (error)
    {
      Serial.println("parse json failed");
      return;
    }
    JsonObject setAlinkMsgObj = doc.as<JsonObject>();
    serializeJsonPretty(setAlinkMsgObj, Serial);
    String cam = setAlinkMsgObj["cam"].as<String>();
    Serial.println("@"+cam);                //取出下发的命令并在前面加@

    char RESPONSE_TOPIC[100];
    sprintf(RESPONSE_TOPIC, "$sys/{产品ID}/{设备名}/cmd/response/%s",msgid.c_str());
    client.publish(RESPONSE_TOPIC, "OK");   // 向平台响应OK
  }else {
    Serial.println("GET_CAM faile!");
  }
}
```

这份代码是根据一位博主的代码改的（[博主文章链接](https://blog.csdn.net/qq_40700822/article/details/116640694)），取出后面的ID用如下代码即可

```c
 const char* lastSlash = strrchr(topic, '/');
  if (lastSlash != NULL) {
    
    const char* cmdId = lastSlash + 1;      // 命令ID位于最后一个'/'之后
    msgid = String(cmdId);                  //将命令ID复制给msgid，msgid定义为全局变量
  }
  Serial.println(msgid);                    // 打印拿到的ID
```

而这个时候我们需要响应这个命令用的是

```c
$sys/584938/onenet_mqtt_dev1/cmd/response/c5a7e27e-05bb-41eb-972b-abce424ade8e
```

一个是request，一个是response，所以在拿到下发命令的topic后要取出后面跟着的ID，然后再重新拼接在`$sys/584938/onenet_mqtt_dev1/cmd/response/`后面，然后用这个拼接的topic发送响应数据给云平台。

这个时候就能在云平台那看到类似如下信息：

![alt text](image-5.png)

一般格式错误返回的错误码是15，原因就是格式有问题。使用如下的格式上传响应都可能有问题：

1.$sys/584938/onenet_mqtt_dev1/cmd/response/

2.$sys/584938/onenet_mqtt_dev1/cmd/response/+

3.$sys/584938/onenet_mqtt_dev1/cmd/response/+/+

以上内容仅供参考，如果你有更好的方法，请在评论区告诉我。
 
### APP连接ONeNet

- [1.内含demo](https://blog.csdn.net/m0_57523637/article/details/134110774)
- [2.新版视频地址](https://www.bilibili.com/video/BV1Sx42127ni/?spm_id_from=333.337.search-card.all.click&vd_source=5e8e4e9e284af3291f1a3addff3fc2c3)
- [3.json格式化网站](https://www.json.cn/json2java/)
- [4.Android Okhttp3的使用（很全面，包含Post提交字符串、键值对、表单、上传文件、无参请求和Get有参无参请求，还有自动添加token）](https://blog.csdn.net/NakajimaFN/article/details/109074166)
- [从json中取出数据,结合第一点看](https://blog.csdn.net/weixin_46323814/article/details/124662664)
- [5.云平台调试错误码](https://open.iot.10086.cn/doc/v5/fuse/detail/1007)

在B站上学习OKHTTP3，我把主要的核心代码放在附件里，分别是get和post的同步和异步请求，返回的结果和视频地址2里讲的一样。

- [视频地址1](https://www.bilibili.com/video/BV1Kr4y1b7Kw?p=2&vd_source=5e8e4e9e284af3291f1a3addff3fc2c3),
- [视频地址2](https://www.bilibili.com/video/BV1Z8411i7Yo/?p=70&spm_id_from=333.880.my_history.page.click&vd_source=5e8e4e9e284af3291f1a3addff3fc2c3)

在编写HTTPS网络请求（post）时需要上传一些数据，这些数据有一定的上传格式，下面的网址汇总了上传格式content参数

- [HTTP的content格式汇总网址](https://www.runoob.com/http/http-content-type.html)

-----------------------------------------
2024.8.19

#### json数据解析步骤

方法一：

![1](image-26.png)
![2](image-27.png)

方法二：

使用第三方库Gson,在使用前需要创建一个Jsonbear，就是接收Jsons数据的格式。

总结：

在Android Studio中，如果你想要生成代码，例如getter和setter方法，可以使用快捷键Alt + Insert（Windows/Linux系统）或Command + N（Mac系统） 。这个快捷操作会引导你通过一个菜单来选择想要生成的代码类型，比如构造函数、toString方法、以及各种重写方法等。

此外，如果你需要查看某个方法的参数信息，可以使用快捷键Ctrl + P（Windows/Linux系统）或Command + P（Mac系统），这将展示出当前方法的参数列表及其类型。
### STM32+电脑(模拟ESP32)+ESP8266通信

STM32————电脑：串口1（PA 9  PA10）,手机连接指定热点，连接成功后等待一段时间把摄像头的网址发给单片机，单片机通过串口2发给ESP8266.ESP8266再传到OneNet上。

**注意**：在用ESP8266最小系统通信的时，需要给板子单独供电，否则通信可能失败，原因我想可能是因为电压不够。

### 设备热点配网技术——WIFIManager

这个配网技术是让开发板设置热点，然后让手机连接，连接好后配置要让开发板连接的WIFI和密码，这个技术叫设备热点技术。相比于以往的一键配网技术，我个人觉得这个设备热点配网技术成功率要要一些。

缺点是这个技术不能用AT指令来实现，所以目前AT指令在不配合其他设备的情况下，通常都使用一键配网技术。

**ESP32和ESP8266使用设备热点配网技术的区别**

- 区别一：使用的WiFi库不同，ESP32使用`WiFi.h`，而ESP8266使用`ESP8266WiFi.h`
- 区别二：使用的WiFiManager.h版本不同，ESP32使用`2.0.17`(目前这个版本是最新的)，而ESP8266使用`0.16或0.15`
在使用ESP32时，请使用目前最新版的wifimanage库，而使用ESP8266的话请使用0.15或0.16版本的WIFIManager，如果ESP8266使用最新版的可能会报错。报什么错呢？

#### 报错：error: 'wifi_country_t' does not name a type const wifi_country_t WM_COUNTRY_US{"US",1,11,WIFI_COUNTRY_POLICY_AUTO};

完整报错如下：

```c
d:\Program Files (x86)\arduino\libraries\WiFiManager/wm_consts_en.h:162:7: error: 'wifi_country_t' does not name a type
 const wifi_country_t WM_COUNTRY_US{"US",1,11,WIFI_COUNTRY_POLICY_AUTO};
       ^
d:\Program Files (x86)\arduino\libraries\WiFiManager/wm_consts_en.h:163:7: error: 'wifi_country_t' does not name a type
 const wifi_country_t WM_COUNTRY_CN{"CN",1,13,WIFI_COUNTRY_POLICY_AUTO};
       ^
d:\Program Files (x86)\arduino\libraries\WiFiManager/wm_consts_en.h:164:7: error: 'wifi_country_t' does not name a type
 const wifi_country_t WM_COUNTRY_JP{"JP",1,14,WIFI_COUNTRY_POLICY_AUTO};
       ^
```

这个错误我目前没有解决，如果你解决了还请评论区或邮件（3256149770@qq.con）告诉我。

### 通信过程中遇到的问题

- keil5中一点击下载就闪退或点击debug中的setting就闪退。[参照文章](https://blog.csdn.net/wcanon/article/details/129645304)

- Keil5编程之warning: #223-D: function “xxx“ declared implicitly.[参考链接](https://blog.csdn.net/weixin_45714385/article/details/114965914)

### 这一部分所用到的资料下载地址

- [正点原子AKT-ESP-Fwifi模块](http://www.openedv.com/docs/modules/iot/atk-esp.html)

----

**2024.8.12(更新).**

### 【实验】SPIFFS文件系统的使用

[参考地址](https://blog.csdn.net/Naisu_kun/article/details/90442925)

### 【实验】TCP/UDP通信实验

[参考地址](https://blog.csdn.net/sinat_25923849/article/details/123682679)

## 【STM32F4学习】摄像头

### 参考资料

- [基于STM32F407的摄像头（不带FIFO的OV7670）图像采集及LCD显示实验-笔记整理](https://blog.csdn.net/LiangWF22/article/details/113618532)
- [STM32F4驱动OV7670总结](https://openatomworkshop.csdn.net/664701d5b12a9d168eb6e4d6.html?dp_token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpZCI6MTY4MDg5NSwiZXhwIjoxNzIyMTgwMzc2LCJpYXQiOjE3MjE1NzU1NzYsInVzZXJuYW1lIjoicXFfNjU3OTU3ODUifQ.xZCSUMCprrwP5K6jTYw716zgdx461uUG6SQOkClUhhw)
- [基于stm32f407vgt6驱动ov7670的TFT实时视频显示](https://github.com/weizhangCJLU/stm32f407vgt6-ov7670-tft)

## STM32F4工程代码

**使用三个ADC通道要注意按顺序去初始化，否则可能会出现问题，运营我还不知道.**

## 【服务器】NGINX

### 在Linux中搭建NGINX服务器

### TCP/IP协议

![alt text](image-6.png)
![alt text](image-7.png)
![alt text](image-8.png)
![alt text](image-9.png)
![alt text](image-10.png)
![alt text](image-11.png)

----------------------------------------------------------------------------

### [知识储备]

[在线自动生成nginx配置文件的网站](https://www.digitalocean.com/community/tools/nginx?global.app.lang=zhCN)

- 可以自由选择所需的应用，生成nginx配置作为参考。
- 根据你的业务需求，自动生成复杂的nginx配置文件，提供你作为参考，非常好用

### NGINX架构

#### NGINX中master的工作原理

![alt text](image-12.png)

### nginx处理HTTP请求的过程

![过程](image-13.png)

### 安装NGINX

![任务](image-15.png)

安装路径：https://blog.csdn.net/u011715638/article/details/138670319

```c
server {
    listen 80;
    listen [::]:80;

    server_name example.com www.example.com;

    root /var/www/html;
    index index.html index.htm;

    location / {
        try_files $uri $uri/ =404;
    }
}
```

上面是配置文件的内容，下面说明一下配置时的一些注意事项：

- 把配置文件的``example.com www.example.com``换成172.0.0.1，这样方便在本地测试；
- 在Ubuntu中可以下载ifconfig来查看Ubuntu的IP地址（ip addr也可以）
- 每次修改配置文件记`sudo systemctl reload nginx`

## 【服务器】Tomcat

1.安装Tomcat要使用哪个版本的java？

使用jdk8或更高版本，详细参考[官方文档](https://tomcat.apache.org/tomcat-9.0-doc/setup.html)

2.如何在Ubuntu安装Tomcat？

- 安装jdk8或更高版本
- 安装

## 【服务器】ZLMedaikit流媒体服务器

需要掌握的知识点：
![知识点](image-29.png)

## 【第三方库】FFmpeg媒体流转码工具

- [Ubuntu上安装ffmpeg的方法](https://cn.linux-console.net/?p=16693)
- [下载ffmpeg源代码地址](https://git.ffmpeg.org/ffmpeg.git)

## 【深度学习】飞桨paddlepaddle实战

-------
2024.8.18

**1.从入门到实际运用，请参考B站up主视频：**[点击链接](https://www.bilibili.com/video/BV1AM4y187yR/?spm_id_from=333.999.0.0)

**2.学完上面的视频后学习paddlepaddle的语音识别课程：**

**3.接着参考STM32cudeXM.AI的相关知识，把模型转换成onnx格式然后在但【单片机上运行：**

**3.1先用一个项目练练手：**`https://shequ.stmicroelectronics.cn/thread-632736-1-1.html`

- [官网](https://stm32ai.st.com/zh/stm32-cube-ai/)
- [入门手册文档](https://www.st.com/resource/zh/user_manual/dm00570145-getting-started-with-x-cube-ai-expansion-package-for-artificial-intelligence-ai-stmicroelectronics.pdf)
- [官网视频](https://shequ.stmicroelectronics.cn/forum.php?mod=forumdisplay&fid=1327&filter=dateline&orderby=dateline)
- [B站视频](https://www.bilibili.com/video/BV1ns4y1D7ea/?p=16)

意外收获，这是一个学习论坛：`https://www.waveshare.net/study/portal.php?mod=list&catid=38`

----
2024.8.25

参考文献：

- 禹鑫鹏,贺庆,王世昕,.基于STM32CubeMX AI和NanoEdge AI的眼动信号分类效果对比研究【J】.传感器世界,2024,(04):6-10.

---
2024.8.26

### X-CUDE—AI在线课程

[参考地址](https://www.st.com.cn/content/st_com/zh/support/learning/stm32-education/stm32-moocs/Introduction_to_STM32CubeAI_MOOC.html)

当模型验证结束后，需要修改以下内容：
![修改文件](image-28.png)


### 相关论文参考

- [【github项目网址】婴儿哭声分类识别](https://github.com/ldknight/Babysound-Sort-tensorflow/blob/main/README.md)

## 【机器学习】HMM模型（隐马尔科夫列）

隐马尔科夫列模型定义：
![定义](image-25.png)

### 相关论文参考

-[【1.基于声学的婴儿哭声识别细分市场模型】(Baby Cry Recognition Based on Acoustic)](https://sprateam-ustc.github.io/Publications/shuxianwang-2022-ncmmsc.pdf)
-[【2.使用隐马尔可夫模型自动分割婴儿哭闹信号】(Automatic segmentation of infant cry signals using hidden Markov models)](https://asmp-eurasipjournals.springeropen.com/articles/10.1186/s13636-018-0124-x)

### 导入库

## 【音视频学习】

### H.264编码

所谓视频编码就是指通过特定的压缩技术，将某个视频格式文件转换成另一种视频格式文件的方式。

视频流传输中最重要的编解码标准有国际电联(TU-T，国际电信联盟)的H.261、H.263、H.264等，运动静止图像专家组（由ISO国际标准化组织与IEC国际电子委员会于1988年联合成立)的MPEG系列标准MPEG1、MPEG2、MPEG4 AVC等。

其中ITU-TH.264/MPEG-4 AVC是ITU-T与ISO/IEC连手合作制订的新标准。ITU-T方面称之为H.264。但ISOIEC的则将这个新标准归纳于MPEG系列,称为MPEG-4 AVC。

而H.265则被视为是ITU-TH.264/MPEG-4AVC标准的继任者，又称为高效率视频编码(High Efficiency VideoCoding，简称HEVC)

![h264](image-17.png)

格式：
![h264](image-16.png)

### 安卓音视频实战编程

构建预览布局-使用SurfaceView或者TextureView

打开相机- Camera.open

设置参数- Camera.Parameters

设置预览数据回调- PreviewCallback

设置预览画布并启动- setPreviewTexture/startPreview

释放相机- stopPreview/release

### YUV

YUV主要应用于优化彩色视频信号的传输，与RGB相比，YUV只需要占用极少的频宽(RGB需要三个独立的视频信号同时传输)。YUV中Y代表明亮度，也称灰阶值;U与V表示的则是色度（色调和饱和度)也可以记作:YCbCr。如果只有Y数据,那么表示的图像就是黑白的。

使用YUV的原因：

使用YUV格式才能极大地去除冗余信息，人眼对亮点信息更敏感，对色度敏感度不高。也就是说,可以压缩UV数据,而人眼难以发现。所以压缩算法的第一步，往往先把RGB数据转换成YUV数据。对Y少压缩一点，对UV多压缩一点，以平衡图像效果和压缩率。这也是为什么编码选择使用YUV而不是RGB。

推算公式：
![alt text](image-18.png)

YUV是一组数据的压缩格式，其下还有因为排列不同而衍生的不同格式名称

![alt text](image-19.png)

NV21转I420
![alt text](image-20.png)

MediaCode组件：
![alt text](image-21.png)

### RTMP协议所在所在的网络层结构

![alt text](image-22.png)

### 【第三方库】LIBRTMP

### 【工具】类似安卓虚拟机：Total Control

### 采集音频数据工具

![alt text](image-23.png)

### 视频采集工具---MediaProjection

![alt text](image-24.png)


--------

安卓P18

----
2024.8.27

方法一：

[安卓使用VLC库实内网播放ESPCam摄像头数据](https://blog.csdn.net/gs12software/article/details/130618598?spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7Ebaidujs_baidulandingword%7ECtr-3-130618598-blog-114264625.235%5Ev43%5Epc_blog_bottom_relevance_base2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7Ebaidujs_baidulandingword%7ECtr-3-130618598-blog-114264625.235%5Ev43%5Epc_blog_bottom_relevance_base2&utm_relevant_index=6)

方法二：

[Mediacode编解码](https://blog.csdn.net/u011418943/article/details/107561111)


## 【安卓APP制作】

1.安卓登录开发

-------
2024.8.21

### 安卓的两种登录方式

登录可以进去就强登录，或进去后在某个页面触发登录。

对于第一个只需要在第一个页面做登录处理即可，而第二种需要`Hook AMS + APT`框架实现，具体看这篇博文：[文章连接](https://blog.csdn.net/calm1516/article/details/114482477)

### 安卓中集成第三方库进行登录

可以使用目前比较流行的第三方库实现：

`JustAuth开源组件`：**JustAuth**是一个整合了国内外数十家知名平台的OAuth登录的开源组件，它提供了丰富的OAuth平台支持，自定义State、自定义OAuth、自定义Http接口和自定义Scope等功能，极大地简化了开发者在第三方登录功能上的工作量。

--------
2024.8.23

2.数据显示

### 安卓显示ONENet提供的可视化链接

[参考链接](https://blog.csdn.net/qq_52608074/article/details/138144200)

------
2024.8.29

## 硬件系统

一、设备选型

1.空气质量模块设备选型：

[（1）MQ135测量空气质量和氨气PPM的计算](https://blog.csdn.net/qilin001cs/article/details/118771474)

{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}