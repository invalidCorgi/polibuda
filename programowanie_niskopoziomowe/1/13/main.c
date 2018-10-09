#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,i;
    float suma=0,iloczyn=1;

    printf("n=");
    scanf("%d",&n);

    float tab[n];

    for(i=0;i<n;i++)
    {
        printf("liczba %d.=",i+1);
        scanf("%f",&tab[i]);
        suma+=tab[i];
        iloczyn*=tab[i];
    }

    printf("\nSrednia arytmetyczna=%f",suma/n);
    printf("\nSrednia geometryczna=%f",pow(iloczyn,(float)1/n));

    return 0;
}
