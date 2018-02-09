#include "inf132312_struktury.h"
#include "inf132312_funkcje.h"

int serwer_in;
int serwer_out;

void obslugaSigInt(){
    msgctl(serwer_in,IPC_RMID,0);
    msgctl(serwer_out,IPC_RMID,0);
    exit(2);
}

int main() {
    signal(SIGINT,obslugaSigInt);
    serwer_in = msgget(594368, IPC_CREAT | 0644);
    serwer_out = msgget(594369, IPC_CREAT | 0644);
    struct grupa grupy[liczba_grup];
    struct klient klienci[liczba_klientow];
    //zmienne wykorzystywane do przechowywania indeksow nadawcow i odbiorcow przy obsludze wiadomosci
    int indeks_grupy;
    int indeks_klienta;

    if(read_config(klienci,grupy)==-1){
        puts("Blad podczas odczytu pliku konfiguracyjnego\nPrzed wlaczeniem serwera upewnij sie, ze masz poprawny plik konfiguracyjny\nWylaczenie serwera\n");
        msgctl(serwer_in,IPC_RMID,0);
        msgctl(serwer_out,IPC_RMID,0);
        exit(1);
    }

    wyswietl_stan_klientow(klienci);
    wyswietl_stan_grup(grupy);

    while (1) {
        //sprawdzaj po kolei czy nie przyszlo jedno z obslugiwanych zadan
        for (int i = 1; i <= nasluchiwane_mtype; ++i) {
            if (msgrcv(serwer_in,&mymsg, sizeof(mymsg)- sizeof(long),i,IPC_NOWAIT)!=-1){
                switch (i){

                    case logowanie_mtype:
                        indeks_klienta = znajdz_klienta(klienci,mymsg.nadawca);
                        if (indeks_klienta==-1){
                            strcpy(mymsg.text,"-1");
                        } else if(klienci[indeks_klienta].zalogowany==1){
                            strcpy(mymsg.text,"0");
                        } else{
                            sprintf(mymsg.text,"%ld",klienci[indeks_klienta].mtype);
                            klienci[indeks_klienta].zalogowany = 1;
                        }
                        msgsnd(serwer_out,&mymsg,sizeof(mymsg)- sizeof(long),0);
                        break;

                    case wylogowanie_mtype:
                        indeks_klienta = znajdz_klienta(klienci,mymsg.nadawca);
                        strcpy(mymsg.text,"\nZostales wylogowany\n");
                        klienci[indeks_klienta].zalogowany = 0;
                        msgsnd(serwer_out,&mymsg,sizeof(mymsg)- sizeof(long),0);
                        break;

                    case podglad_zalogowanych_uzytkownikow_mtype:
                        indeks_klienta = znajdz_klienta(klienci, mymsg.nadawca);
                        mymsg.mtype = klienci[indeks_klienta].mtype;
                        strcpy(mymsg.text,"\nZalogowani uzytkownicy:\n");
                        for (int j = 0; j < liczba_klientow; ++j) {
                            if (klienci[j].zalogowany==1){
                                strcat(mymsg.text,klienci[j].nazwa);
                            }
                        }
                        msgsnd(serwer_out,&mymsg,sizeof(mymsg)- sizeof(long),0);
                        break;

                    case podglad_zapisanych_do_grupy_mtype:
                        indeks_klienta = znajdz_klienta(klienci, mymsg.nadawca);
                        mymsg.mtype = klienci[indeks_klienta].mtype;
                        indeks_grupy = znajdz_grupe(grupy,mymsg.text);
                        if (indeks_grupy==-1){
                            strcpy(mymsg.text,"\nPodana grupa nie istnieje\n");
                        } else {
                            strcpy(mymsg.text, "\nZapisani uzytkownicy do grupy ");
                            strcat(mymsg.text, grupy[indeks_grupy].nazwa);
                            for (int k = 0; k < grupy[indeks_grupy].liczba_klientow_w_grupie; ++k) {
                                strcat(mymsg.text,grupy[indeks_grupy].zapisani_klienci[k]->nazwa);
                            }
                        }
                        msgsnd(serwer_out,&mymsg,sizeof(mymsg)- sizeof(long),0);
                        break;

                    case zapis_do_grupy_mtype:
                        indeks_klienta = znajdz_klienta(klienci, mymsg.nadawca);
                        mymsg.mtype = klienci[indeks_klienta].mtype;
                        indeks_grupy = znajdz_grupe(grupy,mymsg.text);
                        if (indeks_grupy==-1){
                            strcpy(mymsg.text,"\nPodana grupa nie istnieje\n");
                        } else {
                            for (int j = 0; j < grupy[indeks_grupy].liczba_klientow_w_grupie; ++j) {
                                if (klienci[indeks_klienta].mtype == grupy[indeks_grupy].zapisani_klienci[j]->mtype){
                                    strcpy(mymsg.text,"\nJestes juz zapisany do tej grupy\n");
                                    break;
                                }
                                //jesli doszedles do konca listy klientow w grupie i nie bylo tam zadajacego to go zapisz
                                if (j==grupy[indeks_grupy].liczba_klientow_w_grupie-1){
                                    grupy[indeks_grupy].zapisani_klienci[grupy[indeks_grupy].liczba_klientow_w_grupie] = &klienci[indeks_klienta];
                                    grupy[indeks_grupy].liczba_klientow_w_grupie++;
                                    strcpy(mymsg.text,"\nZostales zapisany do grupy ");
                                    strcat(mymsg.text,grupy[indeks_grupy].nazwa);
                                    break;
                                }
                            }
                        }
                        msgsnd(serwer_out,&mymsg,sizeof(mymsg)- sizeof(long),0);
                        break;

                    case wypis_z_grupy_mtype:
                        indeks_klienta = znajdz_klienta(klienci, mymsg.nadawca);
                        mymsg.mtype = klienci[indeks_klienta].mtype;
                        indeks_grupy = znajdz_grupe(grupy,mymsg.text);
                        if (indeks_grupy==-1){
                            strcpy(mymsg.text,"\nPodana grupa nie istnieje\n");
                        } else {
                            for (int j = 0; j < grupy[indeks_grupy].liczba_klientow_w_grupie; ++j) {
                                if (klienci[indeks_klienta].mtype == grupy[indeks_grupy].zapisani_klienci[j]->mtype){
                                    grupy[indeks_grupy].liczba_klientow_w_grupie--;
                                    //przesun klientow po usuwanym o 1 blizej poczatku listy
                                    for (int k = j; k < grupy[indeks_grupy].liczba_klientow_w_grupie; ++k) {
                                        grupy[indeks_grupy].zapisani_klienci[k]=grupy[indeks_grupy].zapisani_klienci[k+1];
                                    }
                                    strcpy(mymsg.text,"\nZostales wypisany z grupy ");
                                    strcat(mymsg.text, grupy[indeks_grupy].nazwa);
                                    break;
                                }
                                //jesli doszedles do konca listy klientow w grupie i nie bylo tam zadajacego
                                if (j==grupy[indeks_grupy].liczba_klientow_w_grupie-1){
                                    strcpy(mymsg.text,"\nNie jestes czlonkiem tej grupy\n");
                                }
                            }
                        }
                        msgsnd(serwer_out,&mymsg,sizeof(mymsg)- sizeof(long),0);
                        break;

                    case podglad_dostepnych_grup_mtype:
                        indeks_klienta = znajdz_klienta(klienci, mymsg.nadawca);
                        mymsg.mtype = klienci[indeks_klienta].mtype;
                        strcpy(mymsg.text,"\nDostepne grupy:\n");
                        for (int l = 0; l < liczba_grup; ++l) {
                            strcat(mymsg.text,grupy[l].nazwa);
                        }
                        msgsnd(serwer_out,&mymsg,sizeof(mymsg)- sizeof(long),0);
                        break;

                    case wiadomosc_do_grupy_mtype:
                        indeks_grupy = znajdz_grupe(grupy, mymsg.adresat);
                        //jesli istnieje podana grupa
                        if(indeks_grupy != -1) {
                            indeks_klienta = znajdz_klienta(klienci, mymsg.nadawca);
                            //dla kazdego czlonka grupy
                            for (int m = 0; m < grupy[indeks_grupy].liczba_klientow_w_grupie; ++m) {
                                //oprocz nadawcy
                                if (grupy[indeks_grupy].zapisani_klienci[m]->mtype != klienci[indeks_klienta].mtype) {
                                    //przekaz wiadomosc
                                    mymsg.mtype = grupy[indeks_grupy].zapisani_klienci[m]->mtype;
                                    msgsnd(serwer_out, &mymsg, sizeof(mymsg) - sizeof(long), 0);
                                }
                            }
                        }
                        break;

                    case wiadomosc_do_uzytkownika_mtype:
                        indeks_klienta = znajdz_klienta(klienci, mymsg.adresat);
                        //jesli istnieje podany uzytkownik
                        if(indeks_klienta != -1) {
                            mymsg.mtype = klienci[indeks_klienta].mtype;
                            msgsnd(serwer_out, &mymsg, sizeof(mymsg) - sizeof(long), 0);
                        }
                        break;
                }
            }
        }
    }
}
