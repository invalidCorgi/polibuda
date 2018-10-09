#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l_plyt_max 100
#define str_len 20

struct Plyta
{
    int nr;
    char tytul[str_len];
    char autor[str_len];
    int rok_wyd;
    char nr_kat[str_len];
    char rodz_muz[str_len];
};

void wyswietlPlyte(int i, struct Plyta plyty[])
{
    int j;
    for(j=0;j<strlen(plyty[i].tytul)-1;j++)
    {
        printf("%c",plyty[i].tytul[j]);
    }
    for(j=str_len;j>strlen(plyty[i].tytul);j--) printf(" ");
    for(j=0;j<strlen(plyty[i].autor)-1;j++)
    {
        printf("%c",plyty[i].autor[j]);
    }
    for(j=str_len;j>strlen(plyty[i].autor);j--) printf(" ");
    printf("%d         ",plyty[i].rok_wyd);
    for(j=0;j<strlen(plyty[i].nr_kat)-1;j++)
    {
        printf("%c",plyty[i].nr_kat[j]);
    }
    for(j=str_len;j>strlen(plyty[i].nr_kat);j--) printf(" ");
    for(j=0;j<strlen(plyty[i].rodz_muz)-1;j++)
    {
        printf("%c",plyty[i].rodz_muz[j]);
    }
    printf("\n");
}

void wczytajPlyte(int i, struct Plyta plyty[])
{
    printf("Plyta nr: %d\n",i+1);
    plyty[i].nr=i;
    printf("Podaj tytul: ");
    fflush(stdin);
    fgets(plyty[i].tytul, str_len, stdin);
    printf("Podaj autora: ");
    fflush(stdin);
    fgets(plyty[i].autor, str_len, stdin);
    printf("Podaj rok wydania: ");
    scanf("%d",&plyty[i].rok_wyd);
    printf("Podaj numer katalogowy: ");
    fflush(stdin);
    fgets(plyty[i].nr_kat, str_len, stdin);
    printf("Podaj rodzaj muzyki: ");
    fflush(stdin);
    fgets(plyty[i].rodz_muz, str_len, stdin);
}

void sortujPlyty(struct Plyta plyty[], int n, int param)
{
    struct Plyta temp;
    int i,j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j > 0; j--) //przesuwaj w tyl az wstawisz w odpowiednie miejsce
        {
            if (porownajPlyty(plyty, j, param))
            {
                temp = plyty[j];
                plyty[j] = plyty[j - 1];
                plyty[j - 1] = temp;
            }
            else
                break;  //wyjdz gdy jest juz w odpowiednim miejscu
        }
    }
}

int porownajPlyty(struct Plyta plyty[], int i_wiekszy, int param)
{
    switch(param)
    {
        case 1:
        {
            if ( plyty[i_wiekszy].nr < plyty[i_wiekszy-1].nr )
                return 1;
            return 0;
            break;
        }
        case 2:
        {
            int size;
            if( strlen(plyty[i_wiekszy].tytul) < strlen(plyty[i_wiekszy-1].tytul) )
                size=strlen(plyty[i_wiekszy].tytul);
            else
                size=strlen(plyty[i_wiekszy-1].tytul);
            if(strncmp(plyty[i_wiekszy].tytul,plyty[i_wiekszy-1].tytul,size)<0)
                return 1;
            return 0;
            break;
        }
        case 3:
        {
            int size;
            if( strlen(plyty[i_wiekszy].autor) < strlen(plyty[i_wiekszy-1].autor) )
                size=strlen(plyty[i_wiekszy].autor);
            else
                size=strlen(plyty[i_wiekszy-1].autor);
            if(strncmp(plyty[i_wiekszy].autor,plyty[i_wiekszy-1].autor,size)<0)
                return 1;
            return 0;
            break;
        }
        case 4:
        {
            if ( plyty[i_wiekszy].rok_wyd < plyty[i_wiekszy-1].rok_wyd )
                return 1;
            return 0;
            break;
        }
        case 5:
        {
            int size;
            if( strlen(plyty[i_wiekszy].nr_kat) < strlen(plyty[i_wiekszy-1].nr_kat) )
                size=strlen(plyty[i_wiekszy].nr_kat);
            else
                size=strlen(plyty[i_wiekszy-1].nr_kat);
            if(strncmp(plyty[i_wiekszy].nr_kat,plyty[i_wiekszy-1].nr_kat,size)<0)
                return 1;
            return 0;
            break;
        }
        case 6:
        {
            int size;
            if( strlen(plyty[i_wiekszy].rodz_muz) < strlen(plyty[i_wiekszy-1].rodz_muz) )
                size=strlen(plyty[i_wiekszy].rodz_muz);
            else
                size=strlen(plyty[i_wiekszy-1].rodz_muz);
            if(strncmp(plyty[i_wiekszy].rodz_muz,plyty[i_wiekszy-1].rodz_muz,size)<0)
                return 1;
            return 0;
            break;
        }
    }
}

int main()
{
    struct Plyta plyty[l_plyt_max];
    int akt_l_plyt = 0, i;
    char wybor;

    do
    {
        system("cls");
        printf("N : nowa plyta\n");
        printf("L : lista wszystkich plyt\n");
        printf("K : koniec programu\n");
        scanf("%c",&wybor);
        switch(wybor)
        {
        case 'N':
            {
                wczytajPlyte(akt_l_plyt,plyty);
                printf("\n");
                akt_l_plyt++;
                break;
            }
        case 'L':
            {
                int wybor2;
                do
                {
                    system("cls");
                    printf("1 - wedlug kolejnosci dodania\n2 - wedlug tytulu\n3 - wedlug autora\n4 - wedlug roku wydania\n5 - wedlug numeru katalogowego\n6 - wedlug rodzaju muzyki\nWybierasz: ");
                    scanf("%d",&wybor2);
                }while(wybor2<1 || wybor2>6);
                sortujPlyty(plyty,akt_l_plyt,wybor2);
                printf("tytul              autor              rok wydania  numer katalogowy   rodzaj muzyki\n");
                for(i=0;i<akt_l_plyt;i++)
                {
                    wyswietlPlyte(i,plyty);
                }
                system("pause");
                break;
            }
        }
    }while(wybor!='K');

    return 0;
}
