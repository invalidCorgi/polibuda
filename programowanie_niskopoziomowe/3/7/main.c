#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wypisz(char str[],int n)
{
    printf("%c",str[n-1]);
    if(n>1)
        wypisz(str,n-1);
}

int main()
{
    char str[100];
    gets(str);
    wypisz(str,strlen(str));
    return 0;
}
