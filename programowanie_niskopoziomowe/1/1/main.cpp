#include <stdio.h>

using namespace std;

int main()
{
    double a,b,c;

    printf("Podaj a: ");
    scanf("%lf",&a);
    printf("Podaj b: ");
    scanf("%lf",&b);
    printf("Podaj c: ");
    scanf("%lf",&c);

    if (a>=b)
    {
        if(a>=c)
            printf("Najwieksza liczba jest a=%lf", a);
        else
            printf("Najwieksza liczba jest c=%lf", c);
    }
    else
    {
        if(b>=c)
            printf("Najwieksza liczba jest b=%lf", b);
        else
            printf("Najwieksza liczba jest c=%lf", c);
    }

    return 0;
}
