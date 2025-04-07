# AndroidStudio

接下来将将介绍AndroidStudio的复习资料，包括AndroidStudio简介、AndroidStudio中 **Make Project** 、**Clean Project** 、**Rebuild Project** 的作用、Run窗口、manifests文件夹（清单文件夹）、java文件夹、res文件夹、Android系统体系结构四层等。

## AndroidStudio简介

{{% badge %}}Important{{% /badge %}}

1.配置Android开发环境：

- 安装JDK：
    （1）下载JDK
    （2）配置环境变量；
- 安装Android Studio；
- 安装SDK。

2.自动构建工具Gradle：

Gradle 是以 Groovy 语言为基础，面向Java应用为主，基于DSL（领域特定语言）语法的自动化构建工具。它可以自动化地进行软件构建、测试、发布、部署、软件打包，同时也可以完成项目相关功能，如生成静态网站、生成文档等。另外其集合了Ant的灵活性和强大功能，以及Maven的依赖管理和约定，从而创造了一个更有效的构建方式。凭借Groovy的DSL和创新打包方式，Gradle提供了一个可声明的方式，并在合理默认值的基础上描述所有类型的构建。Gradle目前已被选作许多开源项目的构建系统。

3.Logcat日志输出工具：使用 Logcat 查看日志

Android Studio 中的 Logcat 窗口会实时显示设备日志来帮助您调试应用，例如，使用 Log 类添加到应用的消息、在 Android 上运行的服务发出的消息或系统消息（例如在发生垃圾回收时）。如果应用抛出异常，Logcat 会显示一条消息，后跟相关联的堆栈轨迹，其中包含指向代码行的链接。

4.Android Studio中 **Make Project** 、**Clean Project** 、**Rebuild Project** 的作用

- Make Project：编译Project下所有Module（组件或模块），一般是自上次编译后Project下有更新的文件，增量编译，不生成Apk。
- Clean Project：删除之前编译后的编译文件。部分版本的AS会自动重新编译整个Project，不生成Apk。
- Rebuild Project：先执行Clean操作，删除之前编译的编译文件和可执行文件，然后重新编译新的编译文件，不生成Apk

5.Run窗口：可以输出程序运行过程中出现的错误。
6.manifests文件夹（清单文件夹）：Android系统配置文件夹，包含一个AndroidManifest.xml文件（清单文件），可在此文件注册声明

- `<activity>`页面、
- `<service>`服务、
- `<receiver>`接收器、
- `<provider>`提供者或提供程序、
- `<uses-permission>`使用权限等；

7.java文件夹：存放Java代码的文件夹，新建项目时默认生成了三个文件夹，com.first.project文件夹用来存放Java文件，这里包含一个名为MainActivity的Java文件，是新建项目时默认生成的。
第二个和第三个文件为测试代码文件夹，不是十分常用。

- res文件夹：存放Android项目的资源文件，包含四个文件夹：
- drawable（图片资源文件夹）、
- layout（布局资源文件夹）、
- mipmap（图片资源文件夹，存放项目图标）、
- values（存放数值资源文件），
- 此外有menu文件（菜单资源文件）。

8.Android系统体系结构四层，从上到下分别是

- 应用程序层
- 应用程序框架层
- 系统运行库层
- Linux内核层
每一层都是用其下面各层所提供的服务。

应用程序层

Android平台包含了许多核心的应用程序，诸如Email客户端、SMS短消息程序、日历、地图、浏览器、联系人等应用程序。这些应用程序都是用Java语言编写的。开发人员可以灵活地根据需求替换这些自带的应用程序或者开发新的应用程序。

应用程序框架

开发者可以完全访问核心应用程序所使用的API框架。该层简化了组件的复用，使得开发人员可以直接使用系统提供的组件来进行快速地开发，也可以通过继承灵活地加以拓展。这些东西包括：

活动管理器（Activity Manager，管理各个应用程序的生命周期以及通常的导航回退功能）
视图系统（View System，构建应用程序的基本组件）
内容提供器（ContentProvider，使得不同的应用程序之间可以存取或者分享数据）
资源管理器（Resource Manager，提供应用程序使用的各种非代码资源，如本地化字符串、图片、布局文件等）
通知管理器（Notification Manager，使应用程序可以在状态栏中显示自定义的提示信息）等。

系统运行库层

