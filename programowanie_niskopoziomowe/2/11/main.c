#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, a, i;

    printf("Podaj liczbe: ");
    scanf("%d",&a);

    n=2;
    i=0;

    while(a>1)
    {
        while(a%n==0)
        {
            i++;
            a/=n;
        }
        if(i!=0)printf("%d ^ %d\n",n, i);
        i=0;
        n++;
    }

    return 0;
}
