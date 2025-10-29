# C语言基础知识

{{% resources color="fuchsia" icon="fab fa-hackerrank" /%}}

## c01-cFirstLearning

### 01-printHello.c

```c
#include <stdio.h>
int main()
{
    printf("Hello World\n");//\n 换行,转义字符
    printf("Hello World\n");//\n 换行,转义字符
    return 0;
}   

//c语言的源代码、源程序
//编译成可执行文件才可以运行
//gcc 01-printHello.c  进行编译得到可执行文件
//./a.out  运行可执行文件   ./a.exe     windows下
```

### 02-printChinese.c

```c
#include <stdio.h>
int main()
{
    printf("中文\n");
    return 0;
}   
```

### 03-printChinese-gb18030.c

```c
#include <stdio.h>
int main()
{
    printf("??\n");
    return 0;
}
```

### 04-printChinese-gb2312.c

```c
#include <stdio.h>
int main()
{
    printf("??\n");
    return 0;
}   
```

### 05-gb232.c

```c
#include <stdio.h>
int main()
{
    printf("ÄãºÃ ÖÐ¹ú  ÖÐÎÄ\n"); 
    return 0;
}
```

### 06-printChineseMenu.c

```c
#include <stdio.h>
int main(){
    printf("┏━━━━━━━━━━欢迎使用学生管理系统━━━━━━━━━━┓\n");
	printf("┃             1、学生登录                ┃\n");
	printf("┃             2、管理员登录              ┃\n");
	printf("┃             0、退出                    ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

/*
制表符
─ ━│┃╌╍╎╏┄┅┆┇┈┉┊┋┌┍┎┏┐┑┒┓└┕┖┗  ┘ ┙┚┛├┝┞┟┠┡┢┣┤┥┦┧┨┩┪┫┬┭┮┯┰┱┲┳┴┵┶┷ ┸ ┹ ┺ ┻ ┼┽┾┿╀╁╂╃╄╅╆╇╈╉╊╋╪╫╬ ═║╒╓╔╕╖╗╘╙╚╛╜╝╞╟╠╡╢╣╤╥╦╧╨╩╔╗╝╚╬═╓╩┠┨┯┷┏┓┗┛┳⊥﹃﹄┌╮╭╯╰╳
*/
```

### 07-xiegangMaohao/_.c

```c
#include <stdio.h>
int main()
{
    printf("Hello World\n");
    printf("I say:\"hello!\"\n"); //\"  表示"，转义字符
    printf("\\n\n");  // \\表示\，转义字符
}
```

## c02-cBaseLearning

### 00.c

```c
#include <stdio.h>
int main(){
    printf("Hello\n");
    printf("World \n");
    printf("abcd\n");
    printf("\nHello\n   1\  
        World\n");// \n 换行符 
}
```

### 01printAllType.c

```c
#include <stdio.h>//std标准，io输入输出。标准输入输出头文件

int main(){
    printf("hello world\n你好中国\n");//\n转义字符
    printf("\n*************\n");//字符串
    
    printf("200\n");//字符串:由数字、字母和各种标点与下划线等组成的序列，可以是0个或多个字符组成，ascii码表中的字符或者汉字等组成。
    printf("1+1\n");//字符串

    //使用printf打印特定类型的数据

    printf("1+1=%d\n",1+1);//%d占位符，格式字符串,%d打印十进制整数，分正负，有符号int类型整数

    printf("10+100=%d\n",10+100);//%d占位符，格式字符串
    printf("%d\n",1000*100);//%d占位符，格式字符串
    printf("%d---%d\n",1000*100,1+2);
    printf("%d,%d\n",1000*100);//第二个占位数对应的数据不确定，此行代码有警告

    printf("%d,%u\n",0xFFFFFFFF,0xFFFFFFFF);//%d有符号数，%u无符号数
    printf("%d,%d\n",0x80000000,0x7FFFFFFF);//int 32位，有符号数的范围是-2147483648~2147483647

    printf("%u,%u\n",0,0xFFFFFFFF);//unsigned int 32位，无符号基本型数的范围是0~4294967295
    printf("%ld,%ld\n",0x8000000000000000,0x7FFFFFFFFFFFFFFF);//long 64位，有符号数的范围是-9223372036854775808~9223372036854775807
    //%ld有符号长整型数

    //每种类型所占的字节数
    printf("sizeof(short)：%lu\n",sizeof(short));//%lu无符号长整数,sizeof 计算给定的类型占用多少字节
    printf("sizeof(int)：%lu\n",sizeof(int));//%lu无符号数
    printf("sizeof(long)：%lu\n",sizeof(long));//%lu无符号数
    printf("sizeof(long long)：%lu\n",sizeof(long long));//%lu无符号数

    printf("sizeof(float)：%lu\n",sizeof(float));//%lu无符号数
    printf("sizeof(double)：%lu\n",sizeof(double));//%lu无符号数
    
    printf("8.4/2.0=%f\n",8.4/2.0);//%f输出单精度小数用的占位符，默认小数点后6位
    printf("8.4/2.0=%.1f\n",8.4/2.0);//.1表示小数点后保留1位
    printf("8.4/2.0=%g\n",8.4/2.0);//%g输出浮点数时自动选择小数点后的位数
    printf("8.4/2.0=%e\n",8.4/2.0);//%e输出科学计数法

    printf("8.4/2.0=%lf\n",8.4/2.0);//%lf输出双精度小数
    
    float f =  897.332458722222222;//单精度浮点数变量f
    double d = 897.332458722222222;//双精度浮点数变量d
    printf("%.14f\n",f);
    printf("%.14lf\n",d);


    printf("%c\n",'A');//%c输出char类型字符
    printf("%c\n",66);//编号是66的ascii字符
    printf("%c\n",'A'+32);//转小写

    printf("%d\n",'A');//ascii编号 
    printf("%c\n",'0');//字符0
    printf("%d\n",'0');//字符0的ascii编号48
    printf("%d\n",0);//数值0
    printf("|%c|\n",0);//ascii码是0的字符，空字符
    printf("|%c|\n",32);//ascii码是32的字符是空格
    printf("|%c|\n",' ');//打印空格

    printf("\"\\n\n");//\n转义字符
    
    

    printf("20\n");

    printf("%d\n",20);//十进制。%d表示十进制整数  占位符/格式字符串
    printf("%X\n",10);//十六进制0-9、A-F
    printf("%x\n",10);//十六进制a-f
    printf("%o\n",20);//八进制
    

    printf("%d\n",0x41);//把十六进制数0x41转换成十进制整数打印出来
    printf("%c\n",0x41);//把十六进制数0x41转换成字符打印出来
    printf("%c\n",0103);//把八进制数101转换成字符打印出来

    return 0; 


//c语言的源代码、gcc编译得到到可执行文件，运行可执行文件
}
```

### 02print_int.c

```c
#include<stdio.h>
int main(){
    int num1 = 10; // int类型变量num1,字面常量10,num1赋值为10
    short num2 = 20; // short类型变量 num2，字面常量20
    long num3 = 30; // long类型变量 num3，字面常量30
    long long num4 = 40; // long long类型变量num4
    //变量名的命名规则：只能使用字母、数字、下划线，不能以数字开头，区分大小写，不能使用关键字
    //用户标识符：变量名、函数名、数组名、结构体成员等统称为用户标识符

    // 打印结果
    printf("num1: %d\n", num1);
    printf("num2: %hd\n", num2);//short类型用%hd
    printf("num3: %ld\n", num3);
    printf("num4: %lld\n", num4); 

    num1 = 20;
    printf("num1: %d\n", num1);
    printf("num1+num2=%d\n", num1+num2);
    return 0;
} 
```

### 03int_printf_scanf.c

```c
#include <stdio.h>
int main()
{
    int num1 = 0;
    short num2 = 0;
    // 程序运行后，给变量输入一个值
    printf("请输入一个整数：");
    scanf("%d", &num1);//&num1表示将变量num1的地址传给scanf函数(后面会详细讲&符号),//scanf中不要使用\n
    printf("请输入一个短整数：");
    scanf("%hd", &num2);//scanf中不要使用\n
    // 打印结果
    printf("num1: %d,\nnum2: %hd\n", num1, num2);
    printf("和是:%d\n", num1 + num2);
    return 0;
}
```

### 04print_float.c

```c
#include <stdio.h>
int main()
{
    float num1 = 3.14;    // float类型变量num1
    double num2 = 1.2345; // double类型变量num2
                          // 打印结果
                          
    printf("num1: %f\n", num1);
    printf("num2: %lf\n", num2);

    num1 = 20.14;//改变了变量的值  
    num2 = 100.2357; //改变了变量的值  
                            // 打印结果
    printf("num1: %.2f\n", num1);// 保留小数点后两位
    printf("num2: |%10.2lf|\n", num2);// 保留小数点后两位，宽度为10, 右对齐
    printf("num2: |%-10.2lf|\n", num2);// 保留小数点后两位，宽度为10,左对齐
    return 0;
}
```

### 05float_scanf.c

```c
#include <stdio.h>
int main()
{
    float num1 = 3.5;    // float类型变量num1
    double num2 = 1.2345; // double类型变量num2
    // 程序运行后，给变量输入一个值
    printf("请输入两个小数：");
    scanf("%f%lf", &num1, &num2);//scanf中不要使用\n
    // 打印结果
    printf("num1: %f\n", num1);
    printf("num2: %lf\n", num2);

    return 0;
}
```

### 06sizeof.c

```c
#include <stdio.h>
int main(){
    int a = 10;
    printf("%lu\n", sizeof(a));//4,sizeof(a)含义：a空间占用的字节数,%lu表示输出无符号长整型
    printf("%lu\n", sizeof(int));//sizeof(int)含义：int类型空间占用的字节数

    
    return 0;
}
```

### 07define.c

```c
#include <stdio.h>
#include <math.h>
//字面常量

// 符号常量PI,后面不要有分号
#define PI 3.1415926

int main() {
    printf("PI = %f\n", PI);
    printf("PI = %.2f\n", PI);// 保留小数点后两位
    //PI = 3.14;// 错误，不能对符号常量赋值
    printf("半径是100的圆的面积：  %.2f\n", PI*100*100);
    
    printf("半径是100的圆的面积：  %.2f\n", M_PI*100*100);//M_PI是原生的圆周率，系统定义好的。包含对应了头文件<math.h>就可以使用了
    return 0;
}
```

### 08print_char.c

```c
#include <stdio.h>
int main() {
    printf("%c\n",'a');//输出a,%c是字符类型
    printf("%d\n",'a');//输出97,%d是整型,输出ascii码

    //'0'是字符，48是整型
    printf("%c\n",'0');//输出0字符0
    printf("%d\n",'0');//输出48
    printf("%d\n",0);//输出0数值0
    printf("%d\n",'A');//输出65

    printf("d:\\mingw64\n");
    printf("I say:\"Hello,World!\"\n");
    return 0;
}
```

### 09char_scanf.c

```c
#include <stdio.h>
int  main()
{
    char ch1 = 'A'; // char类型变量
    char ch2 = 65;  // 使用ASCII码值来初始化字符变量
                    // 程序运行后，给变量输入一个值
    printf("请输入两个字符：");
    scanf("%c%c", &ch1, &ch2); // 输入两个字符时不要有空格，//多输入的数据会放到键盘缓冲区里，后面再有scanf函数调用输入字符时，会先从键盘缓冲区中读取数据
    // 打印结果
    printf("ch1: %c\nch2: %c\n", ch1, ch2);

    printf("请输入第三个字符：");
    scanf("%c", &ch1);//在%c前面加一个空格，可以忽略前面的空白字符（包括换行符）
    printf("ch1:%c~~~~~\n", ch1);

    //清空缓冲区所有数据
    while (getchar() != '\n');//后面会详细讲
    
    printf("请输入第四个字符：");
    scanf("%c", &ch1);
    printf("ch1:%c======\n", ch1);
    return 0;
}
```

