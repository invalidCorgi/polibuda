#include <stdio.h>
#include <stdlib.h>

int silnia(int liczba)
{
    if(liczba<2) return 1;
    int i;
    for(i=liczba-1;i>1;i--)
    {
        liczba*=i;
    }
    return liczba;
}

int main()
{
    printf("%d",silnia(12));
    return 0;
}
