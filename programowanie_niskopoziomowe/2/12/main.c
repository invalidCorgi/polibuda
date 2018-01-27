#include <stdio.h>
#include <stdlib.h>

int potegowanie(int podstawa, int wykladnik)
{
    if(wykladnik==0) return 1;
    int wynik=podstawa,i,j;
    for(i=1;i<wykladnik;i++)
    {
        int temp=wynik;
        for(j=1;j<podstawa;j++)
        {
            wynik+=temp;
        }
    }
    return wynik;
}

int main()
{
    printf("%d",potegowanie(5,3));
    return 0;
}