包括系统库和Android Runtime，系统库是应用程序框架的支撑，是连接应用程序框架层与Linux内核层的重要纽带。程序在Android Runtime中执行，其运行时分为核心库和Dalvik虚拟机两部分。

Linux内核层

Android基于Linux2.6的内核，其核心系统服务如安全性、内存管理、进程管理、网络协议以及驱动模型都依赖于Linux内核，同时内核层也扮演了介于硬件层和软件栈之间的抽象层的角色。
Linux内核层和系统运行库层之间，从Linux操作系统的角度来看，是内核空间与用户空间的分界线，Linux层运行于内核空间，以上各层运行于用户空间。系统运行库层和应用框架层之间是本地代码层和Java代码层的接口。应用框架层和应用程序层是Android的系统API的接口，对于Android应用程序的开发，应用程序框架层以下的内容是不可见的，仅考虑系统API即可。

9.四大核心组件有：activity（活动或页面）、service（服务）、broadcast receiver（广播接收器）、content provider（内容提供者）

10.Activity介绍Android系统是通过任务栈来管理Activity的。当一个Activity启动时，会把Activity压入到堆栈中，当用户按返回键或者结束掉该Activity时，它会从堆栈中弹出。

11.Android为我们定义了四种加载方式

Standard 加载模式  ——标准模式/默认加载模式

标准模式：系统默认的Activity启动模式，当Intent欲打开Activity时，在该Activity不存在，存在于栈顶和存在于栈底三种情况下都会正常创建Activity，并压入任务栈栈顶；

SingleTop 加载模式  ——栈顶单例模式

栈顶单例模式：当启动一个Activity时，只有当该activity存在任务栈中且为栈顶，Intent才会通过onNewIntent()方法传递给在栈顶Activity实例；其他情况则正常创建Activity并压入任务栈；

SingleTask 加载模式  ——栈内单例模式

站内单例模式：当启动一个Activity时，系统会先检查任务栈内是否有该Activity，如果该Activity不存在则正常创建Activity实例，如果存在且在栈底则会将它上面的Activity弹出并销毁，使该Activity置于栈顶再调用onNewIntent()方法；

SingleInstence 加载模式  ——全局单例模式

与SingleTask模式基本一样，只是在这个模式下Activity所处的任务栈中只能有Activity这一个实例，不能有其他的实例。

12.Activity生命周期是指Activity从创建到销毁的过程，在这一过程中，Activity一般处于4种状态，即：Active/Running、Paused、Stop、Killed

（1）Active/Running   此时Activity一定处于屏幕的最前端，用户完全可以看得到，并且可以与用户进行交互。对于Activity栈来说，它处于栈顶；
（2）Paused  此时Activity在屏幕上仍然可见，但是它已经失去了焦点，用户不能与之进行交互。暂停状态的Activity是存活的，它仍然维持着其内部状态和信息，但是系统可能会在手机内存极低的情况下杀掉该Activity；
（3）Stop   此时Activity在屏幕上完全不能被用户看见，也就是说这个Activity已经完全被其他Activity所遮住。处于停止状态的Activity，系统仍然保留有其内部状态和成员信息，但是它经常会由于手机系统内存被征用而被系统杀死回收；
（4）Killed   Activity被系统杀死回收或者未启动。

13.为了能够让Android程序了解自身状态的变化，Android系统中具有很多事件回调函数，我们可以重载这些方法来实现自己的操作。Android生命周期的事件回调函数如下：

```java
    void onCreate(Bundle savedInstanceState) 
    void onStart() 
    void onRestart() 
    void onResume() 
    void onPause() 
    void onStop() 
    void onDestroy()
```

14.Activity生命周期

15.Fragment必须是依存于Activity而存在，因此Activity的生命周期会直接影响到Fragment的生命周期。图在课本第50页。

由图可以看到Fragment比Activity多了几个额外的生命周期回调函数：

onAttach(Activity)：当Fragment与Activity发生关联时调用。从该方法开始，就可以通过Fragment.getActivity方法获取与Fragment关联的窗口对象了，但在该方法中仍然无法操作Fragment中的控件。
onCreateView(LayoutInflater, ViewGroup, Bundle)：创建该Fragment的视图。onActivityCreated(Bundle)：当Activity的onCreate方法返回时调用。

onDestoryView():与onCreateView相对应，当该Fragment的视图被移除时调用。onDetach()：与onAttach相对应，当Fragment与Activity关联被取消时调用。

