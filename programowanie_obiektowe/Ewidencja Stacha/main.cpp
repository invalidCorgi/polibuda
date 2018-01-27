#include <iostream>
#include <fstream>
#include "Portfel.cpp"
#include "Lokata.h"
#include "JednostkiFunduszu.h"
#include "Kontrakt.h"
#include "ProduktStrukturyzowany.h"
#include "Nieruchomosc.h"
#include "IKE.h"

int main() {
    Portfel<Aktywa *> portfel = Portfel<Aktywa *>();
    char input = '0';
    std::string inputStr = "";
    do {
        std::cout
                << "\nWitaj w swojej ewidencji! Podaj liczbe:\n1. Wyswietl oszczednosci\n2. Symuluj oszczednosci na nastepny miesiac\n3. Wyswietl informacje o aktywach\n4. Dodaj aktywa\n5. Usun aktywa\n6. Edytuj aktywa\n7. Wyjdz"
                << std::endl;
        portfel.ZapiszDane("savefile.s");

        std::cin >> input;
        switch (input) {
            // <editor-fold defaultstate="collapsed" desc="Wyswietl oszczednosci">
            case '1': //wyswietl oszczednosci
            {
                int oszczednosci = portfel.GetOszczednosci();
                std::cout << "Twoje laczne oszczednosci to: " << oszczednosci << std::endl;
                break;
            }
                // </editor-fold>
            // <editor-fold defaultstate="collapsed" desc="Symuluj oszczednosci">
            case '2':
            {
                int oszczednosci = portfel.GetSymulowaneOszczednosci();
                std::cout << "Twoje laczne oszczednosci w przyszlym miesiacu (z uwzglednieniem miesiecznego oprocentowania lokat oraz IKE) to: " << oszczednosci << std::endl;
                break;
            }
            // </editor-fold>
            // <editor-fold defaultstate="collapsed" desc="Wyswietl aktywa">
            case '3':
            {
                std::cout << "Wybierz numer aktywow do wyswietlenia:" << std::endl;
                portfel.WyswietlAktywa();
                std::cin >> inputStr;
                int index = 0;
                try { index = stoi(inputStr); } catch (...) {}
                index--;
                if (index < portfel.LiczbaAktywow() && index > -1)
                    portfel.WyswietlWybraneAktywa(index);
                break;
            }
            // </editor-fold>
            // <editor-fold defaultstate="collapsed" desc="Dodaj aktywa">
            case '4': //dodaj aktywa
            {
                    std::cout
                            << "Wybierz rodzaj aktywow do dodania:\n1. Lokata\n2. Jednostki funduszu\n3. Kontrakt\n4. Produkt strukturyzowany\n5. Nieruchomosc\n6. IKE"
                            << std::endl;
                    std::cin >> input;
                    switch (input)
                    {
                        case '1': //Lokata
                        {
                            std::string nazwa;
                            int wartInw = 0;
                            int oprocentowanie = 0;
                            std::cout << "Podaj nazwe:" << std::endl;
                            std::cin >> nazwa;
                            std::cout << "Podaj wartosc:"<< std::endl;
                            std::cin >> inputStr;
                            try { wartInw = stoi(inputStr); } catch (...) {}
                            std::cout << "Podaj oprocentowanie:" << std::endl;
                            std::cin >> inputStr;
                            try { oprocentowanie = stoi(inputStr); } catch (...) {}
                            portfel += new Lokata(nazwa, wartInw, oprocentowanie);
                            break;
                        }
                        case '2': //Jednostki funduszu
                        {
                            std::string nazwa;
                            int wartInw = 0;
                            int liczba = 0;
                            int wartJednostki = 0;
                            std::cout << "Podaj nazwe:" << std::endl;
                            std::cin >> nazwa;
                            std::cout << "Podaj wartosc:"<< std::endl;
                            std::cin >> inputStr;
                            try { wartInw = stoi(inputStr); } catch (...) {}
                            std::cout << "Podaj liczbe zakupionych jednostek funduszu:" << std::endl;
                            std::cin >> inputStr;
                            try { liczba = stoi(inputStr); } catch (...) {}
                            std::cout << "Podaj wartosc jednostki:" << std::endl;
                            std::cin >> inputStr;
                            try { wartJednostki = stoi(inputStr); } catch (...) {}
                            portfel += new JednostkiFunduszu(nazwa, wartInw, liczba, wartJednostki);
                            break;
                        }
                        case '3': //Kontrakt
                        {
                            std::string nazwa;
                            int wartInw = 0;
                            std::string podmiot;
                            std::cout << "Podaj nazwe:" << std::endl;
                            std::cin >> nazwa;
                            std::cout << "Podaj wartosc:"<< std::endl;
                            std::cin >> inputStr;
                            try { wartInw = stoi(inputStr); } catch (...) {}
                            std::cout << "Podaj nazwe podmiotu:" << std::endl;
                            std::cin >> podmiot;
                            portfel += new Kontrakt(nazwa, wartInw, podmiot);
                            break;
                        }
                        case '4': //Produkt strukturyzowany
                        {
                            std::string nazwa;
                            int wartInw = 0;
                            std::cout << "Podaj nazwe:" << std::endl;
                            std::cin >> nazwa;
                            std::cout << "Podaj wartosc:"<< std::endl;
                            std::cin >> inputStr;
                            try { wartInw = stoi(inputStr); } catch (...) {}
                            portfel += new ProduktStrukturyzowany(nazwa, wartInw);
                            break;
                        }
                        case '5': //Nieruchomosc
                        {
                            std::string nazwa;
                            int wartInw = 0;
                            std::string adres;
                            std::cout << "Podaj nazwe:" << std::endl;
                            std::cin >> nazwa;
                            std::cout << "Podaj wartosc:"<< std::endl;
                            std::cin >> inputStr;
                            try { wartInw = stoi(inputStr); } catch (...) {}
                            std::cout << "Podaj adres:" << std::endl;
                            std::cin >> adres;
                            portfel += new Nieruchomosc(nazwa, wartInw, adres);
                            break;
                        }
                        case '6': //IKE
                        {
                            std::string nazwa;
                            int wartInw = 0;
                            int skladka = 0;
                            int oprocentowanie = 0;
                            std::cout << "Podaj nazwe:" << std::endl;
                            std::cin >> nazwa;
                            std::cout << "Podaj wartosc:"<< std::endl;
                            std::cin >> inputStr;
                            try { wartInw = stoi(inputStr); } catch (...) {}
                            std::cout << "Podaj skladke:" << std::endl;
                            std::cin >> inputStr;
                            try { skladka = stoi(inputStr); } catch (...) {}
                            std::cout << "Podaj oprocentowanie:" << std::endl;
                            std::cin >> inputStr;
                            try { oprocentowanie = stoi(inputStr); } catch (...) {}
                            portfel += new IKE(nazwa, wartInw, skladka, oprocentowanie);
                            break;
                        }
                    }
                break;
            }
            // </editor-fold>
            // <editor-fold defaultstate="collapsed" desc="Usun aktywa">
            case '5': {
                std::cout << "Wybierz numer aktywow do usuniecia:" << std::endl;
                portfel.WyswietlAktywa();
                std::cin >> inputStr;
                int index = 0;
                try { index = stoi(inputStr); } catch (...) {}
                index--;
                if (index < portfel.LiczbaAktywow() && index > -1)
                    portfel -= index;
                break;
            }
            // </editor-fold>
            // <editor-fold defaultstate="collapsed" desc="Edytuj aktywa">
            case '6': {
                std::cout << "Wybierz numer aktywow do edycji:" << std::endl;
                portfel.WyswietlAktywa();
                std::cin >> inputStr;
                int index = 0;
                try { index = stoi(inputStr); } catch (...) {}
                index--;
                if (index < portfel.LiczbaAktywow() && index > -1)
                {
                    std::cout << "Wprowadz nowa nazwe aktywow:" << std::endl;
                    std::cin >> inputStr;
                    portfel.ZmienNazweAktywow(index, inputStr);
                }
                break;
            }
            // </editor-fold>
            // <editor-fold defaultstate="collapsed" desc="Wyjdz">
            case '7': {
                return 0;
            }
            // </editor-fold>
        }
    } while (1);
}