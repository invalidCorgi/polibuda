#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;

    do
    {
        system("cls");
        printf("Podaj a: ");
        scanf("%d",&a);
        printf("Podaj b: ");
        scanf("%d",&b);
    }
    while(a==0 || b==0 || a==-b);

    printf("Wynik: %f",(float)a/(a+b));

    return 0;
}
