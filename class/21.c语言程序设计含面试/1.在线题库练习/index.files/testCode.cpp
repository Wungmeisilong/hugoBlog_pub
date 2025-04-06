 /*
	Name: 测试大端小端模式 
	Copyright: not 
	Author: maloudown 
	Date: 20/11/24 15:16
	Description: 
*/

#include <stdio.h>
 
int main(){
 	int i;
 	union test{
 		unsigned int n;
 		char arr[4];
	 };
	 union test num;
	 num.n = 0x12345678;//注意:12所在位置是高位 
	 for(i = 0; i<4; i++){
	 	printf("&arr[%d]  = %p, arr[%d] = %#x\n",i,&num.arr[i],i,num.arr[i]);
	 }
	 return 0;
 } 
 /*
  代码解释：
		 代码中，%x表示输出16进制，x前加 # 标志表示，如果使用 %ox（八进制），
		 则输出的数前面会加上前缀 0；如果使用 %#x 或 %#X（十六进制），
		 则输出的数前面会加上前缀 0x 或 0X。这样做可以明确地表示数值的进制，
		 便于阅读和理解。 
  结果：
	&arr[0]  = 000000000062FE10, arr[0] = 0x78
	&arr[1]  = 000000000062FE11, arr[1] = 0x56
	&arr[2]  = 000000000062FE12, arr[2] = 0x34
	&arr[3]  = 000000000062FE13, arr[3] = 0x12 
  结论：
	高位存储在高地址，所以是小端模式。
 
 */ 
