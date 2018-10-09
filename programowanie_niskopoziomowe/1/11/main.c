#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int wybor;

    do
    {
        system("cls");
        printf("1-potegowanie\n2-odwrotnosc\n3-logarytm naturalny\n4-sinus\n5-tangens\nWybor: ");
        scanf("%d",&wybor);
    }while(wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4 && wybor!=5);

    switch(wybor)
    {
    case 1:
        {
            float x,y;
            printf("\npodstawa=",&x);
            scanf("%f",&x);
            printf("wykladnik=");
            scanf("%f",&y);
            printf("wynik=%f",pow(x,y));
            break;
        }
    case 2:
        {
            float x;
            printf("\nx=",&x);
            scanf("%f",&x);
            printf("wynik=%f",1/x);
            break;
        }
    case 3:
        {
            float x;
            printf("\nx=",&x);
            scanf("%f",&x);
            printf("wynik=%f",log(x));
            break;
        }
    case 4:
        {
            float x;
            printf("\nx=",&x);
            scanf("%f",&x);
            printf("wynik=%f",sin(x));
            break;
        }
    case 5:
        {
            float x;
            printf("\nx=",&x);
            scanf("%f",&x);
            printf("wynik=%f",tan(x));
            break;
        }
    }

    return 0;
}
