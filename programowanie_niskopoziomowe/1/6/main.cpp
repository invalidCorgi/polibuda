#include <stdio.h>
#include <stdlib.h>

int main()
{
    int wybor;
    float T;

    do
    {
        system("cls");
        printf("1 - Zamiana ze stopni Celcjusza na Fahrenheita\n");
        printf("2 - Zamiana ze stopni Fahrenheita na Celcjusza\n");
        printf("Wybierz opcje 1 lub 2: ");
        scanf("%d",&wybor);
    }
    while(wybor!=1 && wybor!=2);

    printf("\nPodaj wartosc temperatury: ");
    scanf("%f",&T);

    switch(wybor)
    {
    case 1:
        {
            printf("\nWynik: %.2f stopni Fahrenheita", 1.8*T+32);
            break;
        }
    case 2:
        {
            printf("\nWynik: %.2f stopni Celsjusza", 0.55555556*(T-32));
            break;
        }
    }

    return 0;
}
