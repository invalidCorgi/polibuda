#include <stdio.h>
#include <stdlib.h>

int sum_dziel(int liczba)
{
    int i, suma=0;
    for(i=1;i<=liczba/2;i++)
    {
        if(liczba%i==0)
            suma+=i;
    }
    return suma;
}

int main()
{
    int a,i;    scanf("%d",&a);
    int tab[a+1];

    for(i=1;i<=a;i++)
    {
        tab[i]=sum_dziel(i);
    }

    for(i=1;i<=a;i++)
    {
        if(tab[i]<a)
            if(tab[tab[i]]==i && tab[i]>i)
                printf("[ %d %d ]\n",i,tab[i]);
    }

    return 0;
}