16.在使用Intent进行Activity之间的跳转时，我们通常有三种Intent跳转方式，即：不带参数的跳转、带参数的跳转以及带返回值的跳转，代码实现可参考实验报告或书本。

17.TextView常用的属性

```xml
    android:id="@+id/textView1"表示该控件的id，在布局文件中或者代码中被引用
    android:textStyle="bold"表示TextView里面的字加粗显示
    android:layout_height="wrap_content"表示该控件的高度为其包含内容的高度
    android:layout_width="wrap_content"表示该控件的宽度为其包含内容的宽度
    android:text="@string/signin" 显示的内容，这里表示存放在string.xml文件中name=signin的文本
    android:layout_height="40dip"设置具体的高度
    android:textColor="#7089c0"设置文本的颜色
    android:textSize="18sp"设置文本的大小
    android:gravity="center_vertical"设置文本垂直居中
    android:paddingLeft="5dip"设置内边距
    android:layout_marginTop="5dip"设置外边距
```

18.LinearLayout线性布局、

- RelativeLayout相对布局、
- FrameLayout帧布局、
- TableLayout表格布局、
- AbsoluteLayout绝对布局

线性布局，是指该容器（LinearLayout）内子控件的摆放方式有两种：
第一种：垂直放置（VERTICAL），相对水平放置来讲，垂直放置就相当于一列，放置的控件或者容器只能在该列中的某个位置，两个控件之间只存在上下方向的关系，不存在其他方向上的关系。当这一列放满后，再添加的控件就至于屏幕之外存在，无法看见。
第二种：水平放置（HORIZONTAL），指的是该容器里面存放的控件或者容器只能以一行的形式出现，放置的控件只能是该行中的某个位置，两个控件或者容器之间只有左右关系没有其他方向上的关系，当放置水平方向满屏时不会自动换行，再放置的控件将在屏幕之外存在，无法看见。
在线性布局中重要的属性值对应表示

```xml
    android:orientation	            //设置控件或者容器存放的方式
    android:id	                    //设置控件id，方便在使用时找到其引用
    android:layout_width	        //容器的宽度，该值必须设置
    android:layout_height	        //容器的高度，该值必须设置
    android:layout_weight	        //该属性针对其内的子控件，存放在LinearLayout中的控件都有这个属性，用来设置该控件或者容器占父控件或者容器的比例。
```

相对布局，是指利用控件之间的相对位置关系来对布局进行放置。换句话说，在该容器中的控件与其他任何一个控件或者容器（包括父控件）有相对关系。

帧布局，是指该容器内放置的控件或者容器没有上下左右的关系，只有层叠前后的关系。放置在容器内的控件按放置的前后顺序逐一层叠摆放，自然地后面摆放的控件就将前面摆放的控件覆盖了，叠在它的上面了。对于放置前后的关系，在没有设置其他属性之前，Android系统采用的是叠放的原则，即后加入节点的层叠在上面。设置属性android：bringToFront=“true|false”将前面放置的控件提到最前面可见。

表格布局，指该容器是一个表格，放置控件时，控件的位置坐落在表格的某个位置上。其中TableRow是配合TableLayout使用的，目的是为了让TableLayout生成多个列，否则TableLayout中就只能存在一列元素，但可以有多行。

TableLayout的直接父类是LinearLayout，所以其具有LinearLayout的属性，TableLayout中的每一行用TableRow表示，每一列就是TableRow中的个数指定的。TableRow的直接父类是LinearLayout，但是其放置的方式只能水平放置。

绝对布局，是指以屏幕左上角为坐标原点（0,0），控件在容器中的位置以坐标的形式存在，可以随意指定控件的坐标位置，非常灵活。在开发过程中很少使用，原因是屏幕兼容性不好，不便控制两个控件之间的位置。其中控件或者容器放置的位置通过android:layout_x和android:layout_y这两个属性进行设置。

ConstraintLayout约束布局

优点：

ConstraintLayout之所以成为目前Android开发中主流的布局，除了官方建议使用ConstraintLayout外还有以下几个方面的优势
    1.功能强大，ConstraintLayout几乎能实现其他布局所有的功能
    2.能减少布局层次的嵌套，有性能的优势
    3.可视化操作的增强，大部分界面用ConstraintLayout都能通过可视化编辑区域完成

19.对话框（Dialog）是Android系统在Activity或者其他组件运行过程中提供的一种资源消耗很小的提示机制，它可以帮助应用完成一些必要的提示功能，同时还提供一些用户交互的功能，包括简单的提示、等待、选择、展示等功能。操作简单，资源消耗较少。代码实现可参考实验报告或书本

