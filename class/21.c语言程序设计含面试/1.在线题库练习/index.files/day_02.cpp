/*
	Name: ������� 
	Copyright: https://blog.dotcpp.com/a/86763 
	Author: ��÷���� 
	Date: 18/11/24 19:02
	Description: 
*/
#include <stdio.h>

int main(){
	char ch[5];
	for(int i = 0; i<5; i++)
	{
		scanf("%c",&ch[i]);
		ch[i] += 4;
	 } 
	 printf("%s",&ch);
} 
