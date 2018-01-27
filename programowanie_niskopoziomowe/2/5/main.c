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
    int a,i;

    scanf("%d",&a);

    for(i=1;i<=a;i++)
    {
        if(i==sum_dziel(i))
            printf("%d\n",i);
    }

    return 0;
}