1提示对话框

```java
package com.example.alertdialog;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.HashMap;

public class MultipleChoiceDialogBox extends AppCompatActivity {
    private Button button;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.test);
        button = findViewById(R.id.dialog_box_up);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(MultipleChoiceDialogBox.this);
                builder.setTitle("这是一个简单的弹窗");
                builder.setIcon(R.mipmap.ic_launcher);
                builder.setMessage("你学会了吗？");
                builder.setPositiveButton("学会了", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {

                    }
                });
                builder.setNegativeButton("不会", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {

                    }
                });
                builder.show();
            }

        });
    }
}
```

2单选对话框

```java
package com.example.alertdialog;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.HashMap;

public class MultipleChoiceDialogBox extends AppCompatActivity {
    private Button button;
    private TextView textView;
    private String sexx[] ={"男","女"};
    private int choiceWitch = 1;
 
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.test);
        button = findViewById(R.id.dialog_box_up);
        textView=findViewById(R.id.show_dialog_box_text);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(MultipleChoiceDialogBox.this);
                builder.setCancelable(false);
                builder.setSingleChoiceItems(sexx, -1, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        choiceWitch=which;
                    }
                });
                builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        textView.setText(sexx[choiceWitch]);
                    }
                });
                builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {

                    }
                });
                builder.show();
            }

        });
    }
}
```

3多选对话框

```java
package com.example.gpc.wzxapplicationwu1;

import android.content.DialogInterface;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.HashMap;

public class AlertDialogActivity extends AppCompatActivity{
    private Button button;
    private TextView textView;
    private String sexx[] ={"a","b","c","d"};
    private boolean stu[] = {false,false,false,false};
    private int choiceWitch = 1;
    private ArrayList<Integer> list = new ArrayList();
    private String str = "";
    private HashMap<Integer,Integer> map = new HashMap<>();
    @Override
    protected void onCreate(@Nullable final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.alert_dialog);
        textView = findViewById(R.id.alert_dialog_textview);
        button = findViewById(R.id.alert_dialog_button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(AlertDialogActivity.this);
                builder.setMultiChoiceItems(sexx, stu, new DialogInterface.OnMultiChoiceClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i, boolean b) {
                        if(b == true){
                            map.put(i,i);
                        } else {
                            map.remove(i);
                        }
                    }
                });
                builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        for (Integer j : map.keySet()){
                            int z = map.get(j);
                            str = str + sexx[z];
                        }
                        textView.setText(str);
                        str = "";
                    }
                });
                builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {

                    }
                });
                builder.show();
            }
        });
    }
}

```

19.Android系统中的ContextMenu(上下文菜单)类似于PC中的右键弹出菜单，当一个视图注册了上下文菜单时，长按该视图对象将出现一个提供相关功能的浮动菜单。上下文菜单可以被注册到任何视图对象中，最常见的是用于列表视图中，但上下文菜单不支持图标和快捷键。

选项菜单
当Activity在前台运行时，如果用户按下微信消息列表页面右上角加号键，此时就会在屏幕右上角弹出相应的选项菜单。但这个功能需要开发人员编程来实现，如果在开发应用程序时没有实现该功能，那么程序运行时按下手机的meun键是不会起作用的。
   
下拉菜单
严格来讲Spinner不算是一个菜单，但是其操作和表现形式具有菜单的行为。Spinner的有效使用可以提高用户的体验。当用户需要选择的时候，可以提供一个下拉列表将所有可选的项列出来，供用户选择。

21.Toast（提示）的使用，代码实现可参考实验报告或书本。

Toast.makeText(MultipleChoiceDialogBox.this,"nihao",Toast.LENGTH_LONG).show();

22.Notification表示通知，是可以显示在Android系统通知栏上的一种数据的封装形，运用Notification可以提高应用的交互性，带来良好的用户感受。
关于Notification，主要涉及到Notification类与NotificationManager类的使用。
Notification类的实例表示在通知栏显示的一个通知，该通知内容包括该通知的ID、时间、内容、标题、图标等。
NotificationManager实例用来将该通知发送到系统的通知栏上。

23.本地服务（Local Service）用于应用程序内部，可以实现应用程序自己的一些耗时任务，比如查询升级信息、网络传输，或者在一些场合需要在后台执行，比如播放音乐，并不占用应用程序比如Activity所属的线程，而是单开线程后台执行，这样用户体验比较好。