### 10/n/t/r.c

```c
#include<stdio.h>
int main(){
    // 换行符 \n
    printf("我没有换行");
    printf("我开始换行啦\n");//回车换行
    
    //\r 表示光标移到当前行的开头
    printf("hello,World!\r");//光标移到行首不换行
    printf("1234\n");
    printf("12\b34\n");//\b 退格键
    
    //制表位 对齐作用(tab键作用) 
    printf("Name\t\tAge\tCity\n");
    printf("Johnggggggg\t25\tNew York\n");
    printf("Emily\t\t28\tLondon\n");
    printf("Tom\t\t30\tParis\n");

    /*
    多行注释
    多行注释
    多行注释
    */
    
    return 0;
}
```

## c03-cOperatorDetailExplanation(1)

### 01+-_.c

```c
#include <stdio.h>
int main() {
    int a = 5;
    int b = 3;
    //1、加法运算符（+）
    int c = a + b;   
    printf("c=%d\n", c);
    //2、减法运算符（-）
    c = a - b;   
    printf("c=%d\n", c);
    //3、乘法运算符（*）
    c = a * b;   
    printf("c=%d\n", c);
    return 0;
}
```

### 02int+float.c

```c
#include <stdio.h>
int main(){
    int a = 10;
    float b = 2.5;
    //printf("%d\n",a + b);//有警告，类型不一致，打印结果不正确。
    
    printf("%f\n",a + b);
    printf("%g\n",a + b);
    printf("%e\n",a + b);

    printf("%e\n",0.007);
    printf("%E\n",0.007);

    printf("%f\n",2e5);
    printf("%e\n",1234e3);

    a = 20;
    b = 30;//隐式类型转换,自动类型提升，从int转为float
    //printf("%d\n",a + b);//有警告，类型不一致，打印结果不正确。
    printf("%f\n",a + b);
    printf("%g\n",a + b);
    printf("%e\n",a + b);

    return 0;
}

// char--->short ----> int ----> long ----> float ---> double
```

### 03div.c

```c
#include <stdio.h>
int main(){
    //4、除法运算符（/）:当两个操作数都是整数时，结果也是整数,结果如果有小数则丢弃。不进行四舍五入。
    //属于整除运算。

    //至少有一个操作数是浮点数时，结果才是浮点数，不是整除运算，浮点除法。

    int a = 7 / 4;//整除运算
    printf("a:%d\n",a);//1

    float b = 5 / 4;//整除运算
    printf("b:%f\n",b);//1.000000
 
    float c = 5.0 / 4;//浮点数除法
    printf("c:%f\n",c);//1.250000

    int e = 5 / 4.0;//（隐式自动转换）小数部分会被舍弃
    printf("e:%d\n",e);//1

    int d = 6 / 4.0;////浮点数除法.（隐式自动转换）小数部分会被舍弃，也不进行四舍五入。
    printf("d:%d\n",d);//1

    float g = 5 / (float)4;//（强制转换）（显式自动转换）
    printf("g:%f\n",g);//1.250000

    float f = (float)(5 / 4);//（强制转换）（显式自动转换）
    printf("f:%f\n",f);//1.000000

    int k = 5,t = 4;//按数学方式计算k/t的实际结果，需要使用强制类型转换
    float h = (float)k / t;//（强制转换）;
    printf("h:%f\n",h);

    h = k / (float)t;//（强制转换）;
    printf("h:%f\n",h);
    
    h = 1.0 * k / t;// 不能写成 k / t * 1.0；
    printf("h:%f\n",h);

    int x = 'a';//（隐式自动转换）
    printf("x:%d\n",x);
    printf("x+1:%c\n",x + 1);
    printf("'a'+2:%c\n",'a' + 2);
    return 0;
}
```

### 04%.c

```c
#include <stdio.h>
// 5、取模运算符（%）（取余运算）：两个整数相除，取余数，取模运算符
//小数不能做取模运算
int main()
{
    int a = 5 % 3;
    printf("a:%d\n", a);//2

    int b = 3 % 5;
    printf("b:%d\n", b);//3

    //float c = 5.0 % 3.0;//error:%只能是整数参与运算
    // printf("c:%f\n", c);
/*
多行注释
*/

    return 0;
}
```

### 05use%.c

```c
/*
1、获取一个三位整数中的每一位数字（拆分数字、分解数字）       
   例如：235 ：个位5，十位3 百位2
                                 
    235 / 1 % 10    得个位5
    235 / 10  % 10  得十位3		
    235 / 100 % 10  得百位 2
    
2、计算判断奇偶数
    XX % 2
3、判断一个数能被另一个数整除
    X % Y
*/
#include <stdio.h>
int main()
{
    int num = 875;
    printf("num = %d\n", num);

    // 方法1：获取一个整数中的每一位数字,使用%10
    int a2 = num  % 10;//    个位
    int b2 = num / 10 % 10 ;//十位
    int c2 = num / 100 ;//百位
    printf("%d\n%d\n%d\n\n", a2, b2, c2);

    // 方法2：获取一个整数中的每一位数字,不使用%
    int a = num / 100;//百位
    int b = (num - a * 100) / 10;//十位
    int c = num - a * 100 - b * 10;//个位
    printf("%d\n%d\n%d\n\n", a, b, c);

    // 方法3：获取一个整数中的每一位数字,使用%10和%100
    int a1 = num % 10;//个位
    int b1 = num % 100 / 10;// 十位
    int c1 = num / 100;//百位
    printf("%d\n%d\n%d\n\n", a1, b1, c1);

    return 0;
}
//水仙花数：一个三位数的各位数字的立方和等于该数本身。
//例如：153 = 1*1*1 + 5*5*5 + 3*3*3 = 1 + 125 + 27 = 153

//自幂数：一个n位数，它的每个位上的数字的n次幂之和等于它本身。
```

### 06++=.c

```c
//06-自增并赋值
//++、--   是自增、自减操作符，操作符只能用来对变量进行操作的。单目运算符
#include <stdio.h>
int main()
{
    int num1 = 5;
    // ++在变量的右边，后边
    int a = num1++;//<======> int a = num1;num1 = num1 + 1;
    printf("a:%d\n",a);//5
    printf("num1:%d\n",num1);//6
    

    int num2 = 5;
    // ++在变量的左边，前面
    int b = ++num2;//<======> num2 = num2 + 1;int b = num2;
    printf("b:%d\n",b);//6
    printf("num2:%d\n",num2);//6
}
```

### 07++print.c

```c
//07-自增并打印
 #include <stdio.h>
 int main(){

    int num1 = 5;
    printf("~~~~~num1:%d\n", num1++);//先打印，后自增//5
    printf("------num1:%d\n", num1);//6

    int num2 = 5;
    printf("num2:%d\n", ++num2);//先自增，后打印//6
    printf("num2:%d\n", num2);//6
 
 }
```

### 08+++.c

```c
//08-自增并做算术运算
#include <stdio.h>
int main()
{
   int num1 = 5;
   printf("(num1++) + 3:%d\n", num1++ +3);//8
   printf("num1:%d\n", num1);//6

   int num2 = 5;
   printf("++num2 + 3:%d\n", ++num2 + 3);//9
   printf("num2:%d\n", num2);//6

//当++在变量前时，先自增运算，再使用这个变量做其它操作
//当++在变量后时，先使用这个变量做其它操作，再自增运算

    int a = 10, b = 20;
    int c = a++ + ++b;//c=(10)+(21)=31
    printf("a:%d\nb:%d\nc:%d\n", a, b, c);//a:11, b:21, c:31

}
```

### 09gcc++warning.c

```c
//09-不同编译器结果可能不同
#include <stdio.h>
int main(void)
{
    int a = 5;
    int b = (++a) + (a++) + (++a) + a;
    //      （6） + （6） +（8） +（8） 
    //   a:6（6）  (6) a:7  a:8 (8)  (8)
    //不同的编译器可能有不同的解析方式，结果可能不同。

    printf("a=%d\n", a);
    printf("b=%d\n", b);

    a = 5;
    int t1 = ++a;
    int t2 = a++;
    int t3 = ++a;
    int t4 = a;
    int t = t1 + t2 + t3 + t4;
    printf("t=%d,a=%d\n", t,a);

     int n = 1;
     printf("%d %d\n",n++, ++n + ++n + ++n); //输出1 12或者其它结果，不同编译器可能不同
     printf("%d\n",n);
    
    return 0;
}
```

### 10=.c

```c
#include <stdio.h>
int main()
{
    int a = 10;//赋值运算
    int b = (a = 20) + 30;//a=20赋值运算的结果是变量a的值
    printf("a = %d, b = %d\n", a, b);//20,50

    short c = 32767;//-32768~32767
    c += 1;//c = c+1    //溢出:表示整数溢出，结果为-32768
    printf("%hd\n", c);//-32768 
    printf("%d\n", (int)c);//-32768
    printf("~~~~~%hu\n", c);//32768  //unsigned short c:%hu表示无符号的short类型0~65535
    unsigned short cc = 32767;
    cc++;
    printf("%hu\n", cc);//32768

    int d = 32767;
    d += 1;
    printf("%d\n", d);//32768  

    int e = 2000000000;
    e += 2000000000;
    printf("%d\n", e);//-294967296//溢出  //有符号数打印
    printf("%u\n", e);//4000000000//无符号数打印unsigned int :%u表示无符号的int类型0~4294967295

    int x = 10;
    printf("%d\n", x);
    int y = x = 100;//可以连写
    printf("%d,%d\n", x,y);

    //int t = u = v = w = 200;//error：u,v,w都是变量名,变量没有定义，不能连写
    
    return 0;
}
```

### 11_=.c

```c
#include <stdio.h>
int main()
{
    int x = 10;
    int y = 20;

    int a = x > y;//关系运算的运算结果只有0或1：假、不对、错、不成立用0，真、对、成立用1
    printf("x>y:%d\n", a);//0
    int b = x < y;
    printf("x<y:%d\n", b);//1
    int c = x == y;
    printf("x==y:%d\n", c);//0
    int d = x >= y;
    printf("x>=y:%d\n", d);//0
    int e = x != y;
    printf("x!=y:%d\n", e);//1
    int f = x <= y;
    printf("x<=y:%d\n", f);//1

    printf("10>8>6:%d\n", 10 > 8 > 6);
    //0,不能按数学方式计算，都是大于号，从左向右计算

    printf("10==10<6:%d\n", 10 == 10 < 6);
    //0,先算10<6，再算==
    
    return 0;
}
```

### 12getMax.c

