/*
	Name: 母牛的故事 
	Copyright: https://blog.dotcpp.com/a/75862
	Author: 王梅四郎 
	Date: 18/11/24 19:02
	Description: 
*/
#include <stdio.h>
//递归思路： 
//int fun(int n)
//{
//    if(n<=3) return n;
//    else return fun(n-1)+fun(n-3);
//}
int main()
{
    int n=0;
    //动态分配思路 
    int arr[100];
    while(1){
    	printf("输入年数："); 
    	scanf("%d", &n);
    	if(n==0)break;
	    for (int i = 0; i <=n; i++) {
	        if (i <= 4) {
	            arr[i] = i;
	        } else {
	            arr[i] = arr[i - 1] + arr[i - 3];
	        }
	    }
	    printf("第%d年时，共生母牛%d头。\n", n,arr[n]);
	}
    return 0;
} 
