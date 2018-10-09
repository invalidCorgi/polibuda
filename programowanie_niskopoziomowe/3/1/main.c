#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l_prac 10

struct pracownik
{
    char nazwisko[20];
    int pensja;
    float proc_premii;
};

void wypisz_prac(int i, struct pracownik pracownicy[])
{
    printf("Pracownik nr: %d\n",i+1);
    printf("%s",pracownicy[i].nazwisko);
    printf("%d\n",pracownicy[i].pensja);
    printf("%.2f%%\n",pracownicy[i].proc_premii);
    system("pause");
}

void dodaj_prac(int i, struct pracownik pracownicy[])
{
    printf("Pracownik nr: %d\n",i+1);
    printf("Podaj nazwisko: ");
    fflush(stdin);
    fgets(pracownicy[i].nazwisko, 20, stdin);
    printf("Podaj pensje: ");
    scanf("%d",&pracownicy[i].pensja);
    printf("Podaj procent premii: ");
    scanf("%f",&pracownicy[i].proc_premii);
}

void zm_pensje(char nazw[], struct pracownik pracownicy[])
{
    int i;
    for(i=0;i<l_prac;i++)
    {
        if(strncmp(pracownicy[i].nazwisko,nazw,strlen(pracownicy[i].nazwisko)) == 0)
        {
            printf("Podaj nowa pensje: ");
            scanf("%d",&pracownicy[i].pensja);
            wypisz_prac(i,pracownicy);
            return;
        }
    }
    printf("Nie znaleziono pracownika\n");
    system("pause");
}

void zm_premie(char nazw[], struct pracownik pracownicy[])
{
    int i;
    for(i=0;i<l_prac;i++)
    {
        if(strncmp(pracownicy[i].nazwisko,nazw,strlen(pracownicy[i].nazwisko)) == 0)
        {
            printf("Podaj nowa premie: ");
            scanf("%f",&pracownicy[i].proc_premii);
            wypisz_prac(i,pracownicy);
            return;
        }
    }
    printf("Nie znaleziono pracownika\n");
    system("pause");
}

void wyplata(char nazw[], struct pracownik pracownicy[])
{
    int i;
    for(i=0;i<l_prac;i++)
    {
        if(strncmp(pracownicy[i].nazwisko,nazw,strlen(pracownicy[i].nazwisko)) == 0)
        {
            wypisz_prac(i,pracownicy);
            printf("\nWyplata wyniesie: %.2f\n",pracownicy[i].pensja+pracownicy[i].pensja*pracownicy[i].proc_premii/100);
            system("pause");
            return;
        }
    }
    printf("Nie znaleziono pracownika\n");
    system("pause");
}

int main()
{
    struct pracownik pracownicy[l_prac];
    int akt_l_prac = 0, i;
    char wybor;

    do
    {
        system("cls");
        printf("N : nowy pracownik\n");
        printf("P : nowa wartosc pensji dla pracownika o podanym nazwisku\n");
        printf("R : nowa wartosc procentu premii dla pracownika o podanym nazwisku\n");
        printf("W : wyplata\n");
        printf("L : lista wszystkich pracownikow\n");
        printf("K : koniec programu\n");
        scanf("%c",&wybor);
        switch(wybor)
        {
        case 'N':
            {
                dodaj_prac(akt_l_prac,pracownicy);
                wypisz_prac(akt_l_prac,pracownicy);
                akt_l_prac++;
                break;
            }
        case 'P':
            {
                char temp[20];
                fflush(stdin);
                printf("Chcesz zmienic pensje osoby o nazwisku: ");
                fgets(temp, 20, stdin);
                zm_pensje(temp,pracownicy);

                break;
            }
        case 'R':
            {
                char temp[20];
                fflush(stdin);
                printf("Chcesz zmienic premie osoby o nazwisku: ");
                fgets(temp, 20, stdin);
                zm_premie(temp,pracownicy);

                break;
            }
        case 'W':
            {
                char temp[20];
                fflush(stdin);
                printf("Chcesz obliczyc wyplate osoby o nazwisku: ");
                fgets(temp, 20, stdin);
                wyplata(temp,pracownicy);

                break;
            }
        case 'L':
            {
                for(i=0;i<akt_l_prac;i++)
                {
                    wypisz_prac(i,pracownicy);
                    printf("\n");
                }
            }
        }
    }while(wybor!='K');

    return 0;
}
