//
// Created by wojtekreg on 12.01.18.
//

#ifndef INF132312_STRUKTURY_H
#define INF132312_STRUKTURY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <signal.h>

#define dozwolona_dlugosc_nazwy 30
#define dlugosc_wiadomosci 512
#define poczatek_osobistych_mtype 20

#define liczba_klientow 9
#define liczba_grup 3

#define logowanie_mtype 1
#define wylogowanie_mtype 2
#define podglad_zalogowanych_uzytkownikow_mtype 3
#define podglad_zapisanych_do_grupy_mtype 4
#define zapis_do_grupy_mtype 5
#define wypis_z_grupy_mtype 6
#define podglad_dostepnych_grup_mtype 7
#define wiadomosc_do_grupy_mtype 8
#define wiadomosc_do_uzytkownika_mtype 9
#define nasluchiwane_mtype 9

struct msgbuf{
    long mtype;
    char nadawca[dozwolona_dlugosc_nazwy];
    char adresat[dozwolona_dlugosc_nazwy];
    char text[dlugosc_wiadomosci];
}mymsg;

struct klient{
    long mtype;
    int zalogowany;
    char nazwa[dozwolona_dlugosc_nazwy];
};

struct grupa{
    int liczba_klientow_w_grupie;
    struct klient *zapisani_klienci[liczba_klientow];
    char nazwa[dozwolona_dlugosc_nazwy];
};

#endif //INF132312_STRUKTURY_H
