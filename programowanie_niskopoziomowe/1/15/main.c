#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x1,x2,x3,y1,y2,y3;

    printf("Podaj x1: ");
    scanf("%f",&x1);
    printf("Podaj y1: ");
    scanf("%f",&y1);
    printf("Podaj x2: ");
    scanf("%f",&x2);
    printf("Podaj y2: ");
    scanf("%f",&y2);
    printf("Podaj x3: ");
    scanf("%f",&x3);
    printf("Podaj y3: ");
    scanf("%f",&y3);

    if(x1==x2 && x1==x3)
    {
        printf("\npunkty sa wspolliniowe");
        return 0;
    }

    if(x1==x2 || x1==x3 || x2==x3)
    {
        printf("\npunkty nie sa wspolliniowe");
        return 0;
    }

    if(fabs(((y2-y1)/(x2-x1))-((y3-y1)/(x3-x1)))<0.0001)
        printf("\npunkty sa wspolliniowe");
    else
        printf("\npunkty nie sa wspolliniowe");

    return 0;
}
