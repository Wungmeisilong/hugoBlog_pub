# 基于C&#43;&#43;的职工管理系统

## 项目需求

![alt text](image.png)

## 项目功能

![alt text](image-1.png)

## 开始项目开发

### 1.创建管理类

#### 管理类功能

管理类负责内容
![alt text](image-2.png)

#### 实现代码

添加头文件：

```cpp
#pragma once //防止头文件重复包含
#include <iostream>

using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
};
```

添加源文件：

```cpp
#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
}

WorkerManager::~WorkerManager()
{
}
```

### 2.添加菜单功能

#### 添加菜单显示函数

```h
class WorkerManager
{
public:
	WorkerManager();
  void Show_Menu();
	~WorkerManager();
};
```

#### 显示菜单界面

```h
void WorkerManager::Show_Menu()
{
	cout << "*************************" << endl;
  cout << "***欢迎使用职工管理系统******" << endl;
  cout << "*****  0-退出管理程序  *****" << endl;
	cout << "*****  1-增加职工信息  *****" << endl;
	cout << "*****  2-显示职工信息  *****" << endl;
	cout << "*****  3-删除职工信息  *****" << endl;
	cout << "*****  4-修改职工信息  *****" << endl;
	cout << "*****  5-查找职工信息  *****" << endl;
	cout << "*****  6-按照编号排序  *****" << endl;
  cout << "*****  7-清空所有文档  *****" << endl;
	cout << "*************************" << endl;
}
```

#### 测试菜单界面

```cpp
#include <iostream>
using namespace std;
#include "workerManager.h"

int main()
{
	WorkerManager wm;
	wm.Show_Menu();
	system("pause");
	return 0;
}
```

### 3.退出功能

#### 添加退出功能

```cpp
class WorkerManager
{
public:
	WorkerManager();
  void Show_Menu();
  void ExitSystem();
	~WorkerManager();
};
```

#### 实现退出功能

```cpp
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
```

#### 测试退出功能

```cpp
int main()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu(); //显示菜单
		cout << "请输入您的选择： " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //增加职工
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //按照编号排序
			break;
		case 7: //清空文件
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls"); //清屏操作
			break;
		}
	}
	system("pause");
	return 0;
}
```

### 4.编写职工类

将三个职工抽象为一个类，利用多态管理不同职工；
职工属性行为：
职工行为：

#### 写worker.h头文件

```h
#pragma once
#include <iostream>
using namespace std;
#include <string>
//职工抽象类
class Worker
{
public:
	//显示个人性息
	virtual void showInfo() = 0;
	//获取岗位个人性息
	virtual string GetDeptName() = 0;
	//职工编号
	int m_Id;
	//职工姓名
	string m_Name;
	//部门编号
	int m_DeptId;

};
```

#### 写employee.h、manager.h、boss.h头文件

```h
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"
//职工类
class Employee:public Worker
{
public:
	Employee(int id,string name,int did);
	//显示个人性息
	void showInfo();
	//获取岗位个人性息
	string GetDeptName();
};
```

#### 写employee.cpp等源文件

```cpp
#include "employee.h"//不同岗位此处不同

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人性息
void Employee::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;

}
//获取岗位个人性息
string Employee::GetDeptName()
{
	return string("员工");//不同岗位此处不同
}
```

#### 在主函数中测试

```cpp
Worker* worker = new Employee(20, "张三", 3);
worker->showInfo();
delete worker;

worker = new Manager(10, "李四", 2);
worker->showInfo();
delete worker;

worker = new Boss(1, "王五", 1);
worker->showInfo();
delete worker;
```

### 5.添加职工

#### 添加成员函数

```cpp
class WorkerManager
{
public:
	WorkerManager();
  void Show_Menu();
  void ExitSystem();
  void Add_Emp();
	~WorkerManager();
};
```

#### 实现添加职工

```cpp
void WorkerManager::Add_Emp()
{
	cout << "添加职工" << endl;
	int id;
	string name;
	int dId;
	cout << "请输入职工编号" << endl;
	cin >> id;
	cout << "请输入职工姓名" << endl;
	cin >> name;
	cout << "请输入职工部门编号" << endl;
	cin >> dId;
	Worker* worker = nullptr;
	switch (dId)
	{
	case 1:
		worker = new Boss(id, name, dId);
		break;
	case 2:
		worker = new Manager(id, name, dId);
		break;
	case 3:
		worker = new Employee(id, name, dId);
		break;
	default: //输入错误 
		cout << "输入错误" << endl;
		system("pause");
		system("cls");
		return;
	}
	//将创建的职工放到vector中
	m_Vec.push_back(worker);
	cout << "添加职工成功" << endl;
	system("pause");
	system("cls");
}
```

#### 测试添加职工


{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}