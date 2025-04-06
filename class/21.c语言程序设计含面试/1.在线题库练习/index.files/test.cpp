#include <stdio.h>
#define T(x) printf(""#x" square is the %d\n",((x)*(x)))
#define TEST(n) X##n

    int main(void){
        T(4);
        int TEST(0) = 0;
        int TEST(1) = 10;
        printf("X1 = %d",X1);
    }
