#include <stdio.h>
#include <string.h>
#define SIZE 5
int main(){
    long n;
    int a[SIZE],tag;
    scanf("%ld",&n);
    if(n<=99999){
    	for(int i = 0; i<SIZE; i++){
   			a[i] =n%10;n/=10;
			if(n==0){tag = i; break;}			  		
		}
		printf("%d\n",tag+1);
		for(int i = tag; i>=0; i--){
			printf("%d ",a[i]);
		}
		printf("\n");
		for(int i = 0; i<=tag; i++){
			printf("%d",a[i]);
		}
	}
    return 0;
}

