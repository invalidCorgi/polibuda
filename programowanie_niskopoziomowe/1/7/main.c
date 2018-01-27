#include <stdio.h>
#include <math.h>

int main()
{
    float x1,x2,x3,x4,y1,y2,y3,y4,xk,yk,dl1,dl2,dl3,dl4,dlk1,dlk2,dlk3,dlk4;

    printf("Jako kolejny punkt przyjmuj kolejny wedlug wskazowej zegara lub odwrotnie do ruchu wskazowek zegara, np.\n");
    printf("1-----2\n|     |\n4-----3\n\n");
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
    printf("Podaj x4: ");
    scanf("%f",&x4);
    printf("Podaj y4: ");
    scanf("%f",&y4);

    xk=(x1+x2+x3+x4)/4;
    yk=(y1+y2+y3+y4)/4;

    dlk1=pow(xk-x1,2)+pow(yk-y1,2);
    dlk2=pow(xk-x2,2)+pow(yk-y2,2);
    dlk3=pow(xk-x3,2)+pow(yk-y3,2);
    dlk4=pow(xk-x4,2)+pow(yk-y4,2);

    dl1=pow(x2-x1,2)+pow(y2-y1,2);
    dl2=pow(x2-x3,2)+pow(y2-y3,2);
    dl3=pow(x3-x4,2)+pow(y3-y4,2);
    dl4=pow(x4-x1,2)+pow(y4-y1,2);

    if((fabs(dlk1-dlk2)<0.0001) && (fabs(dlk1-dlk3)<0.0001) && (fabs(dlk1-dlk4)<0.0001))
    {
        if((fabs(dl1-dl2)<0.0001) && (fabs(dl1-dl3)<0.0001) && (fabs(dl1-dl4)<0.0001))
            printf("Figura jest kwadratem");
        else
            printf("Figura jest prostokatem");
    }
    else
        printf("Figura inna niz kwadrat i prostokat");


    return 0;
}