```c
//10-键盘输入两个整数，打印输出较大的数及其平方
#include <stdio.h>
#include <math.h>
int main() {
    int a = 0,b = 0;
    printf("请输入两个整数：");
    scanf("%d%d",&a,&b);
    printf("两个数中的最大数是：%d\n", a > b ? a : b );//如果a>b成立，结果是冒号左边的a，否则结果是冒号右边的b
    printf("两个数中的最大数的平方是：%d\n", a < b ? b*b : a*a );
    printf("两个数中的最大数的平方是：%d\n", a > b ? a*a : b*b);
    
    printf("两个数中的最大数的10次方是：%f\n", (a > b) ? pow(a,10) : pow(b,10));
    printf("两个数中的最大数的10次方是：%g\n", a > b ? pow(a,10) : pow(b,10));

    printf("两个数中的最大数的3次方是：%f\n", (a > b) ? pow(a,3) : pow(b,3));
    printf("两个数中的最大数的3次方是：%g\n", a > b ? pow(a,3) : pow(b,3));
    printf("%f\n", sqrt(100));
    printf("%g\n", sqrt(100));//开方，默认是开2次方
    printf("%f\n", sqrt(2));
    printf("%g\n", sqrt(2));
    return 0;
}
```

### 13getMax2.c

```c
//10-键盘输入两个整数，求出较大的整数,如果输入小数或者非数字，要进行判断
#include <stdio.h>
#include <math.h>
int main() {
    int a = 0,b = 0;
    char c = 0;
    printf("请输入两个整数(使用空格分隔)：");
    
    int n = scanf("%d%d%c",&a,&b,&c);//scanf()函数返回值是从键盘实际读取到数据的变量的个数
    printf("a = %d,b=%d,c=%d,c=%c\n", a,b,c,c);
    printf("n = %d\n", n);

    n == 3?(c != '\n' ? printf("输入数据错误！\n"):printf("两个数中的最大数是：%d\n", a > b ? a : b )):printf("-----输入数据错误！！\n");

    n != 3?printf("-----输入数据错误！！\n"):
    (c == '\n' ? printf("两个数中的最大数是：%d\n", a > b ? a : b ):printf("输入数据错误！\n"));

    n == 3?(c != '\n' && c != ' ' && c!='\t' ?printf("~~~~输入数据错误！\n"):printf("~~~两个数中的最大数是：%d\n", a > b ? a : b )):printf("~~~~----输入数据错误！！\n");

    n == 3?(c == '\n' || c == ' ' || c=='\t' ?printf("~~~两个数中的最大数是：%d\n", a > b ? a : b ):printf("~~~~输入数据错误！\n")):printf("~~~~----输入数据错误！！\n");

    return 0;
}
```

### 14oddEven.c

```c

#include <stdio.h>
int main() {
    printf("偶数\n");
    printf("%s","偶数\n"); //%s是字符串的意思

    int a = 0;//不初始化时，a的是值是不确定的。一般不推荐使用。要初始化。
    printf("请输入一个整数：");
    //方法1
    scanf("%d",&a);
    printf("~~~~~%d是%s\n",a, (a % 2 == 0?"偶数":"奇数"));
    //%s是字符串的意思，%d是整数的意思。
    
    //方法2
    //scanf("%d",&a);
    a % 2 == 0 ? printf("%d是偶数\n",a):printf("%d是奇数\n",a);
    a % 2 != 0 ? printf("%d是奇数\n",a):printf("%d是偶数\n",a);

    //方法3
    //scanf("%d",&a);
    a % 2 ? printf("%d是奇数\n",a):printf("%d是偶数\n",a);
     //在c语言中，非0数据都为真,视为成立，0为假,视为不成立 

    //方法4:非法数据进行了判断
    scanf("%d",&a) == 1 ? printf("%d是%s\n",a, (a % 2 == 0?"偶数":"奇数")):printf("输入数据错误！！\n");
    
    
    scanf("%d",&a) == 1 ? printf("%d是%s\n",a, (a % 2 != 0?"奇数":"偶数")):printf("输入数据错误！！\n");
    
    scanf("%d",&a) == 1 ? printf("%d是%s\n",a,(a % 2?"奇数":"偶数")):printf("输入数据错误！！\n");
    
    return 0;
}
```

## c04-cOperatorDetailExplanation(2)

### 00-hw.c

```c
#include <stdio.h>

int main(){
  // float a;
  // printf("请输入一个浮点数：\n");
  // scanf("%f",&a);
//方法一
//   int b = a*1000;
//   int flag = b>0?1:-1;//标志变量，正数1，负数-1
//   b = b*flag;
  
//   b%10>=5?b+=10:b;
//   b/=10;
//   a = b/100.0;

//   a = a*flag;


//方法二
    // a = (int)(a*100 + (a>0?0.5:-0.5))/100.0;

    // printf("%.2f\n",a);
    // printf("%g\n",a); 

//方法三

  float n = 0;

  printf("输入一个浮点数：");

  scanf("%f", &n);//1.23678

  int t1 = n * 1000;//t1 = 1236

  int t = t1 - t1 / 10 * 10;//  t = t1 % 10;//t = 6
  printf("t:%d\n", t);
  t = n > 0 ? t : -t;
  t1 = t >= 5 ? t1 / 10 + (n > 0 ? 1 : -1) : t1 / 10;

  float r = t1 / 100.0;

  printf("%f->%f\n", n, r);

  return 0;

}
```

### 01&&.c

```c
//01-判断成年男性
#include <stdio.h>
//逻辑运算符:&& 逻辑与

// 成年男性

int main()
{
    // 年龄>=18
    int age = 20;
    // 性别 男：M 女：F
    char gender = 'M';

    int flag = (age >= 18) && (gender == 'M');//逻辑与&&：两个条件都成立，结果为真

    printf("%s\n", flag == 1 ? "是成年男性" : "不是成年男性");
    
    printf("%s\n", flag ? "是成年男性" : "不是成年男性");
    //非0数据为真，表示成立；0数据为假，表示不成立

    printf("%s\n", (age >= 18) && (gender == 'M') ? "是成年男性" : "不是成年男性");

    (age >= 18) && (gender == 'M') ? printf("是成年男性\n") : printf("不是成年男性\n");
    return 0;
}
```

### 02__.c

```c
#include<stdio.h>
//֧支付方式
int main(){

   char pay = 't';//'w'微信 'z'支付宝

   int flag = (pay == 'w') || (pay == 'z');//逻辑或：||，或者，表示有一个成立结果就成立

    printf("%s\n",flag==1?"线上支付成功":"线上支付失败");
    printf("%s\n",flag?"线上支付成功":"线上支付失败");
    
    printf("用%s支付\n",(pay == 'w')?"微信":(pay == 'z'?"支付宝":"现金方式"));//与下面写法相同

    printf("用%s支付\n",pay == 'w'?"微信":pay == 'z'?"支付宝":"现金方式");
    printf("用%s支付\n",pay == 'z'?"支付宝":pay == 'w'?"微信":"现金方式");

    return 0;
}
```

### 03!.c

```c
#include<stdio.h>
//逻辑非  !  取反运算，把真变成假，把假变成真,单目运算符
int main(){

   int result = 2 > 1;
   printf("%d\n",result);//1

   //反对
   int flag = !result;//逻辑非
   printf("flag:%d\n",flag);//0

    int f = !200;//200是一个非0数据，表示真,成立
    printf("!200:%d\n",f);//0

    f = !0;//0表示假，不成立
    printf("!0:%d\n",f);//1

    f = !'\0';//'\0'表示假  ascii值为0的字符为空字符NULL
    printf("!'\\0':%d\n",f);//1

    f = !'0';//'0'表示真,ascii码是48，非0数据表示真，成立
    printf("!'0':%d\n",f);//0

    
    printf("!2>3:%d\n",!2>3);
    //0
    //先计算逻辑非，再计算比较.按优先级高级进行计算
    
    printf("!(2>3):%d\n",!(2>3));
    //1
    //先计算比较，再计算逻辑非

    printf("(!2)>3:%d\n",(!2)>3);
    //0
    //先计算逻辑非，再计算比较
    
    return 0;

}
```

### 04leapYear.c

```c
#include <stdio.h>

//判断闰年,以下两个条件，有一个成立，就是闰年
//1.能被4整除，但不能被100整除
//2.能被400整除
int main(){

   int year = 2000;//1904;//2000,1900,1901

   int flag = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

   printf("%d年%s闰年\n",year,flag==1?"是":"不是");

printf("%d年%s闰年\n",year,(year%4 == 0 && year%100 != 0)||(year%400==0)?"是":"不是");

    return 0;

}
```

### 05shortCircuiting..c

```c
//05-短路运算规则
//对于逻辑与&&和逻辑或||来说，当第一个操作数能够确定整个表达式的值时，就不会计算第二个操作数。
#include <stdio.h>
int main(){
    int a = 1;
    int b = 2;
    int c = 3;
    c = a > 3 || (b = 4);// 0||4  ---->1
    printf("a = %d\n", a);//1
    printf("b = %d\n", b);//4
    printf("c = %d\n", c);//1

    c = 0;
    c = (a > -3) || (b = 40);//对于逻辑或来说，第一个操作数1>-3成立，整个表达式的结果就是成立的，所以第二个操作数不会被计算,这就是短路运算规则
    printf("a = %d\n", a);//1
    printf("b = %d\n", b);//4, 说明第二个操作数没有被计算
    printf("c = %d\n", c);//1

    c = a > 3 && (b = 400);//对于逻辑与来说，第一个操作数1>3不成立，结果已经确定了，所以第二个操作数不会被计算,这就是短路运算规则
    printf("a = %d\n", a);//1
    printf("b = %d\n", b);//4, 说明第二个操作数没有被计算
    printf("c = %d\n", c);//0

    c = (b = 400) && (a = 3);//没有短路运算
    printf("a = %d\n", a);//3,说明第二个操作数被计算了
    printf("b = %d\n", b);//400
    printf("c = %d\n", c);//1

    a = 1;
    c = (b = 0) && (a = 3);//短路运算
    printf("a = %d\n", a);//1，短路运算
    printf("b = %d\n", b);//0
    printf("c = %d\n", c);//0

    return 0;
}
```

### 06_____.c

```c
//06-左移右移运算符
#include<stdio.h>

//左移、右移运算符

int main(){

    //左移
    int a1 = 4;
    int b1 = a1 << 3;
    printf("b1:%d\n",b1);//32
    
    int a5 = 1073741824;
    int b5 = a5 << 2;
    printf("b5:%d\n",b5);//0
    

    int a4 = 24;
    int b4 = a4 >> 3;
    printf("b4:%d\n",b4);//3


    //右移:有符号数右移，符号位不变，高位补符号位
    int a2 = -1073741824;//int范围：-21亿多~21亿多
    int b2 = a2 >> 3;
    printf("b2:%d\n",b2);


    int a6 = -1;
    int b6 = a6 >> 20;
    printf("b6:%d\n",b6);

    //-1的二进制为11111111111111111111111111111111
    //无论右移多少位，都为11111111111111111111111111111111
    
    unsigned int a3 = 3373741824;//无符号数右移，高位补0, unsigned int 范围0~42亿多
    unsigned b3 = a3 >> 3;
    printf("b3:%u\n",b3);
    b3 = a3 >> 31;
    printf("b3:%u\n",b3);

    int aaa = 0xFFFFFFFE;
    int bbb = aaa >> 2;
    printf("bbb:%d\n",bbb);
    printf("bbb:%X\n",bbb);
    return 0;
}
```

### 07bitOperation.c

```c
//07-按位与或非异或运算
#include<stdio.h>

// 位操作符
int main(){

    //1、按位与 &
    int a1 = 3;
    int b1 = 5;
    int c1 = a1 & b1;//a1 && b1 计算原理不同
    printf("c1:%d\n",c1);

   

    //2、按位或
    int a2 = 3;
    int b2 = 5;
    int c2 = a2 | b2;//a1 || b1 计算原理不同
    printf("c2:%d\n",c2);

    
    
    //3、异或操作
    int a4 = 3;
    int b4 = 5;
    int c4 = a4 ^ b4;
    printf("c4:%d\n",c4);

    //4、按位取反
    int a3 = 3;//有符号整数，分正负
    int b3 = ~a3;////有符号整数，分正负
    printf("b3:%d\n",b3);//-4
    printf("b3:%u\n",b3);//4294967292
    unsigned int b33 = ~a3;//无符号整数，不分正负
    printf("b33:%u\n",b33);//4294967292
    printf("b33:%d\n",b33);//-4
    
    return 0;
}
```

