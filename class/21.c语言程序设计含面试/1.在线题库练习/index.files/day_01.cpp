/*
	Name: ���������������� 
	Copyright: not 
	Author: ��÷���� 
	Date: 18/11/24 19:02
	Description: 
*/
#include <stdio.h>

int main(){
	int arr[3];
	int temp;
	// ����Ƿ�ɹ���ȡ����������
	while (scanf("%d%d%d", &arr[0], &arr[1], &arr[2]) == 3) {
		temp = arr[0];
		for (int i = 0; i < 2; i++) { // ����ѭ����������������Խ��
			if (arr[i] < arr[i + 1])
				temp = arr[i + 1];
			else
				temp = arr[i];
		}
		printf("%d\n", temp); // ����printf��ʹ�ã�ֱ�����temp��ֵ
	}
} 
