/*
	Name: ĸţ�Ĺ��� 
	Copyright: https://blog.dotcpp.com/a/75862
	Author: ��÷���� 
	Date: 18/11/24 19:02
	Description: 
*/
#include <stdio.h>
//�ݹ�˼·�� 
//int fun(int n)
//{
//    if(n<=3) return n;
//    else return fun(n-1)+fun(n-3);
//}
int main()
{
    int n=0;
    //��̬����˼· 
    int arr[100];
    while(1){
    	printf("����������"); 
    	scanf("%d", &n);
    	if(n==0)break;
	    for (int i = 0; i <=n; i++) {
	        if (i <= 4) {
	            arr[i] = i;
	        } else {
	            arr[i] = arr[i - 1] + arr[i - 3];
	        }
	    }
	    printf("��%d��ʱ������ĸţ%dͷ��\n", n,arr[n]);
	}
    return 0;
} 
