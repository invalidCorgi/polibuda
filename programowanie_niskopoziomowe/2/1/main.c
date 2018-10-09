#include <stdio.h>
#include <stdlib.h>
#define n 10

int main()
{
    int tab[n], i, temp;
    for(i=0; i<n; i++)
    {
        tab[i]=i;
        printf("%d\n",tab[i]);
    }

    for(i=0; i<n/2; i++)
    {
        temp = tab[n-i-1];
        tab[n-i-1]=tab[i];
        tab[i]=temp;
    }

    printf("\nOdwrocona:\n");

    for(i=0; i<n; i++)
    {
        printf("%d\n",tab[i]);
    }

    return 0;
}
