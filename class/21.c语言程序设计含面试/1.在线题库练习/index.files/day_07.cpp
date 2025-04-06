#include <stdio.h>
int main(){
    int x, y, z;
    int t;
    for(t = 0;t<4;t++){
        x = 4 * t;
        y = 25 - 7 * t;
        z = 75 + 3 * t;
        printf("cock:%d,hen:%d,chicken:%d-----sum:%d\n",x,y,z,(x+y+z));
    }
    return 0;
}
