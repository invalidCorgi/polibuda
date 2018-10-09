#include <stdio.h>
#include <stdlib.h>

int silnia(int n)
{
    if(n==2) return n;
    return n*silnia(n-1);
}

int main()
{
    printf("%d",silnia(5));
    return 0;
}
