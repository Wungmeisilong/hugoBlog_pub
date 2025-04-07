# AndroidStudio笔记

这篇文章主要介绍AndroidStudio的使用，以及一些Android开发的基础知识。以及一些开发中遇到的问题和解决方法，除此之外，还会介绍一些开发中常用的工具和技巧。

## 第一章

### 配置开发环境

- 1.**安装JDK**
    ["安装连接"](https://www.bilibili.com/video/BV1tE411V7xA/)
- 2.**安装AndroidStudio**
    ["安装连接"](https://www.bilibili.com/video/BV11z4y1x7Dh/)
- 3.**安装SDK**
- 4.**AndroidStudio汉化**
- https://www.bilibili.com/video/BV1Hz4y1K7Tc/

## 第二章

Gradle():自动构建
日志输出工具：查看报错
Run（运行）

工程结构：
（清单文件）：对Activity，service，re广播等进行注册的文件
Java目录：
后缀为 **.class**
drawable目录：资源文件，放图片、图标、背景资源的文件
Layout目录：放页面布局文件
放图片和.xml文件，适配不同分辨率的文件夹
values目录：颜色、数组、字符串、样式

## Android基本原理

### Android体系结构

### Android 用用程序核心组件

#### Activity

## 第四章 Activity、Fragment以及Intent通信机制

### Activity生命周期

四种状态的转换

布局的特点：

## 第八章 数据存储和提供器

### SharedPreference

使用键值对关系来获取文件

### SQLite

轻量级占用内存小，支持基本的MySQL语言。
创建过程：

### ContentPreference（应用存储）

通过暴露URL让软件之间可以共享文件
好比一般使用文件时，软件会要求需要访问你手机文件权限。

### 文件存储

## 网络通信编程

### 网络访问方式

网络状态码，例如404表示什么？

### 数据解析

1.JSON格式解析：
以类对象的方式进行相应，以数组的方式进行相应，也可以二者混合。

### 网络状态

### JavaScript与Java交互

webView的使用

在简单的使用webview过程中可能无法进入指定的网页，而且AndroidStudio模拟机上还会弹出如下错误：

````markdown
    **Webpage not available** 

    The webpage at http://www.baidu.comi could not beloaded because:
    net::ERR_CLEARTEXT_NOT_PERMITTED
````

解决的办法：
请在**AndroidManifest.xml**文件下添加代码：
{{< tabs title=".xml文件" >}}
{{% tab title="添加代码" style="info" color="blue " %}}

````xml

    <uses-permission android:name="android.permission.INTERNET" />
    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
    <uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
````

{{% /tab %}}
{{< /tabs >}}

如果添加上面的还不可以，请在**manifest**中添加如下代码：

{{< tabs title=".xml文件" >}}
{{% tab title="添加代码" style="info" color="blue " %}}

````xml
<?xml version="1.0" encoding="utf-8"?>
    <manifest ...>
        <application 
            ...
            android:usesCleartextTraffic="true">
            ...
        </application>
    </manifest>
````

{{% /tab %}}
{{< /tabs >}}

["原文章链接"](https://blog.csdn.net/zgd826237710/article/details/95520785/)

getwebSetting

{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}
