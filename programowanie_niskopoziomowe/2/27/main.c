#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int tab[], int n)
{
    int i,j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n - i; j++)  //-i aby nie sortowac posortowanej czesci
        {
            if (tab[j - 1] > tab[j])  //zamien jesli poprzedni jest mniejszy
            {
                int temp = tab[j - 1];
                tab[j - 1] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

int main()
{
    int n=10;

    int *tab;
    tab = (int*) malloc (sizeof (int) * n);

    int i;

    for(i=0;i<n;i++)
    {
        tab[i]=rand()%100;
    }

    BubbleSort(tab,n);

    for(i=0;i<n;i++)
    {
        printf("%d\n",tab[i]);
    }

    free(tab);

    return 0;
}
