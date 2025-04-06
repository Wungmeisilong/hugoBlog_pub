//#pragma pack(4) 
#include <stdio.h>
#define offsetof(TYPE, MEMBER) ((size_t ) &((TYPE *)0)->MEMBER)
typedef struct s
{
    /* data */
    union {
        int a;
        char str[10];
    };
    struct s* next;
}S;

int main(){
    printf("%ld",offsetof(S, next));
    return 0;    
}
