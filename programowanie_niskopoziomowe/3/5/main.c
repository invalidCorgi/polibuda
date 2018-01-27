#include <stdio.h>
#include <stdlib.h>

int mnozenie(int a, int b)
{
    if (b == 1) return a;
    return a + mnozenie(a, b-1);
}

int potegowanie(int a, int b)
{
    if (b == 1) return a;
    return mnozenie(a, potegowanie(a, b-1));
}

int main()
{
    printf("%d",potegowanie(5,3));
    return 0;
}
