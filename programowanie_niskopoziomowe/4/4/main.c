#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f1;

    char max[100],min[100];
    int iMin=100,iMax=0,i;

    if ((f1=fopen("input.txt", "r"))==NULL)
    {
        printf ("Nie moge otworzyc pliku input.txt do odczytu!\n");
        exit(1);
    }


    while ( !feof(f1) )
    {
        char temp[100];
        //fscanf (f1, "%s", temp);
        fgets(temp,100,f1);
        if(iMax<strlen(temp))
        {
            iMax=strlen(temp);
            for(i=0;i<100;i++)
                max[i]=temp[i];
        }
        if(iMin>strlen(temp))
        {
            iMin=strlen(temp);
            for(i=0;i<100;i++)
                min[i]=temp[i];
        }
    }

    printf("Najdluzszy wiersz: %s \nNajkrotszy wiersz: %s",max,min);

    fclose (f1);

    return 0;
}
