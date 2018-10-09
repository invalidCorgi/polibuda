#include <stdio.h>
#include <stdlib.h>

int main()
{
    int liczba=29;
    int dzielnik=6;
    while(liczba>=0)
        liczba-=dzielnik;
    liczba+=dzielnik;
    printf("%d",liczba);
    return 0;
}
