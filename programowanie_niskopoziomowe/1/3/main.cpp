#include <stdio.h>

int main()
{
    float a,b;

    printf("Podaj a: ");
    scanf("%f",&a);
    printf("Podaj b: ");
    scanf("%f",&b);

    printf("Wynik: %f",4*a+2*(a-b-1)/(a*a+b*b+1));

    return 0;
}
