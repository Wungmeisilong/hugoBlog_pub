#include <stdio.h>
#define x(n,m) printf("%d * %d = %d",n,m,(n)*(m))
int main() {
    // Write your code here
	for(int i = 1; i <10; i++){
		for(int j = 1; j <10; j++){
			x(i,j);
			if(i == j && (j*i)<81){
				printf("\n");
				break;
			}else if(i*j <10){
				printf("    ");
			}else {
				printf("   ");
			}
		}
	}
    return 0;
}
