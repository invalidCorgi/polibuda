#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int wybor;
    do
    {
        system("cls");
        printf("1-kolo\n2-kwadrat\n3-prostokat\n4-trojkat\n5-trapez\nWybor: ");
        scanf("%d",&wybor);
    }while(wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4 && wybor!=5);

    switch(wybor)
    {
    case 1:
        {
            float r;
            printf("\nr=");
            scanf("%f",&r);

            printf("obwod=%f\n",3.14159265*2*r);
            printf("pole=%f",3.14159265*r*r);
            break;
        }
    case 2:
        {
            float a;
            printf("\na=");
            scanf("%f",&a);

            printf("obwod=%f\n",4*a);
            printf("pole=%f",a*a);
            break;
        }
    case 3:
        {
            float a,b;
            printf("\na=");
            scanf("%f",&a);
            printf("b=");
            scanf("%f",&b);

            printf("obwod=%f\n",2*a+2*b);
            printf("pole=%f",a*b);
            break;
        }
    case 4:
        {
            float a,b,c,p;
            do
            {
                printf("\na=");
                scanf("%f",&a);
                printf("b=");
                scanf("%f",&b);
                printf("c=");
                scanf("%f",&c);
            }
            while(!(((a+b)>c) && ((a+c)>b) && ((b+c)>a)));


            p=(a+b+c)/2;

            printf("obwod=%f\n",a+b+c);
            printf("pole=%f",sqrt(p*(p-a)*(p-b)*(p-c)));
            break;
        }
    case 5:
        {
            float a,b,c,d,h;
            printf("\na(podstawa)=");
            scanf("%f",&a);
            printf("b(podstawa)=");
            scanf("%f",&b);
            printf("c(ramie)=");
            scanf("%f",&c);
            printf("d(ramie)=");
            scanf("%f",&d);
            printf("h(wysokosc)=");
            scanf("%f",&h);

            printf("obwod=%f\n",a+b+c+d);
            printf("pole=%f",0.5*((a+b)*h));
            break;
        }
    }

    return 0;
}
