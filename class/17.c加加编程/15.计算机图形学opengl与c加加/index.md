# 15.计算机图形学OpenGL与C&#43;&#43;

## 理解GLFW和GLAD

### GLFW（）

GLFW是一个开源的、跨平台的库，用于创建窗口、处理输入和渲染图形。它提供了一种简单的方式来与OpenGL进行交互，使得开发图形应用程序变得更加容易。

GLFW的主要功能包括：

- 创建窗口
- 定义上下文
- 处理用户输入

### GLAD（）

GLAD是一个开源的、跨平台的库，用于管理OpenGL的函数指针。它提供了一种简单的方式来获取OpenGL的函数指针，使得开发OpenGL应用程序变得更加容易。

相关说明：

- OpenGL本身知识规范/标准
- 各个厂家具体实现方式可以不同
- 不同操作系统处理方式也可以不同

主要功能：

- 获取OpenGL函数指针
- 处理OpenGL版本兼容性问题
- 处理OpenGL扩展函数
……

如果没有GLAD库，在Windows下：

```c++
typedef void (*GL_GENBUFFER) (GLsizei,GLuint*);//声明函数指针
GL_GENBUUFFER glGenBuffer = (GL_GENBUFFER)wglGetProcAddress('glGenBuffer');//获取函数指针
unsigned int buffer;//声明缓冲区对象
glGenBuffer(1,&buffer);//调用函数
```

有了GLAD库，只需要：

```c++
unsigned int buffer;
glGenBuffer(1,&buffer);
```


{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}