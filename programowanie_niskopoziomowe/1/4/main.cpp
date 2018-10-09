#include <stdio.h>

int main()
{
    int m,n;
    do
    {
        printf("Podaj m: ");
        scanf("%d",&m);
        printf("Podaj n: ");
        scanf("%d",&n);
    }
    while((m+n)==5);

    printf("Wynik: %f",(float)(5+m-n)/(m+n-5));

    return 0;
}
