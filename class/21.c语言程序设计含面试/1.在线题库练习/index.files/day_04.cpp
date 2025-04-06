/*
	Name: 温度转换 
	Copyright: 
	Author: 王梅四郎 
	Date: 18/11/24 19:02
	Description: 
*/
#include <stdio.h>

int main(){
	double c, F;
	scanf("%lf",&F);
		c = 5*(F-32)/9; 
		printf("c=%0.2lf\n", c); // 修正printf的使用，直接输出temp的值
	return 0;
} 
