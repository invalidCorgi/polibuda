#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in, stare=1, nowe=1,temp;
    scanf("%d",&in);

    if(in<=1)
    {
        printf("1");
        return 0;
    }

    while(1)
    {
        temp=nowe;
        nowe=stare+nowe;
        stare=temp;
        if(stare<=in && nowe>in)
        {
            printf("%d",stare);
            break;
        }
    }

    return 0;
}