### 08swap.c

```c
//08-交换两个变量的值
#include <stdio.h>
// 交换
int main()
{

  int a = 100;
  int b = 200;
  
  printf("交换前：a = %d b = %d\n", a, b); 
  // 方法一
  int t = a; 
  a = b;
  b = t;
  printf("交换后：a = %d b = %d\n", a, b);

  // 方法二
  a = 100;
  b = 200;
  a = a + b;//300
  b = a - b;//100
  a = a - b;//200
  printf("交换后：a = %d b = %d\n", a, b);
  
  a = -100;
  b = 200;
  a = a + b;//100
  b = a - b;//-100
  a = a - b;//200
  printf("交换后：a = %d b = %d\n", a, b);
  
  // 方法三
  a = 100;
  b = 200;
  a = a ^ b; // 用其它二进制直接验证：110 ^  010 = 100
  b = a ^ b; // 用其它二进制直接验证：100 ^  010 = 110
  a = a ^ b; // 用其它二进制直接验证：100 ^  110 = 010
  printf("交换后：a = %d b = %d\n", a, b);

  return 0;
}
```

### 09(int).c

```c
//09-强制类型转换
#include<stdio.h>
//强制转换
int main(){

    int a = 10;
    float b = 3.84;
    int c = 0 ;

  
    c = b;//隐式转换：自动把float类型转换成了int型
    printf("隐式转换：c:%d\n",c);
    printf("b:%f\n",b);
      
    //float 强制转换位int
    c = (int)b;//显式转换：手动把float类型转换成了int型
    printf("显式转换：c:%d\n",c);
    printf("b:%f\n",b);

    //相加后强制转换
    c = (int)(a+b);
    printf("c:%d\n",c);
   
   int x = 30;
   printf("%d\n",x/4);
   printf("%f\n",(float)x/4);//此时要得出正确结果，就需要使用强制类型转换

    float y = 30.2;
    printf("%d\n",(int)y % 4);
    return 0;
}
```

### 10,.c

```c
//10-逗号运算符
#include<stdio.h>
//逗号表达式
int main(){
//表达式：在c中，表达式是用来计算值的。
//什么是表达式：由c的运算符和运算对象组成。

    
    int a = 1, b = 2, c = 3;

    //逗号表达式
    int d = (a++, b++, ++c, a + b + c); //d=XXX 赋值表达式 ，括号中的是逗号表达式
    printf("a=%d\n",a);//a=2
    printf("b=%d\n",b);//b=3
    printf("c=%d\n",c);//c=4
    printf("d=%d\n",d);//d=9
    
    a = 1,b = 2,c = 3;//语句：语句是用来控制程序运行的
    printf("~~~%d\n",(a = 1, b = 2, c = 3));

    d = a++, b++, ++c, a + b + c;//等号优先级高，先计算等号
    printf("a=%d\n",a);//a=2
    printf("b=%d\n",b);//b=3
    printf("c=%d\n",c);//c=4
    printf("d=%d\n",d);//d=1
 
    //1+1;

    a = 1, b = 2, c = 3;//语句：语句是用来控制程序运行的
    printf("%d\n",(d = a++, b++, ++c, a + b + c));//等号优先级高，先计算等号
    printf("a=%d\n",a);//a=2
    printf("b=%d\n",b);//b=3
    printf("c=%d\n",c);//c=4
    printf("d=%d\n",d);//d=1


    return 0;
}
```

### 11question.c

```c
//11-提问的问题.c:我想问那个短路运算规则，与运算&&第一个表达式为假，但后面有或运算的时候怎么办

//(A && B || C)
//A如果为假,B不会执行，C要执行。

#include<stdio.h>
int main(){
    int a = 2,b = 0,c = 0;
    (a = 0) && (b = 5) || (c = 10);//&&有短路运算，A为false,B不会执行，C要执行
    printf("a= %d ,b = %d,c = %d\n",a,b,c);//a=0,b=0,c=10

    a = 2,b = 0,c = 0;
    (a = 20) || (b = 5) && (c = 10);//||有短路运算，A为true,B不执行，C也不执行
    printf("a= %d ,b = %d,c = %d\n",a,b,c);//a=20,b=0,c=0

    a = 2,b = 0,c = 0;
    (a = 20) || ((b = 5) && (c = 10));//||有短路运算，A为true,B不执行，C也不执行。同上
    printf("a= %d ,b = %d,c = %d\n",a,b,c);//a=20,b=0,c=0

    a = 2,b = 0,c = 0;
    ((a = 20) || (b = 5)) && (c = 10);//||有短路运算，A为true,B不执行，C执行
    printf("a= %d ,b = %d,c = %d\n",a,b,c);//a=20,b=0,c=10
}
```

## c05-if-else-switch-for-while-do-while

### 01if.c

```c
//01-if第一种格式
#include<stdio.h>
// if的第一种格式:单分支结构
int main(){

    //定义一个年龄
    int age = 27;
    //判断
    if(age >= 18) {
        printf("我可以上网吧玩游戏啦\n");
        printf("哈哈哈\n");
    }
    printf("时间过的真快啊\n");
    
    return 0;
}
```

### 02isLeapYear.c

```c
//01-if第一种格式
#include<stdio.h>
//判断闰年

int main(){
    int year = 0;
    printf("请输入年份：");
    scanf("%d",&year);

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        printf("%d是闰年！\n",year);
    }

    if(!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))){
        printf("%d不是闰年！\n",year);
    }
    return 0;
}
```

### 03isOddEven.c

```c
//03-判断奇偶性
#include<stdio.h>
//判断奇偶性

int main(){
    int num = 0;
    printf("请输入一个数字：\n");
    scanf("%d",&num);

    //判断奇偶性
    if(num % 2 == 0){
        printf("%d是偶数\n",num);
    }

    if(num % 2 != 0){
        printf("%d是奇数\n",num);
    }
    
    if(num % 2 == 1  || num % 2 == -1){
        printf("%d是奇数\n",num);
    }
    
    if(num % 2){//非0就是真，此时真就是1或者-1
        printf("%d是奇数\n",num);
    }
    
    if(!(num % 2 == 0)){
        printf("%d是奇数\n",num);
    }

    if(!(num % 2)){
        printf("%d是偶数\n",num);
    }
    return 0;
}
```

### 04if_else.c

```c
//04-if的第二种格式
#include <stdio.h>
// if的第二种格式
int main()
{
    int age;
    printf("请输入您的年龄：");
    scanf("%d", &age);

    // 判断年龄
    if (age >= 18)
    {
        printf("恭喜您，您成年啦\n");
        printf("请这边购票\n");
    }
    else
    {
        printf("小朋友，你还没成年\n");
        printf("可以免费游玩\n");
    }

    printf("祝您玩的愉快\n");

    return 0;
}
```

### 05isOddEven.c

```c
//05-判断奇偶性双分支
#include<stdio.h>
//判断奇偶性

int main(){
    int num = 0;
    printf("请输入一个数字：\n");
    scanf("%d",&num);
    //方法一
    if(num % 2 == 0){
        printf("%d是偶数\n",num);
    }else{
        printf("%d是奇数\n",num);
    }
    //方法二
    if(num % 2 == 1 || num % 2 == -1){
        printf("%d是奇数\n",num);
    }else{
        printf("%d是偶数\n",num);
    }
//尝试写出其它判断方法，并比较哪种方法更简单

    return 0;
}
```

### 06if_else_if.c

```c
//06-if的第三种格式
#include <stdio.h>
// if的第三种格式

int main()
{
    int score = 0;
    printf("请输入一个成绩(0~100)：\n");
    scanf("%d", &score);
    printf("~~~~~~\n");
    // 方法一
    if (score > 100 || score < 0)
    {
        printf("数据不合法！！！\n");
    }
    else if (score >= 90)
    {
        printf("奖励自行车一辆\n");
    }
    else if (score >= 80)
    {
        printf("变形金刚一个\n");
    }
    else if (score >= 70)
    {
        printf("游乐场游玩一天\n");
    }
    else if (score >= 60)
    {
        printf("黄冈试卷一套\n");
    }
    else
    {
        printf("皮带炒肉丝\n");
    }

    printf("***********\n");

    // 方法二：分支结构嵌套
    if (score > 100 || score < 0)
    {
        printf("数据不合法！！！\n");
    }
    else if (score >= 80)
    {
        if (score >= 90)
        {
            printf("奖励自行车一辆\n");
        }
        else
        {
            printf("变形金刚一个\n");
        }
    }
    else 
    {
        if (score >= 60)
        {
            if (score >= 70)
            {
                printf("游乐场游玩一天\n");
            }
            else
            {
                printf("黄冈试卷一套\n");
            }
        }
        else
        {
            printf("皮带炒肉丝\n");
        }
    }
    // 练习：方法三:补充完整以下代码
    /*

    if (score > 100 || score < 0)
    {
        printf("数据不合法！！！\n");
    }
    else if (score >= 60){
        _____补充完整代码______________
    }
    else{
        ______补充完整代码_____________
    }
    ......
    ......
    */

    return 0;
}
```

### 07switch.c

```c
//07-switch格式
#include <stdio.h>
// switch

int main()
{
    int num = 0;
    printf("输入数字1-7：\n");
    scanf("%d", &num);
    // switch
    switch (num)
    {
    case 1:
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");
        break;
    case 5:
        printf("星期五\n");
        break;
    case 6:
        printf("星期六\n");
        break;
    case 7:
        printf("星期日\n");
        break;
    default:
        printf("输入数字错误\n");
    }
    return 0;
}
```

### 08caseFallthrough.c

```c
//08-case的穿透性
#include <stdio.h>
// 输入月份1-12,输出季节

// case穿透性

int main()
{
    int month = 0;
    printf("输入月份1-12:\n");
    scanf("%d", &month);

    switch (month)
    {
//冗余代码，可以去掉，使用switch穿透性，去掉冗余代码
    case 3:
    case 4:    
    case 5:
        printf("Spring\n");
        break;
    case 7:
    case 6:
    case 8:
        printf("Summer\n");
        break;
    case 9:
    case 10:
    case 11:
        printf("Autumn\n");
        break;
    case 12:
    case 1:
    case 2:
        printf("Winter\n");
        break;
    default:
        printf("您输入的月份有误，请重新输入\n");
    }

    // 输入一个成绩,0-100,输出等级A(>=90)、B(>=80)、C（>=70）、D(>=60)、E(<60)
    int score = 0;
    printf("输入一个成绩,0-100:\n");
    scanf("%d", &score);
    if (score < 0 || score > 100)
    {
        printf("您输入的成绩有误，请重新输入\n");
        return 0; // 结束当前函数，不执行下面的代码
    }
    
    switch (score / 10)
    { // 使用score/10,取整，会使得case情况变少，简化代码
    case 10:
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 6:
        printf("D\n");
        break;
    default:
        printf("E\n");
    }
    return 0;
}
```

### 09forPrint1_10.c

