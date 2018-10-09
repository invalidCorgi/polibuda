#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;

    scanf("%d",&a);
    scanf("%d",&b);
    c=a; d=b;

    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    printf("%d",c*d/a);

    return 0;
}
