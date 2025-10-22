# C语言基础知识

{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}

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