```c
//09-for输出1-10
#include <stdio.h>
int main(){
    
    int i = 1;
    for(;i <= 10;i++){///循环三要素：初始条件、循环条件、迭代条件。变量i的初始值是1，循环条件是i<=10，迭代条件是i++。
    //循环变量的变化：初值、终值、步长。
        printf("%02d：hello world\n",i);
    }
    printf("for-end:%d\n",i);

    for(int i = 10;i >= 1;i--){
        printf("%d\n",i);
    }
    
    //打印1-10
    for(int i = 100;i <= 109;i++){
        printf("%d\n",i-99);
    }
    //打印1-10
    for(int i = -100;i <= -91;i++){
        printf("~~~%d\n",i+101);
    }
    //打印1-10
    for(int i = 0;i <= 9;i++){
        printf("%d\n",i+1);
    }
    return 0;
}
```

### 0printPerfectNumber.c

```c
//0-输出10000以内的完数
#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    for (int n = 2; n <= 10000; n++)
    {
        sum = 0;
        for (i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                sum = sum + i;
            }
        }
        if (sum == n)
        {
            printf("%d是完数,%d=", n,n);
            for(i=1;i<n;i++){
                if(n%i==0){
                    printf("%d+",i);
                }
            }
            printf("\b \n");
        }
    }
    return 0;
}
```

### 10forPrint1_100sum.c

```c
//10-for输出1-100累加和
#include <stdio.h>
int main(){

    long long s = 0;//累加和变量
    // s = s+1;
    // s = s+2;
    // s = s+3;
    // //.......
    // s = s+100;  
    // printf("for end:s=%d\n",s);
    // s = s+1+2+3+4+......+100;

    for(int i = 1;i <= 100;i++){//初值、终值、步长
        printf("i=%d,s=%lld\n",i,s);
        s = s + i;//累加和:0+1+2+3+4+......+100
        printf("i=%d,s=%lld\n\n",i,s);
    }
    printf("for end:s=%lld\n",s);
    return 0;
}
```

### 11forPrint1_100EvenSum.c

```c
//11-for输出1-100偶数和
#include <stdio.h>
int main()
{
    // 1-100偶数和与奇数和
    //方法一
    int s = 0,t = 0;
    for(int i = 1;i <= 100;i++){
        if(i % 2 == 0){
            s = s + i;//偶数和
        }
        else{
            t += i;//奇数和
        }
    }
    printf("偶数和：s=%d\n",s);
    printf("奇数和：t=%d\n",t);
 
   //方法二
    s = 0,t = 0;
    for (int i = 2; i <= 100; i += 2)
    {
        s = s + i; // 偶数和
        t = t + (i - 1);//奇数和
    }
    printf("~~~~~偶数和s=%d\n", s);
    printf("~~~~~奇数和t=%d\n", t);
   
   //方法三
    s = 0,t = 0;
    for (int i = 1; i <= 100; i += 2)
    {
        s = s + (i+1); // 偶数和
        t = t + i;//奇数和
    }
    printf("偶数和s=%d\n", s);
    printf("奇数和t=%d\n", t);

    //方法四
    s = 0,t = 0;
    for (int i = 1; i <= 50; i++)
    {
        s = s + i*2; // 偶数和
        t = t + i*2-1;//奇数和
    }
    printf("偶数和s=%d\n", s);
    printf("奇数和t=%d\n", t);
    return 0;
}
```

### 12printDataCount.c

```c
//12-统计满足条件的数字的个数
/*
需求：键盘录入两个整数，表示一个范围。
           统计这个范围中
           既能被3整除，又能被5整除的整数有多少个？
*/
#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    int count = 0; // 计数器
    printf("请输入表示范围的两个整数：");
    scanf("%d%d", &a, &b);//30 80//90 10
    //方法一
    // if (a < b)
    // {
    //     for (int i = a; i <= b; i++)
    //     {
    //         if (i % 3 == 0 && i % 5 == 0)
    //         {
    //             printf("%d ", i);
    //             count++; // 计数器加1
    //         }
    //     }
    // }
    // else  //a > b
    // {
    //     for (int i = a; i >= b; i--)//for(int i = b;i <= a;i++)
    //     {
    //         if (i % 3 == 0 && i % 5 == 0)
    //         {
    //             printf("%d ", i);
    //             count++; // 计数器加1
    //         }
    //     }
    // }

    // 方法二
    if (a > b)
    { // 此代码用来保证a小于b.如果a>b就交换a和b的值，保证a小于b.
        int t = a;
        a = b;
        b = t;
    } // 用来保证a小于b
    
    for (int i = a; i <= b; i++)
    {
        if (i % 15 == 0)
        {
            printf("%d ", i);
            count++; // 计数器加1
        }
    }
    printf("\n在%d到%d范围内，既能被3整除，又能被5整除的整数有%d个。\n", a, b, count);
    return 0;
}
```

### 13printFoldCount.c

```c
//13-打印折纸的次数
/*
需求：世界最高山峰是珠穆朗玛峰(8844.43米=8844430毫米)，
假如我有一张足够大的纸，它的厚度是0.1毫米。
请问，我对折折叠多少次，可以折成珠穆朗玛峰的高度?
*/
#include <stdio.h>
int main(){
    float n = 0.1;
    int count = 0;//计数器
    while (n < 8844430)
    {
        n = n * 2;
        printf("n=%.2f\n",n);
        count++;
    }
    printf("count=%d\n",count);

//用for实现以上功能
    float f = 0.1;
    int count2 = 0;
    for(;f < 8844430;)
    {
            f *= 2;//f=f*2
            printf("for:f=%.2f\n",f);
            count2++;
    }
    printf("count2=%d\n",count2);
    return 0;
}
```

### 14do_whileOddSum.c

```c
//14-使用do...while循环求1～100奇数和
#include <stdio.h>
int main()
{
    int i = 1;
    int t = 0;
    // 方法一
    do
    {
        if (i % 2 != 0)
        {
            t += i; // 奇数和
        }
        i++;//++i;
    } while (i <= 100);
    printf("1~100奇数和是：%d\n", t);

    // 方法二
    i = 1;
    t = 0;
    do
    {
        t += i; // 奇数和
        i += 2; // i = i + 2;
    } while (i <= 100);
    printf("1~100奇数和是：%d\n", t);

    // 方法三
    i = 1;
    t = 0;
    do
    {
        t += i; // 奇数和
    } while ((i += 2) <= 100);
    printf("1~100奇数和是：%d\n", t);

    // 方法四
    i = 1;
    t = 0;
    do
    {
        if (i % 2 != 0)
        {
            t += i; // 奇数和
        }
        //++i;//i++;
    } while ( ++i <= 100);//与 i++ <= 100不同,会多加一个101
    printf("1~100奇数和是：%d\n", t);
    return 0;
}
```

### 15InfiniteLoop.c

```c
//15-死循环
#include <stdio.h>
int main() {
    // while (1) {
    //     printf("while\n");
    // }

    // float i = 1;
    // for (;;i *= 1.0001) {//无限循环,for没有写条件，属于成立，即无限循环的一种写法。死循环
    //     printf("%f\n",i);
    // }
    
    // do{
    //     printf("do--while\n");
    // }while(1);

    return 0;
}
```

### 16-continue.c

```c
//16-continue
#include <stdio.h>
int main()
{

    for (int i = 1; i <= 5; i++)
    {
        if (i == 3)
        {
            continue;//提前结束本次循环，剩余的循环体语句不再执行，继续开始下一次循环，for执行i++,while和do~while执行循环条件判断
        }
        printf("吃第%d个包子\n", i);
    }

    return 0;
}
```

### 17-break.c

```c
//17-break
#include <stdio.h>
int main()
{

    for (int i = 1;i <= 5; i++)
    {
        printf("吃第%d个包子\n", i);
        if (i >= 3)
        {
            break;//跳出循环,提前结束循环
        }  
    }

    return 0;
}
```

### 18guessNumberGame.c

```c
//18-猜数字小游戏
/*
《游戏说明》
1、系统生成一个1～100之间的随机数，命名：rn
2、用户输入一个数字，命名：num
3、比较两者的大小，输出三种结果。
    您猜大啦
    您猜小啦
    您猜对啦
4、如果猜错了，可以一直猜，直到猜中为止
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    // srand(time(NULL));         
    // // // 随机数种子,不使用time(NULL)的话每次运行程序，
    // // //则随机数种子都一样，产生随机数序列也都一样
    
    // int  rn = rand();//rand()函数产生一个随机数，返回值是一个随机数
    // printf("rn = %d\n", rn);
    // rn = rand();
    // printf("rn = %d\n", rn);
    // rn = rand();
    // printf("rn = %d\n", rn);
    // rn = rand();
    // printf("rn = %d\n", rn);


    srand(time(NULL));        
    int rn = rand() % 100 + 1; // rand() % 100 + 1 产生1-100之间的随机数
    // 计算公式：如果要产生[A,B]之间的随机整数，
    // 则：rand() % (B - A + 1) + A
    // 例如产生及格的成绩分数：60-100分之间的随机整数，
    // 则：rand() % (100 - 60 + 1) + 60   
    // ----> rand() % 41 + 60
    
    int num = 0;
    printf("请输入一个你猜的数字(1~100)：");
    scanf("%d", &num);

    while (1)
    {
        if (num > rn)
        {
            printf("您猜大了\n");
        }
        else if (num < rn)
        {
            printf("您猜小了\n");
        }
        else
        {
            printf("恭喜您，猜对了！rn = %d\n", rn);
            break;
        }
        printf("请再输入一个你猜的数字：");
        scanf("%d", &num);
    }
    return 0;
}
//使用rand()函数产生随机数,完成人与电脑进行石头、剪刀、布的游戏
```

### 19loopPrintMenu.c

```c
//19-循环打印项目菜单
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num = 0;
    while (1)
    {
        system("clear"); // linux下使用"clear",windows下用"cls"  清屏命令  
        printf("┏━━━━━━━━━━欢迎使用学生管理系统━━━━━━━━━━┓\n");
        printf("┃             1、学生登录                ┃\n");
        printf("┃             2、管理员登录              ┃\n");
        printf("┃             0、退出                    ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"); 
        printf("请选择编号[0-2]：");
        scanf("%d", &num);
        if (num == 0)
        {
            printf("退出系统\n");
            exit(0);//退出程序 。return 0 也行，退出函数。exit(0);也行，退出程序。break;也行，跳出循环。
        }
        else if (num == 1){
            printf("学生登录\n");
            getchar();//char ch; scanf("%c",ch)//清空键盘缓存区中的一个字符包括回车键
            printf("按回车键继续........");
            getchar();
        }
        else if (num == 2){
            printf("管理员登录\n");
            while(getchar()!='\n');//清空键盘缓存区中的所有字符包括回车键
            printf("按回车键继续........");
            getchar();
        }
        else{
            printf("输入错误\n");
            while(getchar()!='\n');//清空键盘缓存区中的所有字符包括回车键
            printf("按回车键继续........");
            getchar();
        }   
    }

    return 0;
}
/*
单线细线制表符
┌ ┐ └ ┘ ┴ ┬ ├ ┤ ┼ ─ │

单线粗线制表符
┏ ┓ ┗ ┛ ┻ ┳ ┣ ┫ ╋ ━ ┃

粗细线结合制表符
┍ ┎ ┏   ┑ ┒ ┓   ┕ ┖ ┗   ┙ ┚ ┛   ┵ ┸ ┶ ┹ ┺ ┷ ┻   ┭ ┰ ┮ ┱ ┲ ┯ ┳   ┦ ┧ ┥ ┪ ┩ ┨ ┫   ┝ ┞ ┟ ┠ ┡ ┢ ┣   ╀ ╁ ┽ ┾ ╂ ┿ ╃ ╄ ╅ ╆ ╇ ╈ ╉ ╊ ╋

双线制表符
╔ ╗ ╚ ╝ ╩ ╦ ╠ ╣ ╬ ═ ║

单双线结合制表符
╓ ╖ ╙ ╜ ╨ ╥ ╟ ╫ ╢ ╒ ╕ ╘ ╛ ╧ ╤ ╞ ╪ ╡
 */
```

