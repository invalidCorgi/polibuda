#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i;
    srand(time(0));

    do
    {
        system("cls");
        printf("n=");
        scanf("%d",&n);
        printf("m=");
        scanf("%d",&m);
    }while(m<0);

    m++;

    for(i=0;i<n;i++)
        printf("%d. liczba: %d\n",i+1,rand()%m);

    return 0;
}
