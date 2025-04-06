/*
	Name: 求三个数中最大的数 
	Copyright: not 
	Author: 王梅四郎 
	Date: 18/11/24 19:02
	Description: 
*/
#include <stdio.h>

int main(){
	int arr[3];
	int temp;
	// 检查是否成功读取了三个整数
	while (scanf("%d%d%d", &arr[0], &arr[1], &arr[2]) == 3) {
		temp = arr[0];
		for (int i = 0; i < 2; i++) { // 修正循环条件，避免数组越界
			if (arr[i] < arr[i + 1])
				temp = arr[i + 1];
			else
				temp = arr[i];
		}
		printf("%d\n", temp); // 修正printf的使用，直接输出temp的值
	}
} 
