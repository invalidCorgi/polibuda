//
// Created by wojtekreg on 13.01.18.
//

#include "inf132312_funkcje.h"

int read_config(struct klient klienci[], struct grupa grupy[]){
    FILE *fd;
    char bufor[dozwolona_dlugosc_nazwy];
    fd = fopen("config.txt","r");
    if (fd == NULL){
        return -1;
    }
    for (int i=0;i<liczba_klientow;i++){
        klienci[i].mtype = poczatek_osobistych_mtype+i;
        klienci[i].zalogowany = 0;
        fgets(klienci[i].nazwa,dozwolona_dlugosc_nazwy,fd);
    }
    for (int i=0;i<liczba_grup;i++){
        fgets(grupy[i].nazwa,dozwolona_dlugosc_nazwy,fd);
        fgets(bufor,dozwolona_dlugosc_nazwy,fd);
        grupy[i].liczba_klientow_w_grupie = atoi(bufor);
        for (int j = 0; j < grupy[i].liczba_klientow_w_grupie; ++j) {
            fgets(bufor,dozwolona_dlugosc_nazwy,fd);
            int indeks = znajdz_klienta(klienci,bufor);
            grupy[i].zapisani_klienci[j] = &klienci[indeks];
        }
    }
    fclose(fd);
    return 0;
}

int znajdz_klienta(struct klient klienci[], char nazwa[]){
    for (int i = 0; i < liczba_klientow; ++i) {
        if (!strcmp(nazwa,klienci[i].nazwa)){
            return i;
        }
    }
    return -1;
}

int znajdz_grupe(struct grupa grupy[], char nazwa[]){
    for (int i = 0; i < liczba_grup; ++i) {
        if (!strcmp(nazwa,grupy[i].nazwa)){
            return i;
        }
    }
    return -1;
}

void wyswietl_stan_klientow(struct klient klienci[]){
    for (int i = 0; i < liczba_klientow; ++i) {
        printf("%sZalogowany: %d\nmtype: %ld\n",klienci[i].nazwa,klienci[i].zalogowany,klienci[i].mtype);
    }
}

void wyswietl_stan_grup(struct grupa grupy[]){
    for (int i = 0; i < liczba_grup; ++i) {
        printf("%sLiczba klientow w grupie: %d\nZapisani klienci:\n",grupy[i].nazwa,grupy[i].liczba_klientow_w_grupie);
        for (int j = 0; j < grupy[i].liczba_klientow_w_grupie; ++j) {
            printf("%s",grupy[i].zapisani_klienci[j]->nazwa);
        }
    }
}