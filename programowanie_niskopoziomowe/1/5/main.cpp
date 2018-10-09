#include <stdio.h>
#include <math.h>

int main()
{
    double x;

    printf("Podaj x: ");
    scanf("%lf",&x);

    printf("Wynik: %lf",(sqrt((pow(sin(x*x*x),2)+1.25)/(pow(cos(x*x),3)+1.25)))/(log(pow(tan(x+2),2))+2.5));

    return 0;
}
