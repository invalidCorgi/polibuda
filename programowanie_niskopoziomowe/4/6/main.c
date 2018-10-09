#include <stdio.h>
#include <stdlib.h>
#include <string.h>



 int main()
 {
    FILE *plik;

      if ((plik=fopen("plik.txt", "r"))==NULL)
        {
        printf ("Blad\n");
        return 2;
        }

    char linia[100];


    while(fgets(linia, 100, plik))
    {
        printf("%d\n", abs(atoi(linia)));
    }
    fclose (plik);
    return 0;
 }