Service的两种启动方式
(1)通过bindService绑定：
绑定时，bindService -> onCreate() –> onBind()；
 解绑定：unbindService –>onUnbind() –> onDestory()；
此时如果调用者（如Activity）直接退出，Service 由于与调用者绑定在一起，则Service随着调用者一同停止。

（2）通过startService绑定：
 启动时，startService –> onCreate() –> onStart()；
停止时，stopService –> onDestroy()；
此时，服务与调用者（如Activity）没有绝对关联，当调用者关闭后服务还会一直在后台运行。
服务的生命周期


23.在Android里面有各式各样的广播，比如：电池的状态变化、信号的强弱状态、电话的接听和短信的接收等等，本节将会介绍系统发送、监听这些广播的机制。

两种广播注册方法的区别
第一种不是常驻型广播，也就是说广播跟随程序的生命周期
第二种是常驻型，也就是说当应用程序关闭后，如果有信息广播过来，程序广播接收器也会被系统调用自动运行

25.作为一个完整的应用程序，数据的存储与操作是必不可少的。Android系统为我们提供了四种数据存储方式，分别是：Shared Preference、SQLite、File和ContentProvider。
SharedPreference：一种常用的数据存储方式，其本质就是基于xml文件存储键值对（key-value）数据，通常用来存储一些简单的配置信息。

SQLite：一个轻量级的数据库，支持基本SQL语法，是Android系统中常被采用的一种数据存储方式。Android为此数据库提供了一个名为SQLiteDatabase的类，封装了一些操作数据库的API。
文件储存：即常说的文件（I/O）存储方法，常用于存储数量比较大的数据，但缺点是更新数据将是一件困难的事情。
ContentProvider：它是Android系统中能实现应用程序之间数据共享的一种存储方式。由于Android系统中，数据基本都是私有的，存放于“data/data/程序包名（package name）”目录下，所以要实现数据共享，正确方式是使用ContentProvider。由于数据通常在各应用间是私密的，所以此存储方式较少使用，但是其又是必不可少的一种存储方式。如果应用程序有数据需要共享时，就需要使用ContentProvider为这些数据定义一个URI（包装成Uri对象），然后其他的应用程序就通过ContentResolver传入这个URI来对数据进行操作。

26.SharedPreferences对象的常用方法有以下几种：



27.Sqlite数据库的使用涉及到两个类：SQLiteDataBase和SQLiteOpenHelper

SQLiteDatabase具体方法：


SQLiteOpenHelper 具体方法


例：要得到一个可写数据库，首先创建一个类继承 SQLiteOpenHelper，重写 onCreate()方法并在该方法中创建表，然后使用创建出的 SQLiteOpenHelper 的子类对象的 getWritableDatabase()方法获得一个可读写的数据库对象。

28.网络状态


29.JSON数据解析
是一种轻量级的数据交换格式，它基于纯文本，采用完全独立于语言的文本格式来存储和传输数据。在编程环境中解析JSON数据意味着将JSON字符串转换为程序可以理解并操作的数据结构
JSON Object：JSON中对象(Object)以“{”开始, 以“}”结束。对象中的每一个item都是一个键值对，表现为“key:value”的形式, 键值对之间使用逗号分隔。如下代码所示：
{
"name"："coolxing"， 
"age"：24，
"male"：true，
	"address"：{ 
"street":"huiLongGuan"，
"city":"beijing"，
"country":"china"
}
}

JSONArray: JSON数组(Array)以"["开始, 以"]"结束, 数组中的每一个元素可以是String,Number, Boolean, null, Object对象甚至是Array数组, 数组间的元素使用逗号分隔,如下代码所示：
[
"coolxing", 24， 
{
"street":"huiLongGuan"， 
"city":"beijing"，
"country":"china"
}
]

30.Webview
WebView 加载页面主要调用三个方法：LoadUrl、LoadData、LoadDataWithBaseURL.
    LoadUrl  直接加载网页、图片并显示。
    LoadData 显示文字与图片内容。(模拟器1.5、1.6)。
    LoadDataWithBase 显示文字与图片内容 (支持多个模拟器版本)。
使用webview的websetting来设置，WebSetting websetting = webView.getSettings().
Websetting常用方法：


