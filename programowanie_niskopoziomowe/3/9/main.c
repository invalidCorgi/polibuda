#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suma(char str[],int n)
{
    if(n==1)return str[0]-48;
    return (str[n-1]-48)+suma(str,n-1);
}

int main()
{
    char str[20];
    gets(str);
    printf("%d",suma(str,strlen(str)));
    return 0;
}
