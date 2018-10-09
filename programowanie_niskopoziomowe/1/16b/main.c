#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 1000

int main()
{
    char cezar[n];
    int odleglosc,wybor,i;

    printf("Wpisz wiadomosc:\n");
    fgets(cezar, n, stdin);
    strupr(cezar);
    printf("\nWpisz odleglosc liter: ");
    scanf("%d",&odleglosc);

    do
    {
        system("cls");
        printf("1-zaszyfrowanie\n2-deszyfrowanie\nWybor: ");
        scanf("%d",&wybor);
    }while(wybor!=1 && wybor!=2);

    switch(wybor)
    {
    case 1:
        {
            for(i=0;i<n;i++)
            {
                if(cezar[i]<=90 && cezar[i]>=65)
                {
                    cezar[i]+=odleglosc;
                    if(cezar[i]>90)
                        cezar[i]-=26;
                    if(cezar[i]<65)
                        cezar[i]+=26;
                }
            }
            break;
        }
    case 2:
        {
            for(i=0;i<n;i++)
            {
                if(cezar[i]<=90 && cezar[i]>=65)
                {
                    cezar[i]-=odleglosc;
                    if(cezar[i]>90)
                        cezar[i]-=26;
                    if(cezar[i]<65)
                        cezar[i]+=26;
                }
            }
            break;
        }
    }

    printf("Wynik:\n\n%s",cezar);

    return 0;
}
