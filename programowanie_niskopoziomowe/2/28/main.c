#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int tab[], int n)
{
    int i,j;
    for (i = 0; i < n - 1; i++)
    {
        int x = i;
        for (j = i + 1; j < n; j++)  //znajdz najmniejsza liczbe
        {
            if (tab[x] > tab[j])
                x = j;
        }
        if (x != i)    //jesli kolejna liczba nie jest najmniejsza to zamien z najmniejsza
        {
            int temp = tab[i];
            tab[i] = tab[x];
            tab[x] = temp;
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

    SelectionSort(tab,n);

    for(i=0;i<n;i++)
    {
        printf("%d\n",tab[i]);
    }

    free(tab);

    return 0;
}
