#include <stdio.h>
#include <stdlib.h>

long long silnia(long long liczba)
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
    long long n=20,wynik=0;
    long long tab[n],i,j;
    for(i=0;i<n;i++)
        tab[i]=silnia(i);
    for(i=1;wynik<tab[n-1];i++)
    {
        wynik=i*(i+1)*(i+2);
        for(j=0;j<n;j++)
            if(wynik==tab[j])
            printf("%I64d * %I64d * %I64d = %I64d!\n",i,i+1,i+2,j);
    }
    return 0;
}
