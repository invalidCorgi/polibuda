#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

pthread_t a,b,c,d,e,f,g,h;

int dlugosc(long long x)
{
    int dlug=0;
    while(x!=0)
    {
        x/=10;
        dlug++;
    }
    return dlug;
}

void* automorf(long long x,long long max)
{
    while(x<=max)
    {
        long long tmp = x*x;
        int dziel=1,i;
        for(i=0; i<dlugosc(x); i++)dziel*=10;
        tmp%=dziel;
        if(tmp==x)
            printf("%d\n",x);
        x+=8;
    }

}

int main()
{
    long long min,max;
    long long tmp;
    printf("Od: ");
    scanf("%lld",&min);
    printf("Do: ");
    scanf("%lld",&max);
    for(;min<=max;min++)
    {
        tmp=min*min;
        long long dziel=1;
        int i;
        for(i=0;i<dlugosc(min);i++)dziel*=10;
        tmp%=dziel;
        if(tmp==min)
            printf("%d\n",min);
    }
    /*pthread_create(&a,NULL,automorf(min,max),NULL);
    pthread_create(&b,NULL,automorf(min+1,max),NULL);
    pthread_create(&c,NULL,automorf(min+2,max),NULL);
    pthread_create(&d,NULL,automorf(min+3,max),NULL);
    pthread_create(&e,NULL,automorf(min+4,max),NULL);
    pthread_create(&f,NULL,automorf(min+5,max),NULL);
    pthread_create(&g,NULL,automorf(min+6,max),NULL);
    pthread_create(&h,NULL,automorf(min+7,max),NULL);*/

    return 0;
}
