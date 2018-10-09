#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l_stud_max 100

struct Student
{
    char imie[20];
    char nazwisko[20];
    int nr_albumu;
    float ocena;
};

void wypisz_stud(int i, struct Student studenci[])
{
    printf("Student nr: %d\n",i+1);
    printf("Imie: %s",studenci[i].imie);
    /*printf("Imie: ");
    for(j=0;j<strlen(studenci[i].imie)-1;j++)
    {
        printf("%c",studenci[i].imie[j]);
    }
    print("\n");
    */
    printf("Nazwisko: %s",studenci[i].nazwisko);
    printf("Nr albumu: %d\n",studenci[i].nr_albumu);
    printf("Ocena: %.2f\n",studenci[i].ocena);
    system("pause");
}

void dodaj_stud(int i, struct Student studenci[])
{
    printf("Student nr: %d\n",i+1);
    printf("Podaj imie: ");
    fgets(studenci[i].imie, 20, stdin);
    printf("Podaj nazwisko: ");
    fgets(studenci[i].nazwisko, 20, stdin);
    printf("Podaj nr albumu: ");
    scanf("%d",&studenci[i].nr_albumu);
    printf("Podaj ocene: ");
    scanf("%f",&studenci[i].ocena);
}

void oceny(int n, struct Student studenci[])
{
    int min=1024,max=0,i;
    float suma=0;
    for(i=0;i<n;i++)
    {
        suma+=studenci[i].ocena;
        if(studenci[i].ocena>max)
            max=studenci[i].ocena;
        if(studenci[i].ocena<min)
            min=studenci[i].ocena;
    }
    printf("Najnizsza ocena: %d\n",min);
    printf("Najwyzsza ocena: %d\n",max);
    printf("Srednia ocen: %f\n",(float)suma/n);
    system("pause");
}

void usun_stud(int i, struct Student studenci[])
{
    int n;
    for(n=0;n<20;n++)
    {
        studenci[i].imie[n]=' ';
        studenci[i].nazwisko[n]=' ';
    }
    studenci[i].nr_albumu=0;
    studenci[i].ocena=0;
}

int main()
{
    struct Student studenci[l_stud_max];
    int akt_l_stud = 0, i;
    char wybor;

    do
    {
        system("cls");
        printf("N : nowy student\n");
        printf("E : edycja danych studenta o podanym numerze\n");
        printf("W : wyznaczenie sredniej, maksymalnej i minimalnej oceny\n");
        printf("D : usuniecie danych o studentach\n");
        printf("L : lista wszystkich studentow\n");
        printf("K : koniec programu\n");
        wybor = getchar();
        switch(wybor)
        {
        case 'N':
            {
                dodaj_stud(akt_l_stud,studenci);
                printf("\n");
                wypisz_stud(akt_l_stud,studenci);
                akt_l_stud++;
                break;
            }
        case 'E':
            {
                int temp;
                printf("Chcesz zmienic dane studenta nr: ");
                scanf("%d",&temp);
                if(temp<=akt_l_stud && temp>0)
                    dodaj_stud(temp-1,studenci);
                else
                    printf("Nie ma studenta o tym numerze");

                break;
            }
        case 'W':
            {
                if(akt_l_stud>=1)
                    oceny(akt_l_stud,studenci);
                else
                    printf("Brak studentow");

                break;
            }
        case 'D':
            {
                int i=akt_l_stud-1;

                for(;i>=0;i--)
                {
                    usun_stud(i,studenci);
                }
                akt_l_stud=0;
                break;
            }
        case 'L':
            {
                for(i=0;i<akt_l_stud;i++)
                {
                    wypisz_stud(i,studenci);
                    printf("\n");
                }
                break;
            }
        }
    }while(wybor!='K');

    return 0;
}
