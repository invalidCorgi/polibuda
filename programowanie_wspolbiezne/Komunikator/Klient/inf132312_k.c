#include "inf132312_struktury.h"

int main() {
    char nazwa[dozwolona_dlugosc_nazwy] = "niezalogowany\n";
    char nazwa_bez_new_line[dozwolona_dlugosc_nazwy] = "niezalogowany";
    long mtype = 0;
    int pid_dziecka = 0;
    char bufor[dlugosc_wiadomosci];
    int serwer_in = msgget(594368,0644);
    int serwer_out = msgget(594369,0644);
    if(serwer_in==-1 || serwer_out==-1){
        puts("Serwer jest wylaczony, sprobuj ponownie pozniej");
        exit(0);
    }

    while (1){
        //tricky console clear
        //printf("\x1B[2J\x1B[H");
        //wyswietl "znak zachety"
        printf("[%s]$ ",nazwa_bez_new_line);
        //czytaj polecenie wraz z new line, dalsze strlen(bufor)-1 ignoruja new line
        fgets(bufor,dlugosc_wiadomosci,stdin);
        if (!strncmp(bufor,"help",strlen(bufor)-1)){
            puts("Dostepne komendy:");
            puts("help - pomoc, w ktorej jestes ;P");
            puts("login - logowanie");
            puts("logout - wylogowanie");
            puts("finger - podglad zalogowanych uzytkownikow");
            puts("grfinger - podglad dostepnych grup");
            puts("grprev - podglad zapisanych uzytkownikow do podanej grupy");
            puts("grin - zapis do podanej grupy");
            puts("grout - wypisanie sie z podanej grupy");
            puts("grsend - wyslanie wiadomosci do grupy");
            puts("usend - wyslanie wiadomosci do uzytkownika");
            puts("exit - wyjscie z programu");
            continue;
        } else if (!strncmp(bufor,"exit",strlen(bufor)-1)){
            if (strcmp(nazwa_bez_new_line,"niezalogowany")){
                puts("Przed wyjsciem wyloguj sie");
                continue;
            }
            break;
        } else if (!strncmp(bufor,"login",strlen(bufor)-1)){
            if (strcmp(nazwa_bez_new_line,"niezalogowany")){
                puts("Przed zalogowaniem wyloguj sie");
                continue;
            }
            //wyslij zadanie logowania i natychmiast czekaj na odpowiedz
            puts("Podaj nazwe uzytkownika:");
            fgets(mymsg.nadawca,dozwolona_dlugosc_nazwy,stdin);
            mymsg.mtype=logowanie_mtype;
            msgsnd(serwer_in,&mymsg,sizeof(mymsg)- sizeof(long),0);
            msgrcv(serwer_out,&mymsg,sizeof(mymsg)- sizeof(long),logowanie_mtype,0);
            int tmp_mtype = atoi(mymsg.text);
            if (tmp_mtype==-1){
                puts("Nie ma takiego uzytkownika w bazie lub jest aktualnie zalogowany");
                continue;
            } else{
                mtype = tmp_mtype;
                strcpy(nazwa,mymsg.nadawca);
                strcpy(nazwa_bez_new_line,nazwa);
                nazwa_bez_new_line[strlen(nazwa)-1] = '\0';
                //uruchom dziecko odbierajace wiadomosci na naszym mtype
                if ((pid_dziecka=fork())==0){
                    while (1){
                        msgrcv(serwer_out, &mymsg, sizeof(mymsg) - sizeof(long), mtype, 0);
                        //jesli adresatem jestesmy my, to wiadomosc jest od uzytkownika
                        if (!strcmp(mymsg.adresat, nazwa)) {
                            strcpy(bufor, "\nWiadomosc od uzytkownika ");
                            strcat(bufor, mymsg.nadawca);
                            strcat(bufor, "Tresc:\n");
                            strcat(bufor, mymsg.text);
                        }
                        //jesli nadawca jestesmy my, to jest to odpowiedz serwera na zadanie
                        else if (!strcmp(mymsg.nadawca, nazwa)) {
                            strcpy(bufor,mymsg.text);
                        }
                        //w przeciwnym wypadku jest to wiadomosc od grupy
                        else {
                            strcpy(bufor, "\nWiadomosc z grupy ");
                            strcat(bufor, mymsg.adresat);
                            strcat(bufor, "Od uzytkownika ");
                            strcat(bufor, mymsg.nadawca);
                            strcat(bufor, "Tresc:\n");
                            strcat(bufor, mymsg.text);
                        }
                        puts(bufor);
                    }
                }
            }
        }
        //reszta polecen wymaga zalogowania sie
        else if (!strcmp(nazwa_bez_new_line,"niezalogowany")) {
            puts("Musisz byc zalogowany");
            continue;
        } else {
            if (!strncmp(bufor, "logout", strlen(bufor) - 1)) {
                //przy wylogowaniu zabij dziecko odbierajace wiadomosci dla do tej pory zalogowanego uzytkownika
                kill(pid_dziecka,SIGKILL);
                //wyslij zadanie wylogowania na serwer, natychmiast czekaj na odpowiedz
                mymsg.mtype = wylogowanie_mtype;
                msgsnd(serwer_in, &mymsg, sizeof(mymsg) - sizeof(long), 0);
                msgrcv(serwer_out, &mymsg, sizeof(mymsg) - sizeof(long), wylogowanie_mtype, 0);
                puts(mymsg.text);
                //i wroc do stanu poczatkowego
                strcpy(nazwa, "niezalogowany\n");
                strcpy(nazwa_bez_new_line, "niezalogowany");
                mtype = 0;
            } else if (!strncmp(bufor, "finger", strlen(bufor) - 1)) {
                mymsg.mtype = podglad_zalogowanych_uzytkownikow_mtype;
                msgsnd(serwer_in, &mymsg, sizeof(mymsg) - sizeof(long), 0);
            } else if (!strncmp(bufor, "grfinger", strlen(bufor) - 1)) {
                mymsg.mtype = podglad_dostepnych_grup_mtype;
                msgsnd(serwer_in, &mymsg, sizeof(mymsg) - sizeof(long), 0);
            } else if (!strncmp(bufor, "grprev", strlen(bufor) - 1)) {
                puts("Podaj nazwe grupy:");
                fgets(mymsg.text, dozwolona_dlugosc_nazwy, stdin);
                mymsg.mtype = podglad_zapisanych_do_grupy_mtype;
                msgsnd(serwer_in, &mymsg, sizeof(mymsg) - sizeof(long), 0);
            } else if (!strncmp(bufor, "grin", strlen(bufor) - 1)) {
                puts("Podaj nazwe grupy:");
                fgets(mymsg.text, dozwolona_dlugosc_nazwy, stdin);
                mymsg.mtype = zapis_do_grupy_mtype;
                msgsnd(serwer_in, &mymsg, sizeof(mymsg) - sizeof(long), 0);
            } else if (!strncmp(bufor, "grout", strlen(bufor) - 1)) {
                puts("Podaj nazwe grupy:");
                fgets(mymsg.text, dozwolona_dlugosc_nazwy, stdin);
                mymsg.mtype = wypis_z_grupy_mtype;
                msgsnd(serwer_in, &mymsg, sizeof(mymsg) - sizeof(long), 0);
            } else if (!strncmp(bufor, "grsend", strlen(bufor) - 1)) {
                puts("Podaj nazwe grupy:");
                fgets(mymsg.adresat, dozwolona_dlugosc_nazwy, stdin);
                puts("Podaj wiadomosc:");
                fgets(mymsg.text, dlugosc_wiadomosci, stdin);
                mymsg.mtype = wiadomosc_do_grupy_mtype;
                msgsnd(serwer_in, &mymsg, sizeof(mymsg) - sizeof(long), 0);
            } else if (!strncmp(bufor, "usend", strlen(bufor) - 1)) {
                puts("Podaj nazwe uzytkownika:");
                fgets(mymsg.adresat, dozwolona_dlugosc_nazwy, stdin);
                puts("Podaj wiadomosc:");
                fgets(mymsg.text, dlugosc_wiadomosci, stdin);
                mymsg.mtype = wiadomosc_do_uzytkownika_mtype;
                msgsnd(serwer_in, &mymsg, sizeof(mymsg) - sizeof(long), 0);
            }
        }
    }

    return 0;
}