### 20armstrongNumber.c

```c
//20-自幂数
#include <stdio.h>
#include <math.h>
// 自幂数：一个n位正整数，它的各位数字的n次方和等于它本身。
// 求出1到输入的正整数之间的所有自幂数
int main()
{
  int sxhs = 0, z = 0, sum = 0;
  printf("请输入一个正整数:");
  scanf("%d", &sxhs);//99999
  printf("自幂数如下：\n");
  for (int i = 1; i <= sxhs; i++)//
  { // 从1到输入的正整数，依次判断是否为自幂数

    // 1、计算i是几位数
    z = i;//897
    int n = 0; // n表示位数
    while (z != 0)
    {          // 计算位数
      n++;     // 位数加1
      z /= 10; // 去掉最后一位
    }

    // 2、计算各位数字的n次方和
    z = i;
    sum = 0; // sum表示各位数字的n次方和
    while (z != 0)
    {                               // 计算各位数字的n次方和
      sum += pow((z % 10), n); // 计算各位数字的n次方和
      z /= 10;
    }

    // 3、判断是否为自幂数
    if (i == sum)
    { // 如果等于本身，则输出
      printf("%d\n", i);
    }
  }
  return 0;
}
```

## c06-function

### 00-hw.c

```c
#include <stdio.h>
#include <math.h>
int main()
{

    int a = 0;//统计个数，记数器

    int b = 1;

    while (b <= 999999999)
    {
        int temp = b;
        int c = 0;//总和
        int n = 0;//位数
        //计算b的位数
        while (temp != 0)
        {
	    n++;
            temp /= 10;
        }
        //计算b的各位数的n次方之和
        temp = b;
        while (temp != 0)
        {
            c += pow(temp % 10, n);
            temp /= 10;
        }
        //判断是否为自幂数
        if (c == b)
        {
            printf("%d\n", b);
            a++;
        }
        b++;
    }
    //打印总个数
    printf("\n从1~%d之间共有%d个自幂数.\n", b,a);
    return 0;
}
```

### 01functionDefineCall.c

```c
//01-函数定义和调用
#include <stdio.h>
#include <math.h>
#include <ctype.h>

//函数定义
//定义一个打印n行星号的函数
void printNLinesStar(int n)//打印n行星号,n为参数,形式参数
{ // 定义了有参无返回值的函数 
    for (int i = 1; i <= n; i++)
    {
        printf("printNLinesStar:**************\n");
    }
}

//定义一个求两个整数和的函数
int getSum(int a,int b)//形参
{ // 定义了有两个参数并有返回值的函数
    int sum = a + b;
    return sum;//返回值。意味着sum值作为返回值返回给调用者。放到调用函数的栈中，放到调用的地方。
}

//当函数定义在main后面，或者定义在其它文件中时，需要先声明，再调用
void printStar();


//int是main()的返回值类型，与return 0;相对应。
int main()//主函数是程序入口函数
{   
    //调用函数
    printStar();
    printf("111111\n");
    printStar();
    printf("222222\n");
    
    printNLinesStar(3);//3是实参，实际参数，调用函数传参给形式参数n
    printf("33333333\n");
    printNLinesStar(10);//10是实参，实际参数
    printf("\n");
    //调用函数
    int sum1 = getSum(1, 2);//实参1,2
    int num1 = 10;
    int num2 = 20;
    int sum2 = getSum(num1, num2);
    int sum3 = getSum(100, 200) + 400;
    printf("%d,%d,%d\n", sum1, sum2, sum3);
    printf("%d\n", getSum(1000, 2000));
    printf("%d\n", getSum(1.7, 3.4));//有警告

    return 0;
}



//定义一个打印三行星号的函数
void printStar()//没有形式参数，无形参，无参，
//void无类型，没有类型
{ // 定义了无参无返回值的函数，无返回值是指函数不会计算出来一个结果。

    printf("***********\n");
    printf("********\n");
    printf("**************\n");
    //return ;//可省略
}





```

### 02getDaysFunction.c

```c
//02-封装年月获取天数的函数
#include <stdio.h>
//根据给定的年和月返回天数,如果输入的月份有误则返回-1,否则返回天数.编写此函数
int getDays(int year,int month){
    switch (month)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        return 31;
        //break;
    case 4:case 6:case 9:case 11:
        return 30;
    case 2:  
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
            return 29;
        } 
        else{
            return 28;
        }
    default:
        return -1;
    } 

}
int main(){
    int year = 2000;
    int month = 20;
    
    int days = getDays(year,month);
    if( days == -1){
        printf("输入月份有误~~~\n");
    }
    else{
        printf("%d年%d月有%d天！\n",year,month,days);
    }
    
    printf("请输入年和月：");
    scanf("%d%d",&year,&month);
    days = getDays(year,month);
    if( days == -1){
        printf("输入月份有误~~~\n");
    }
    else{
        printf("%d年%d月有%d天！\n",year,month,days);
    }
    return 0;
}
```

### 03-ATM.c

```c

#include <stdio.h>
#include <string.h> //字符串处理函数对应的头文件
#include <stdlib.h>//能使用exit(0)退出程序功能

// 全局变量money，在函数外定义，表示余额。
// 在定义时，赋初值。在此之后定义的所有函数中，可以直接使用。
int money = 1000;

// 查询功能
void search_Money()
{
    printf("您现在的余额是：%d\n", money);
}


// 存款功能
void save_Money(int save_money)
{
    // 存钱
    money += save_money;
    // 调用查询功能
    search_Money();
}

// 取钱
int get_Money(int get_money)
{

    if (get_money > money)
    {
        printf("您的余额不足\n");
        return 0; // 返回0，表示失败
    }
    else
    {
        money -= get_money;
        search_Money();
        return 1; // 返回1，表示成功
    }
}

void ATMSystem()
{
    // 为了保证系统一直运行，采用while死循环
    int flag = 1; // 局部变量
    int choose = 0;
    while (flag)
    {
        printf("----------------主菜单----------\n");
        printf("您好，欢迎来到职坐标银行ATM系统，请选择您的操作：\n");
        printf("1、查询余额\n");
        printf("2、存款\n");
        printf("3、取款\n");
        printf("4、退出系统\n");
        printf("请输入您的选项【1-4】：");
        // 键盘录入
        scanf("%d", &choose);

        // switch
        switch (choose)
        {
        case 1:
            // 查询功能
            printf("查询功能\n");
            search_Money();
            break;
        case 2:
            // 存款功能
            printf("存款功能\n");
            int save_money = 0;
            printf("请输入您要存的金额：\n");
            scanf("%d", &save_money);
            save_Money(save_money);
            break;
        case 3:
            // 取款功能
            printf("取款功能\n");
            int get_money = 0;
            printf("请输入您的取款金额：\n");
            scanf("%d", &get_money);
           
            int num = get_Money(get_money);
            if (num == 1)
            {
                printf("取款成功\n");
            }
            else
            {
                printf("取款失败\n");
            }
            break;
        case 4:
            // 退出功能
            // printf("退出功能\n");
            flag = 0;
            printf("欢迎您的再次使用\n");
            //exit(0);
            break;
        default:
            printf("您输入的指令有误，请重新输入\n");
            break;
        }
    }
}

int main()
{

    // int count = 3;
    // int flag = 1;
    // while (flag)
    // {

    //     printf("欢迎来到职坐标ATM，请输入您的用户名和密码\n");
    //     char username[20];
    //     char password[20];

    //     // 输入用户名
    //     printf("请输入用户名：");
    //     scanf("%s", username);

    //     // 输入密码
    //     printf("请输入密码：");
    //     scanf("%s", password);

    //     // 验证用户名和密码
    //     if (strcmp(username, "zhangsan") == 0 && strcmp(password, "123456") == 0)
    //     {
    //         printf("登录成功！\n");
            ATMSystem();
            
    //     }
    //     else
    //     {
    //         printf("用户名或密码错误！\n");
    //         count--;
    //         printf("您还有%d次机会", count);
    //         if (count == 0)
    //         {
    //             flag = 0;
    //             printf("卡被冻结，请联系大仁老师\n");
    //         }
    //     }
    // }
    return 0;
}
```

### 04recursiveFunctionFactorial.c

```c
//04-递归函数计算阶乘
#include <stdio.h>
//使用递归函数计算n阶乘
int fac(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * fac(n-1);
}

//使用递归函数计算1~n的和
int sum(int n){
    
    if(n == 1){
        return 1;
    }
    return n + sum(n-1);
    
}

int main(){
    printf("%d\n",fac(0));
    printf("%d\n",fac(5));

    printf("%d\n",sum(5));
    printf("%d\n",sum(100));
}

//使用循环和递归都可以解决，但递归的效率更高

//感兴趣的话：汉诺塔问题 经典的递归问题


```

### 05printMultiplicationTable.c

```c
//05-打印九九乘法表
#include <stdio.h>
void printf99(){
    int i, j;
    for(i=1; i<=9; i++){//外层循环控制行数,从1到9,总共9行
        for(j=1; j<=i; j++){//内层循环控制每行打印的式子个数,从1到i
            printf("%dx%d=%-4d", j, i, i*j);
        }
        printf("\n");
    }
}

int main(){
    printf99();
}

//API简写：应用程序编程接口（Application Programming Interface）
//API是计算机程序设计领域中的一个概念，它定义了程序设计人员与计算机硬件、软件、操作系统等交互时，程序员与计算机硬件、软件、操作系统之间的通信协议，即定义了程序员与计算机硬件、软件、操作系统之间的接口。
```

### 06globalLocal.c

```c
//06-全局变量与局部变量共存
#include <stdio.h>
int a = 10;
int main()
{
    printf("~~~a = %d\n", a);
    int a = 20;
    printf("---a = %d\n", a);
    {
       int a = 30;
       printf("******a = %d\n", a);
    }
    printf(".......a = %d\n", a);
    {
        extern int a;//告诉编译器，a是外部变量，全局变量
        printf("******a = %d\n", a);
        a = 100;
        printf("******a = %d\n", a);
    }
    printf(".......a = %d\n", a);
    {
        extern int a;//告诉编译器，a是外部变量，全局变
        printf("XXXX******a = %d\n", a);
    }
    return 0;
}
```

## c07-array

### 00monkeyEatPeaches.c

```c
//00-猴子吃桃
#include <stdio.h>
int cp(int days){
    if(days == 1) {
        return 1;
    }
    return (cp(days-1)+1)*2;
}

int cp2(int days){
    if(days == 10) {
        return 1;
    }
    return (cp2(days+1)+1)*2;
}
int main() {
    printf("桃子数是：%d\n", cp(10));
    printf("桃子数是：%d\n", cp2(1));
}
```

### 01defineArray.c

