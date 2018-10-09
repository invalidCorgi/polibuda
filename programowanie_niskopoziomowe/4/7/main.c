#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f1, *f2;
    int l[5],i,wybor;
    for(i=0; i<5; i++)
        l[i]=0;

    char temp[100];
    if ((f1=fopen("test2.txt", "r"))==NULL)
    {
        printf ("Nie mogê otworzyæ pliku test.txt do odczytu!\n");
        exit(1);
    }

    if ((f2=fopen("nowy.txt", "w"))==NULL)
    {
        printf ("Nie mogê otworzyæ pliku nowy.txt do zapisu!\n");
        exit(1);
    }
    printf("Wybierz kodowanie (1 lub 2): ");
    scanf("%d",&wybor);

    switch(wybor)
    {
    case 1:
    {
        while ( !feof(f1) )
        {
            fscanf (f1, "%s", temp);
            switch (strlen(temp))
            {
            case 1:
            {
                l[1]=l[2]=l[3]=l[4]=0;
                //printf("%d. ",++l[0]);
                fprintf(f2,"%d. ",++l[0]);
                break;
            }
            case 2:
            {
                l[2]=l[3]=l[4]=0;
                //printf("  %d.%d. ",l[0],++l[1]);
                fprintf(f2,"  %d.%d. ",l[0],++l[1]);
                break;
            }
            case 3:
            {
                l[3]=l[4]=0;
                //printf("    %d.%d.%d. ",l[0],l[1],++l[2]);
                fprintf(f2,"    %d.%d.%d. ",l[0],l[1],++l[2]);
                break;
            }
            case 4:
            {
                l[4]=0;
                //printf("      %d.%d.%d.%d. ",l[0],l[1],l[2],++l[3]);
                fprintf(f2,"      %d.%d.%d.%d. ",l[0],l[1],l[2],++l[3]);
                break;
            }
            case 5:
            {
                //printf("        %d.%d.%d.%d.%d. ",l[0],l[1],l[2],l[3],++l[4]);
                fprintf(f2,"        %d.%d.%d.%d.%d. ",l[0],l[1],l[2],l[3],++l[4]);
                break;
            }
            }
            fgets(&temp,100,f1);
            //printf("%s",temp);
            fprintf(f2,"%s",temp);
        }
        break;
    }
    case 2:
    {
        while ( !feof(f1) )
        {
            fscanf (f1, "%s", temp);
            switch (strlen(temp))
            {
            case 1:
            {
                l[1]=l[2]=l[3]=l[4]=0;
                fprintf(f2,"%c. ",65+(l[0]++));
                break;
            }
            case 2:
            {
                l[2]=l[3]=l[4]=0;
                fprintf(f2,"  %d. ",++l[1]);
                break;
            }
            case 3:
            {
                l[3]=l[4]=0;
                fprintf(f2,"    %c. ",97+(l[2]++));
                break;
            }
            case 4:
            {
                l[4]=0;
                fprintf(f2,"      (%d) ",++l[3]);
                break;
            }
            case 5:
            {
                fprintf(f2,"        (%c) ",97+(l[4]++));
                break;
            }
            }
            fgets(&temp,100,f1);
            fprintf(f2,"%s",temp);
        }
        break;
    }
    }

    fclose (f1);
    fclose (f2);
    return 0;
}
