#include <stdio.h>
#include <math.h>

int main()
{
    float a1,a2,b1,b2,x,y,odl;

    printf("a1=");
    scanf("%f",&a1);
    printf("b1=");
    scanf("%f",&b1);
    printf("a2=");
    scanf("%f",&a2);
    printf("b2=");
    scanf("%f",&b2);

    if(a1==a2)
    {
        printf("Proste sa rownolegle - nie przecinaja sie");
        return 0;
    }

    x=(b2-b1)/(a1-a2);
    y=a1*x+b1;
    odl=sqrt(x*x+y*y);

    printf("\nProste przecinaja sie w punkcie(%.4f,%.4f), ktory lezy %.4f jednostki dlugosci od poczatku ukladu wspolrzednych",x,y,odl);

    return 0;
}