31.进程是一个具有一定独立功能的程序关于某个数据集合的一次运行活动。它是操作系统动态执行的基本单元。
通俗地讲一个进程代表一个应用程序，该应用程序运行在自己的进程当中，使用系统为其分配的堆内存，不受其他应用程序或者是其他进程的影响，是独立运行的。当然一个进程中可以同时运行多个应用程序，这时堆内存是共享的。

Android系统为每个应用程序分配了一个进程，应用程序中组件（Activity，Service，BroadCast）的状态决定的一个进程的“重要性层次”，层次最低的属于旧进程。这个“重要性层次”有五个等级，也就是进程的生命周期，按最高层次到最低层次排列如下：
   （1）前台进程
   （2）可视进程
   （3）服务进程
   （4）背景进程
   （5）空进程
  
 一个Android应用只能存在一个进程，但是可以存在多个线程，也就是说，当应用启动后，系统分配了内存，这个进程的内存不被其他进程使用，但被进程中一个或多个线程共享。宏观地讲所有的进程是并发执行的，而进程中的多个线程同时执行但并不是并发的，系统的CPU会根据应用的线程数触发每个线程执行的时刻，当CPU时间轮到分配某个线程执行时刻时该线程开始执行，执行到下一个线程执行的时，依此轮询，直到线程执行结束。
在理解启动模式前，理解几个概念

1. 任务
用户尝试在您的应用中执行操作时与之互动的一系列 activity。这些 activity 按照每个 activity 的打开顺序排列在称为“返回堆栈”的堆栈中，也称为任务栈。
1. Activity：简单理解就是页面，下面介绍启动模式的时候我们都把它理解为“页面”；
2. Intent：教材一般叫意图，简单理解它就是带操作的信息，像指令一样，接收到Intent就类似接收到指令一样。
3. 一个应用可以有多个任务栈，在考虑一个应用一个任务栈的情况下，两个页面如果在不同应用程序，那么在启动这两个页面的时候，他们会被压入各自的任务栈，所以两个不同应用程序的各自页面一般不会出现在同一个任务栈中；
4. onNewIntent() 方法的作用主要是允许已存在的 Activity 更新其状态以响应新的 Intent 数据。例如，在接收动态广播（如地理位置更新、消息通知等）或重新加载内容时，无需重启 Activity 就可以处理新的数据。开发者需要重写这个方法并在其中处理接收到的新 Intent 数据。

四种启动模式：

**标准模式（standard）**

默认启动模式，如果任务栈中没有Activity则会实例化一个新的Activity，并将其压入当前任务栈的顶部。
如果同一个Activity已经存在栈顶，那么新的实例仍然会被创建并压入栈中，因此栈中可能包含多个该Activity实例。

**单例模式（singleTop）**

当一个新的Intent要启动已位于栈顶的Activity（与请求的Intent匹配的Activity）时，系统不会创建新的Activity实例，而是将intent通过onNewIntent()方法传递给现有的Activity实例；

- 如果目标Activity不在栈顶，则会正常创建新的实例；
- 如果目标Activity不在栈顶而在栈顶的下一层呢？
    比如现在有A-B-C-D,D在栈顶，如果传来的Intent是要打开页面C，在单例模式下也是正常创建；

总结：

在单例模式下，

- 如果页面不存在，也就是要打开的Activity没有在任务栈中实例化，那么正常创建Activity实例，并压入栈中；
- 如果Activity已经存在于任务栈中，且为栈顶，那么系统不创建新的Activity实例，而是将intent通过onNewIntent()方法传递给现有的Activity实例，
- 如果不是栈顶，正常创建Activity实例。

**栈内复用模式（singleTask）**

当打开一个页面，也就是启动一个Activity时，系统首先会在整个任务栈中查找这个Activity是否已经在栈中，

- 情况一：如果存在并且处于栈底，则直接把该Activity之上的所有Activity弹出栈，使这个Activity置于栈顶并调用其onNewIntent()。
- 情况二：如果在栈顶，则将intent通过onNewIntent()方法传递给现有的Activity实例

如果不存在已有的Activity实例，才会创建新的实例并放入栈顶。这种模式下的Activity始终只有一个实例存在于任务栈中。

**单实例模式（singleInstance）**

当启动Activity时，系统会为它创建一个新的任务栈，然后在这个新的栈顶放上这个Activity的实例。
如果再次启动这个Activity，即使是在另一个任务栈中，系统也不会创建新实例，而是将意图传递给已经存在的Activity实例。

{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}