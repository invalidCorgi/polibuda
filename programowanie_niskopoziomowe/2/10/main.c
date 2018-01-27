#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int p=2,a;
    scanf("%d",&a);
    while(pow(2,p)<=a)
    {
        if(sum_dziel(p)==1)
            if(sum_dziel(pow(2,p)-1)==1)
                printf("%.0f\n",pow(2,p)-1);
        p++;
    }
    return 0;
}
