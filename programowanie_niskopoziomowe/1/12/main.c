#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;

    printf("a=");
    scanf("%f",&a);
    printf("b=");
    scanf("%f",&b);
    printf("c=");
    scanf("%f",&c);

    if(((a+b)>c) && ((a+c)>b) && ((b+c)>a))
        printf("boki moga utworzyc trojkat");
    else
        printf("boki nie moga utworzyc trojkata");

    return 0;
}
