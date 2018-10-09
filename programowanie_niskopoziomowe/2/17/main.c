#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d, g;
    int a, b;
    float c;

    printf("Podaj zakres szukania: ");
    scanf("%d %d", &d, &g);

    for(a = d; a < g; a++)
        for(b = a; b < g; b++)
            if((c = sqrt(pow(a, 2) + pow(b, 2))) == roundf(c))
                printf("a = %d \tb = %d\tc = %.0f\n", a, b, c);
    return 0;
}
