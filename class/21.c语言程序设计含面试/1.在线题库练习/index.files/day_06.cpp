#include <stdio.h>
int ascii_to_integer(const char *str){
    int digit = 0;
    while(*str >= '0' && *str <= '9'){
        digit = digit * 10 + (*str - '0');
        str++;
    }
    if(*str != '\0')
        return 0;
    return digit;
}
int main(int argc, char *argv[]){
	char str[100];
    printf("ÇëÊäÈëÒ»´®Êý×Ö×Ö·û£º");
    scanf("%s",str);
    printf("The digit is: %d\n", ascii_to_integer(str));
    return 0;
}
