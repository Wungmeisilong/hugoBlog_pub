 /*
	Name: ���Դ��С��ģʽ 
	Copyright: not 
	Author: CV-Lob
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
	 num.n = 0x12345678;//ע��:12����λ���Ǹ�λ 
	 for(i = 0; i<4; i++){
	 	printf("&arr[%d]  = %p, arr[%d] = %#x\n",i,&num.arr[i],i,num.arr[i]);
	 }
	 return 0;
 } 
 /*
  ������ͣ�
		 �����У�%x��ʾ���16���ƣ�xǰ�� # ��־��ʾ�����ʹ�� %ox���˽��ƣ���
		 ���������ǰ������ǰ׺ 0�����ʹ�� %#x �� %#X��ʮ�����ƣ���
		 ���������ǰ������ǰ׺ 0x �� 0X��������������ȷ�ر�ʾ��ֵ�Ľ��ƣ�
		 �����Ķ������⡣ 
  �����
	&arr[0]  = 000000000062FE10, arr[0] = 0x78
	&arr[1]  = 000000000062FE11, arr[1] = 0x56
	&arr[2]  = 000000000062FE12, arr[2] = 0x34
	&arr[3]  = 000000000062FE13, arr[3] = 0x12 
  ���ۣ�
	��λ�洢�ڸߵ�ַ��������С��ģʽ��
 
 */ 
