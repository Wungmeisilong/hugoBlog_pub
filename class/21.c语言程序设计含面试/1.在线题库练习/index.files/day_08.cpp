#include <stdio.h>
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int *p = arr;
    for (int i = 0; i < 3; i++){
        printf("%d",*p++);
    }
    p = arr;
    printf("\n-------------------------------------------\n");
    for (int i = 0; i < 3; i++){
        printf("%d",*++p);
    }
    p = arr;
    printf("\n-------------------------------------------\n");
    for (int i = 0; i < 3; i++){
        printf("%d",++(*p));
    }
    return 0;
}