```c
//01-数组定义
#include <stdio.h>
int main(){
    int arr1[4] = {25,26,27,28};
    //定义一个int型数组，有四个元素，每个元素都是int型

    double arr2[5] = {1.82,1.85,1.92,1.95,2.14};
    //定义一个double型数组，有5个元素，每个元素都是double型

    printf("arr1[0],arr1[3]：%d,%d\n",arr1[0],arr1[3]);
    //输出数组元素,下标从0开始，第0个元素为25，第3个元素为28

    printf("arr2[1],arr2[4]：%lf,%lf\n",arr2[1],arr2[4]);
    //输出数组元素,下标从0开始，第0个元素为1.82，第4个元素为2.14

    printf("%e,%e\n",arr2[1],arr2[4]);
    printf("%g,%g\n",arr2[1],arr2[4]);
    //用%g输出，会根据数值大小自动选择一种比较合适的短的格式输出
    
    //下标越界情况，输出不确定的值。
    printf("%f,%f\n",arr2[5],arr2[14]);//超出数组范围，输出不确定的值。下标从0开始，第5个元素不存在，第14个元素不存在。
    return 0;
}
```

### 02accessArrayElements.c

```c
//02-遍历数组所有元素
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printfArray(int a[],int n) {
    for(int i = 0; i < n; ++i) {
        printf("%d ", a[i]); // 遍历数组a中的所有元素:打印
    }
    printf("\n");
}

int main() {
    int a[10]; // 定义一个长度为10的数组a
    printf("a[0]:%d\n", a[0]); // 访问数组a中的第一个元素，未初始化，不确定a[0]的值
    printf("%lu\n", sizeof(a)); // 输出数组a的空间大小,即数组a所占的内存空间大小，占用多少字节
    printf("%lu\n", sizeof(a[0])); // 输出数组a中a[0]元素的空间大小,占用多少字节
    printf("%lu\n", sizeof(a)/sizeof(a[0])); // 输出数组a中元素的个数。数组长度
    printf("~~~~~~\n");
    
    int b[] = {23,45,56,7,4,3,4,5,6,55,34,5,56,88,44,234,1,2,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    // for(int i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    //     printf("%d ", b[i]); // 遍历数组b中的所有元素:打印
    // }
    int n = sizeof(b)/sizeof(b[0]);
    printfArray(b,n);

    printf("=======\n");

    for(int i = 0; i < n; i++) {
        b[i] = 100; // 遍历数组b中的所有元素：修改
    }
    b[5] = 800;

    printfArray(b,n);
    // for(int i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    //     printf("%d ", b[i]); // 遍历数组b中的所有元素
    // }
    printf("~~~~~~\n");

    int total = 0;
    for(int i = 0; i < n; ++i) {
        total += b[i]; // 遍历数组b中的所有元素：求和
    }
    printf("total = %d\n", total);

    srand(time(NULL)); // 初始化随机数种子 
    for(int i = 0; i < n; ++i) {
        //b[i] = rand() % 101; // 遍历数组b中的所有元素：随机赋值0~100
        b[i] = rand() % 41 + 60; // 遍历数组b中的所有元素：模拟及格分数赋值60~100
    }
    
    // for(int i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    //     printf("%d ", b[i]); // 遍历数组b中的所有元素
    // }
    printfArray(b,n);

    printf("\n");

    //统计b数组中有多少个元素能被3整除
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(b[i] % 3 == 0) {// 遍历数组b中的所有元素：判断
            count++;
            printf("%d ", b[i]);
        }
    }
    printf("\n");
    
    printf("count = %d\n", count);

    //统计每个分数有几个人
    int c[101] = {0};// 定义一个长度为101的数组c，并初始化为0,用来保存每个分数段的人数。即c[60]保存分数是60分的人数，c[61]保存分数为61分的人数......
    for(int i = 0; i < n; ++i) {
        /*
        if(b[i]==60){
            c[60]++;//c[60]++等同于c[b[i]]++;
        }
        else if(b[i]==61){
            c[61]++;//c[61]++等同于c[b[i]]++;
        }
        else if(b[i]==62){
            c[62]++;//c[62]++等同于c[b[i]]++;
        }
        //...................共计41*3行代码，太繁琐了
        */ 
        c[b[i]]++;//遍历的b数组得到分数，把分数当做c数组元素下标，通过这个c元素加1，就统计出每个分数有几个人
        
    }
    for(int i = 60; i < sizeof(c)/sizeof(c[0]); ++i) {
        if(c[i]>0){
            printf("%d分出现%d次\n",i,c[i]);
        } 
    }
    return 0;
}
```

### 03changeArrayElements.c

```c
//03-改变数组元素
/*
练习四：变化数据

定义一个数组，存储1,2,3,4,5,6,7,8,9,10
遍历数组得到每一个元素。
要求：
1，元素如果是奇数，则将当前数字扩大一倍
2，元素如果是偶数，则将当前数字变成二分之一
*/
#include <stdio.h>
int main() {

    //初始化数组
    int arr[10] = { 10,20,30,4,5,6,7,8,9,10 };
    //打印数组元素
    for (int i=0;i<10;i++) {
        printf("%-5d ",arr[i]);
    }
    printf("\n");
    //遍历数组，对元素进行操作
    for (int i=0;i<10;i++) {
        if (arr[i] % 2 == 0) {//判断元素是否为偶数
            arr[i] /= 2;//偶数元素变为二分之一
        }
        else {
            arr[i] *= 2;//奇数元素扩大一倍
        }
    }
    //打印数组元素
    for (int i=0;i<10;i++) {
        printf("%-5d ",arr[i]);
    }
    printf("\n");

    //把下标是偶数的元素变为0 
    //方法一
    // for (int i = 0;i < 10;i++) {//遍历数组元素
    //     if (i % 2 == 0) {//判断下标是否为偶数
    //         arr[i] = 0;//如果是偶数下标，则对应数组元素变为0
    //     }
    // }
    //方法二

     for (int k = 0;k < 10;k += 2) {//只遍历偶数下标元素,下标是偶数的元素
            arr[k] = 0;
    }
    
    for (int i=0;i<10;i++) {
        printf("%-5d ",arr[i]);
    }
    printf("\n");
    return 0;
}
```

### 04reverseArrayElements.c

```c
//04-数组元素逆序
/*数组元素逆序*/
#include <stdio.h>
int main(void) {
    int a[] = {8, 9, 10,100,23,54,65 };
    int n = sizeof(a) / sizeof(a[0]);//数组长度
    for (int i = 0; i < n; ++i) {
        printf("%-5d ", a[i]);
    }
    printf("\n");
    // 数组元素逆序
    //方法一
    // for (int i = 0; i < n/2; ++i) {
    //     int t = a[i];
    //     a[i] = a[n - 1 - i];
    //     a[n - i - 1] = t;
    // }
    //方法二
    // for (int i = 0,k = n-1; i < n/2; ++i,k--) {
    //     int t = a[i];
    //     a[i] = a[k];
    //     a[k] = t;
    // }
    //方法三
    for (int i = 0,k = n-1; i < k; ++i,k--) {
        int t = a[i];
        a[i] = a[k];
        a[k] = t;
    }
    for (int i = 0; i < n; ++i) {
        printf("%-5d ", a[i]);
    }
    printf("\n");
}
```

### 05bubbleSort.c

```c

//05-冒泡排序
// 冒泡排序:按升序排序
#include <stdio.h>
int main()
{
    int count = 0,count2 = 0;// 总比较次数和本轮比较次数
    int a[10] = {21, 42, 31,15,16,37,18,39,9,10};
    // 冒泡排序 a[0] a[1] a[2] a[3]  a[4]  a[5]  a[6]  a[7] a[8]  a[9]
    for (int i = 0; i < 9; i++)
    { // 外层循环控制排序的轮数/趟数
        // i = 0时 i=1时
        printf("第%d趟排序开始：", i + 1);
        count2 = 0;
        for (int j = 0; j < 9; j++)
        { // 内层循环控制每一轮比较的次数

            // j=0:比较a[0]和a[1],不交换a[0]=21,a[1]=42
            // j=1:比较a[1]和a[2],42>31,要交换，a[1]=31,a[2]=42
            // j=2:比较a[2]和a[3],42>15,交换，a[2]=15,a[3]=42
            // j=3:比较a[3]和a[4],42>16,交换，a[3]=16,a[4]=42
            // j=4:比较a[4]和a[5],42>37,交换，a[4]=37,a[5]=42
            // j=5:比较a[5]和a[6],42>18,交换，a[5]=18,a【6】=42
            // j=6,7,8
            count++;
            count2++;
            if (a[j] > a[j + 1])
            { // 如果前一个数比后一个大，则交换
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("第%d趟排序后的结果：", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", a[j]);
        }
        printf("本轮共比较了%d次\n", count2);
        printf("\n");
    }

    for (int j = 0; j < 10; j++)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
    printf("一共比较了%d次\n", count);


    // for(int i = 0; i < 9; i++)// 外层循环控制排序的轮数/趟数
    // {
    //     for (int j = 0; j < 9; j++)// 内层循环控制每一轮比较的次数
    //     {
    //         if (a[j] > a[j + 1])
    //         { // 如果前一个数比后一个大，则交换
    //             int t = a[j];
    //             a[j] = a[j + 1];
    //             a[j + 1] = t;
    //         }
    //     }
    // }

    // for (int j = 0; j < 10; j++)
    // {
    //     printf("%d ", a[j]);
    // }
    // printf("\n");


    return 0;
}
```

### 06optimizedBubbleSort1.c

```c
//06-冒泡排序优化1
//冒泡排序
#include <stdio.h>
int main(){
    int count = 0,count2 = 0;
    int a[10] = {21, 4,  31, 15,   16,    37,   18,    39,  9,   10}
    ;
    //冒泡排序   a[0] a[1] a[2] a[3]  a[4]  a[5]  a[6]  a[7] a[8]  a[9]
    for(int i = 0;i < 9;i++){//外层循环控制排序的轮数/趟数
        printf("第%d趟排序开始:",i+1);
        count2 = 0;
        for(int j = 0;j < 9 - i;j++){//优化了内层循环控制每一轮比较的次数
            count++;
            count2++;
            if(a[j] > a[j+1]){//如果前一个数比后一个大，则交换
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("第%d趟排序后的结果:",i+1);
        for(int j = 0;j < 10;j++){
            printf("%d ",a[j]);
        }

        printf("第%d趟共比较了%d次\n",i+1,count2);

    }
    printf("一共比较了%d次\n",count);


    //不添加其它打印代码。
    //for(int i = 0; i < 9; i++)// 外层循环控制排序的轮数/趟数
    // {
    //     for (int j = 0; j < 9-i; j++)// 内层循环控制每一轮比较的次数
    //     {
    //         if (a[j] > a[j + 1])
    //         { // 如果前一个数比后一个大，则交换
    //             int t = a[j];
    //             a[j] = a[j + 1];
    //             a[j + 1] = t;
    //         }
    //     }
    // }
    return 0;
}
```

### 07optimizedBubbleSort2.c

```c
//07-冒泡排序优化2
//冒泡排序
#include <stdio.h>
int main(){
    int count = 0;
    // int a[10] = {21, 4,  31, 15,   16,    37,   18,    39,  9,   10};
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0;i < 9;i++){//外层循环控制排序的轮数/趟数
        printf("第%d趟排序开始：",i+1);
        int flag = 0;//标志变量。flag表示是否交换过，如果交换过则flag=1。优化比较总轮数/总趟数
        for(int j = 0;j < 9-i;j++){//内层循环控制每一轮比较的次数
            count++;
            if(a[j] > a[j+1]){//如果前一个数比后一个大，则交换
                flag = 1;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("第%d趟排序后的结果：",i+1);
        for(int j = 0;j < 10;j++){
            printf("%d ",a[j]);
        }
        printf("\n");
        if(flag == 0){//如果成立，说明已经有序，则跳出循环。(某一轮没有交换过则说明此时已经有序，此时flag肯定还是0)
            break;//跳出外层循环
        }
    }
    printf("一共比较了%d次\n",count);
    return 0;
}
```

