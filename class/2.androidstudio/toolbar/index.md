# 2-1.Toolbar工具栏

## menu文件的创建

在创建**menu**这个目录前，请看查看**res/**目录下是否包含该目录，如果没有则创建。
接着在该目录下创建**xml**文件，此处文件名为**content_menu**。在该**content_menu**使用`<item`,如下为部分代码：
{{< tabs title=".xml文件" >}}
{{% tab title="简码" style="info" color="blue " %}}

````xml
    <item
        android:id="@+id/content_menu_group_chat"
        android:title="发起群聊"
        android:orderInCategory="1"
        />
````

{{% /tab %}}
{{% tab title="全码" style="default" color="green " %}}

````xml
<?xml version="1.0" encoding="utf-8"?>
<menu xmlns:android="http://schemas.android.com/apk/res/android">
    <item
        android:id="@+id/content_menu_group_chat"
        android:title="发起群聊"
        android:orderInCategory="1"
        />
    <item
        android:id="@+id/content_menu_add_friend"
        android:title="添加朋友"
        android:orderInCategory="2"
        />
    <item
        android:id="@+id/content_menu_add_RichScan"
        android:title="扫一扫"
        android:orderInCategory="3"
        />
    <item
        android:id="@+id/content_menu_add_QRcode"
        android:title="扫码"
        android:orderInCategory="4"
        />
</menu>
````

{{% /tab %}}
{{< /tabs >}}
在代码中**orderInCategory**属性是用来控制该**item**权重的，权重越小等级越高，该标题就会靠前显示，
{{% notice style="secondary" icon="eye" title="结果" %}}
![8899](img1_item.jpg?classes=shadow,border&height=250px&width=15vw)
{{% /notice %}}

## 创建布局页面

详细代码如下：
{{< tabs title=".xml文件" >}}
{{% tab title="简码" style="info" color="blue " %}}

````xml
<androidx.appcompat.widget.Toolbar
            android:id="@+id/options_menu_toolbar"
            android:layout_width="409dp"
            android:layout_height="wrap_content"
            android:background="?attr/colorPrimary"
            android:minHeight="?attr/actionBarSize"
            android:theme="?attr/actionBarTheme"
            app:layout_constraintLeft_toLeftOf="parent"
            app:layout_constraintRight_toRightOf="parent"
            app:layout_constraintTop_toTopOf="parent" />
````

{{% /tab %}}
{{% tab title="全码" style="default" color="green " %}}

````xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <androidx.appcompat.widget.Toolbar
        android:id="@+id/options_menu_toolbar"
        android:layout_width="409dp"
        android:layout_height="wrap_content"
        android:background="?attr/colorPrimary"
        android:minHeight="?attr/actionBarSize"
        android:theme="?attr/actionBarTheme"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>
````

{{% /tab %}}
{{< /tabs >}}

## Activity.java[^1]文件中

[^1]:Activity.java这个文件的一般就是我们所说的主程序，类似与C语言中的包含main入口的文件。

此处创建类的步骤，继承`AppCompatActivity`方法就不再赘述。

1. 在`onCreate`获取**Toolbar**的id，这个过程也叫实例化；
2. 接着使用方法`setSupportActionBar`;
3. 在onCreate外重写`onCreateOptionsMenu`和`onOptionsItemSelected`方法。

{{< tabs title=".java文件" >}}
{{% tab title="onCreate" style="info" color="blue " %}}

````java
@SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.opetions_menu);
        toolbar = findViewById(R.id.options_menu_toolbar);
        setSupportActionBar(toolbar);

    }
````

{{% /tab %}}
{{% tab title="onCreateOptionsMenu" style="info" color="blue " %}}

````java
@Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.content_menu,menu);
        return super.onCreateOptionsMenu(menu);
    }
````

{{% /tab %}}
{{% tab title="onOptionsItemSelected" style="info" color="blue " %}}

````java
@Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
    //获取menu目录中content_menu.xml文件里item的id
        int id = item.getItemId();
    //判断id是否被点击，被点击就执行相应的动作，比如页面跳转
        if(id == R.id.content_menu_add_friend){
            Intent intent = new Intent(OpetionsMenu.this,ListDialogActivity.class);
            startActivity(intent);
        }else if(id == R.id.content_menu_group_chat){
            return  super.onContextItemSelected(item);
        }
        return false;
    }
````

{{% /tab %}}
{{% tab title="全码" style="default" color="green " %}}

````java
package com.example.practiceapplication;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

public class OpetionsMenu extends AppCompatActivity {
    private Toolbar toolbar;
    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.opetions_menu);
        toolbar = findViewById(R.id.options_menu_toolbar);
        setSupportActionBar(toolbar);

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.content_menu,menu);
        return super.onCreateOptionsMenu(menu);
    }
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        int id = item.getItemId();
        if(id == R.id.content_menu_add_friend){
            Intent intent = new Intent(OpetionsMenu.this,ListDialogActivity.class);
            startActivity(intent);
        }else if(id == R.id.content_menu_group_chat){
            return  super.onContextItemSelected(item);
        }
        return false;
    }
}
````

{{% /tab %}}
{{< /tabs >}}

## 最终结果

{{% notice style="secondary" icon="eye" title="结果" %}}
![8899](abc.jpg?classes=shadow,border&height=250px&width=15vw)
{{% /notice %}}

{{% expand %}}详细知识等我更新……{{% /expand %}}
