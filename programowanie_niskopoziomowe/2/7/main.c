#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,zakres,dokad;

    scanf("%d",&zakres);
    int tablica[zakres];
    dokad=floor(sqrt(zakres));
    for (i=1; i<=zakres; i++) tablica[i]=1;

    for (i=2; i<=dokad; i++)
    {
        if (tablica[i] != 0)
        {
            j = i+i;
            while (j<=zakres)
            {
                tablica[j] = 0;
                j += i;
            }
        }
    }
    for (i=2; i<=zakres; i++)
        if (tablica[i]!=0)
            printf("%d, ",i);
    return 0;
}