### 08Two-DimensionalArray.c

```c
//08-二维数组
#include <stdio.h>
int main(){
    int a[3][4] = {{100,200,300,400},{500},{900,1000,1100,1200}};//{100,200};//
    for(int i = 0;i < 3;i++){
        for(int k = 0;k < 4;k++){
            printf("%6d ",a[i][k]);
        }
        printf("\n");
    }

    printf("请输入12个整数：");
    for(int i = 0;i < 3;i++){
        for(int k = 0;k < 4;k++){
            scanf("%d",&a[i][k]);
        }
    }
    for(int i = 0;i < 3;i++){
        for(int k = 0;k < 4;k++){
            printf("%d ",a[i][k]);
        }
        printf("\n");
    }

    
    return 0;   
}
```

### 09One-DimensionalCharArray.c

```c
//09-一维字符数组

#include <stdio.h>
#include <string.h>
int main(){
    char d[5] = "12345";
    char a[] = {'a','b','c'};//单引号表示字符型，没有\0结束标志，必须有一个字符，不能是空字符，否则编译出错。
    char b[] = {"abcd"};//双引号表示字符串,有\0结束标志，可以是空字符，"\0"是在保存时自动添加的。
    char c[] = "abcde";
    printf("sizeof(a):%lu\n",sizeof(a));//3
    printf("sizeof(b):%lu\n",sizeof(b));//5
    printf("sizeof(c):%lu\n",sizeof(c));//6

    printf("strlen(b):%lu\n",strlen(b));//4,strlen只计算字符串的字符长度、即实际字符的个数，以\0为结尾标志，不计算\0  (string length)
    printf("strlen(c):%lu\n",strlen(c));//5,strlen只计算字符串的长度，以\0为结尾标志
    printf("strlen(a):%lu\n",strlen(a));//不一定是3。strlen只计算字符串的长度，以\0为结尾标志
    

    printf("%s,%s,%s\n",a,b,c);//%s用来打印字符串，遇到\0结束
    printf("c[4]:|%c|\n",c[4]);
    printf("c[5]：|%c|\n",c[5]);//\0是什么都没有
    printf("|%c|\n",32);

    printf("%lu\n",sizeof("中国人"));//汉字在不同的编码系统下占的字节数是不一样的，gbk编码是一个汉字是2个字节，utf-8是3个字节
    return 0;
}
```

### 10Two-DimensionalCharArray.c

```c
//10-二维字符数组
#include <stdio.h>
int main(){
    char name[5][20] = {"Tom","Jack","xiaoming","xiaohua","Chinese"};//二维字符数组保存多个字符串
    //二维字符数组，也是一维字符串数组，5个字符串name[0],name[1],....name[4]
    printf("%s,%s\n",name[2],name[4]);
    
    
    for(int i = 0;i < 5;i++){
        printf("%s\n",name[i]);
    }

    printf("%c\n",name[0][0]);
    printf("|%c|,|%c|\n",name[0][3],name[0][19]);
    printf("%c\n",name[1][3]);
    return 0;
}
```

### 11arrayAsFunctionArgument.c

```c
//11-数组当做函数参数
#include <stdio.h>
void printArr(int arr[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[5] = {2,4,6,8,10};
    printArr(a,10);
    printArr(b,5);
    
    char c[10]={0};
    scanf("%s",c);//输入字符串，存入c数组中
    printf("%s\n",c);
    return 0;
}
```

## c08-pointerBase

### 01pointerVariableAndAddressNumber.c

```c
//01-指针变量与地址编号
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a = 10;
    printf("a:%d\n",a);//打印a的值，a的内容
    printf("&a: %p\n",&a);//打印a的地址编号、打印a的地址，&是取地址运算符,用%p打印即是用十六进制打印地址编号
    //0~17,179,869,183:   16GB内存空间，
    //0x7ff7b4fe56a8,140701870216872
    //0x7ff7b11956b8----140701804877496
    //0x7ff7b390d6b8----140701846263480
    //0x7ff7ba6ef6b8

    int * ptr = &a;//*表示声明的是一个指针类型的变量ptr，
    //*此时是一个标志符，表示ptr是一个指针变量
    //int表示这个指针变量ptr中只能保存int类型变量的地址
    //int在这里表示ptr指向的数据只能是int类型。
    
    printf("ptr:%p\n",ptr);//打印ptr的值,是一个地址，a的地址
    //用%p打印即是用十六进制打印地址编号
    
    printf("&ptr:%p\n",&ptr);//打印ptr的地址编号、打印ptr的地址
    int **pptr = &ptr;//pptr是一个二级指针变量，保存的是一级指针变量ptr的地址
    printf("sizeof(a):%lu\n",sizeof(a));
    printf("sizeof(ptr):%lu\n",sizeof(ptr));//8字节
    printf("sizeof(pptr):%lu\n",sizeof(pptr));//8字节

    printf("*ptr:%d\n",*ptr);//<=====>printf("*ptr:%d\n",a);
    //*ptr是根据ptr中保存的地址，去访问对应的地址空间<=====>printf("*ptr:%d\n",a);
    //*单目运算符，表示指针间接访问运算符、解引用运算符。
    
    printf("*&a:%d\n",*&a);
    //*&是互逆操作，操作抵消了<=====>*&a <======> a

    *ptr = 100;//a = 100;
    printf("*ptr:%d\n",*ptr);
    printf("a=%d\n",a);

    printf("*ptr*200:%d\n",*ptr * 200);
    //两个*运算。一个是指针运算，一个是乘法运算
    
    printf("**pptr:%d\n",**pptr);//*(*pptr)<=====>*ptr<==>a
    **pptr = 200;
    printf("a:%d\n",a);
    printf("*ptr:%d\n",*ptr);
    printf("**pptr:%d\n",**pptr);
    return 0;
}
//a、&a、ptr、*ptr、&ptr、pptr、*pptr、**pptr、sizeof(a)、sizeof(ptr)、sizeof(pptr)
```

### 02usePointerInputData.c

```c
///02-使用指针输入数据

#include <stdio.h>
int main(){
    int a = 0;
    printf("请输入一个整数：");
    scanf("%d",&a);
    printf("%d\n",a);

    int * p = &a;//p指向a
    printf("请再输入一个整数：");
    scanf("%d",p);
    printf("a:%d\n",a);
    printf("*p:%d\n",*p);


    int b = 2000;
    p = &b;//改变了p的指向，让p指向了b
    printf("%d\n",*p);//2000

    int *q = (int *)0x7ff7b11956000;//不能直接使用一个数值当做地址。
    printf("~~~~~~\n");
    //printf("%d\n",*q);//error:运行时出错，因为q指向的地址是无效的。
    printf("-------\n");
    
    //*q = 1000;//error:运行时出错，因为q指向的地址是无效的。
    printf("========\n");
    return 0;
}
```

### 03pointerAndInteger.c

```c
//03-指针加减一个整数
#include <stdio.h>
#define N 10
int main(){
    int arr[] = {10,20,30,40};
    //数组名就是首元素的地址，是常量，不能修改
    //有四个元素：arr[0],arr[1],arr[2],arr[3]

    int arr3[4] = {0};
    int arr2[4] = {100,200,300,400};
    
    //arr3 = arr2;//错误，不能将一个数组赋值给另一个数组
    //N = 20;//错误，不能修改符号常量
    
    *arr = *arr2;//《==》*&arr[0] = *&arr2[0]《==》arr[0] = arr2[0];
    printf("arr[0]：%d\n",arr[0]);
    
    *arr *= *arr2;
    //《========》arr[0] *= arr2[0];
    //《========》arr[0] = arr[0] * arr2[0];
    printf("arr[0]：%d\n",arr[0]);
    printf("*arr：%d\n",*arr);

    int *ptr = arr;//等价于<=======> int *ptr = &arr[0];
    printf("%p\n",ptr);
    printf("%d\n",*ptr);

    ptr +=2;
    printf("%p\n",ptr);
    printf("%d\n",*ptr);
    

    ptr -=1;//ptr--
    printf("%p\n",ptr);
    printf("%d\n",*ptr);
    
    printf("通过指针访问所有的数组元素：\n");
    ptr = arr;//等价于<=======> ptr = &arr[0];
    for(int i = 0;i < 4;i++){
        printf("%d\n",*ptr);//arr[i]
        ptr++;
    }
    printf("%p\n",ptr);
    //上面循环的最后一次打印，打印的是指针指向的arr[3]，
    //再++，就指向了arr[4]，越界
    
    printf("%d\n",*ptr);//越界访问，程序可能崩溃。打印出了不确定值
    printf("%p\n",&arr[3]);//数组中最后一个元素的地址

    ptr = &arr[3];
    printf("%p\n",ptr);
    printf("%d\n",*ptr);

    *ptr += 2;//<======>arr[3] += 2;
    printf("%p\n",ptr);
    printf("%d\n",*ptr);
    printf("arr[3]:%d\n",arr[3]);


    ptr = arr;
    printf("%p\n",ptr);
    *(ptr += 2);//<======>*(ptr = ptr + 2);<=====>arr[2];
    printf("%p\n",ptr);
    printf("%d\n",*ptr);

    ptr = arr;
    printf("%d\n",*(ptr++));//printf("%d\n",*(ptr));ptr = ptr + 1;
    printf("%d\n",*ptr);

    ptr = arr;
    printf("%d\n",*(++ptr));//ptr = ptr + 1;printf("%d\n",*(ptr));
    printf("%d\n",*ptr);

    ptr = arr;
    printf("%d\n",(*ptr)++);//printf("%d\n",arr[0]);arr[0]++;
    printf("%d\n",*ptr);//arr[0]

    ptr = arr;
    printf("%d\n",++(*ptr));//arr[0]++;printf("%d\n",arr[0]);
    printf("%d\n",*ptr);//arr[0]

    return 0;
}
```

### 04arrayAsFunctionArgument.c

```c
//04-数组当做参数
#include <stdio.h>
int sumOfArr(int *a,int n){//形式参数传递数组名
    ////<========>int sumOfArr(int a[],int n)//a[]===>int *a
    printf("sizeof(a):%lu\n",sizeof(a));
    int s = 0;
    //方法一/
    // for(int i = 0;i < n;i++){
    //     //s += a[i];//a指针名可以当作数组名使用
    //     s += *(a+i);//指针加一
    // }
    // return s;
    // //方法二
    // s = 0;
    // for(int i = 0;i < n;i++){
    //     s += *a;
    //     a++;//指针加一，或者++a;
    // }
    // return s;

    //方法三
    s = 0;
    for(int i = 0;i < n;i++){
        s += *a++;//不能写成 s+= *(++a);也不能写成 s+= ++*a;也不能写成 s+= (*a)++;
    }
    return s;
}
int main(){
    int b[] = {10,20,30,40,50};
    printf("%p\n",b);
    printf("%p\n",&b[0]);
    printf("sizeof(b):%lu\n",sizeof(b));//sizeof(b) = 5*4 = 20,整个数组占用的内存空间
    printf("sizeof(b[0]):%lu\n",sizeof(b[0]));
    printf("sizeof(&b[0]):%lu\n",sizeof(&b[0]));
    printf("%d\n",sumOfArr(b,sizeof(b)/sizeof(int)));
}
```

