//
// Created by Stan on 2018-01-13.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Aktywa.h"
#include "IKE.h"
#include "Lokata.h"
#include "JednostkiFunduszu.h"
#include "Kontrakt.h"
#include "Nieruchomosc.h"
#include "ProduktStrukturyzowany.h"

template <class T>
class Portfel {
private:
    std::vector<T> aktywaLista;
public:
    Portfel()
    {
        aktywaLista = std::vector<T>();
        WczytajDane("savefile.s");
    }
    void DodajAktywa(T aktywa)
    {
        aktywaLista.push_back(aktywa);
    }

    Portfel<T>& operator+=(T element)
    {
        DodajAktywa(element);
    }

    void UsunAktywa(int index) {
        aktywaLista.erase(aktywaLista.begin() + index);
    }

    Portfel<T>& operator-=(int index)
    {
        UsunAktywa(index);
    }

    int GetOszczednosci()
    {
        int i;
        int oszczednosci = 0;
        for (i = 0; i < aktywaLista.size(); i++) {
            Aktywa* aktywa = (Aktywa*)aktywaLista[i];
            oszczednosci += aktywa->GetWartoscInwestycji();
        }
        return oszczednosci;
    }
    int GetSymulowaneOszczednosci()
    {
        int oszczednosci = GetOszczednosci();
        int i;
        for (i = 0; i < aktywaLista.size(); i++)
        {
            if ( dynamic_cast<Lokata*>(aktywaLista[i]) )
                oszczednosci += ((Lokata*)aktywaLista[i])->GetOprocentowanie();
            else if ( dynamic_cast<IKE*>(aktywaLista[i]) )
                oszczednosci += ((IKE*)aktywaLista[i])->GetOprocentowanie();
        }
        return oszczednosci;
    }
    void WyswietlAktywa()
    {
        int i;
        for (i = 0; i < aktywaLista.size(); i++) {
            Aktywa *aktywa = (Aktywa *) aktywaLista[i];
            std::cout << (i + 1) << ". " << aktywa->GetNazwa() << '\n';
        }
    }
    void WyswietlWybraneAktywa(int index)
    {
        ((Aktywa*)aktywaLista[index])->WyswietlAktywa();
    }
    void ZmienNazweAktywow(int index, std::string nazwa)
    {
        ((Aktywa*)aktywaLista[index])->SetNazwa(nazwa);
    }
    int LiczbaAktywow()
    {
        return aktywaLista.size();
    }
    void ZapiszDane(std::string plik)
    {
        int i;
        std::string dane = "";
        for (i = 0; i < aktywaLista.size(); i++)
        {
            dane += ((Aktywa*)aktywaLista[i])->GetNazwa();
            dane += '\n';
            dane += std::to_string(((Aktywa*)aktywaLista[i])->GetWartoscInwestycji());
            dane += '\n';
            if ( dynamic_cast<Lokata*>(aktywaLista[i]) )
            {
                dane += '1';
                dane += '\n';
                dane += std::to_string(((Lokata*)aktywaLista[i])->GetOprocentowanie());
                dane += '\n';
            }
            else if ( dynamic_cast<IKE*>(aktywaLista[i]) )
            {
                dane += '2';
                dane += '\n';
                dane += std::to_string(((IKE*)aktywaLista[i])->GetSkladka());
                dane += '\n';
                dane += std::to_string(((IKE*)aktywaLista[i])->GetOprocentowanie());
                dane += '\n';
            }
            else if ( dynamic_cast<JednostkiFunduszu*>(aktywaLista[i]) )
            {
                dane += '3';
                dane += '\n';
                dane += std::to_string(((JednostkiFunduszu*)aktywaLista[i])->GetLiczba());
                dane += '\n';
                dane += std::to_string(((JednostkiFunduszu*)aktywaLista[i])->GetWartoscJednostki());
                dane += '\n';
            }
            else if ( dynamic_cast<Kontrakt*>(aktywaLista[i]) )
            {
                dane += '4';
                dane += '\n';
                dane += ((Kontrakt*)aktywaLista[i])->GetPodmiot();
                dane += '\n';
            }
            else if ( dynamic_cast<Nieruchomosc*>(aktywaLista[i]) )
            {
                dane += '5';
                dane += '\n';
                dane += ((Nieruchomosc*)aktywaLista[i])->GetAdres();
                dane += '\n';
            }
            else if ( dynamic_cast<ProduktStrukturyzowany*>(aktywaLista[i]) )
            {
                dane += '6';
                dane += '\n';
            }
        }
        std::ofstream file(plik);
        file << dane;
        file.close();
    }

    void WczytajDane(std::string plik)
    {
        std::ifstream input(plik);
        std::string line;

        std::string nazwa;
        int wartInw;
        int typ;

        int oprocentowanie, skladka, liczba, wartJednostki;
        std::string podmiot, adres;

        if (input.is_open())
        {
            while (!input.eof() )
            {
                //odczytaj i dodaj aktywa
                getline(input,line);
                if (line == "") return;
                nazwa = line;
                getline(input,line);
                wartInw = stoi(line);
                getline(input,line);
                typ = stoi(line);
                switch (typ)
                {
                    case 1:
                        getline(input,line);
                        oprocentowanie = stoi(line);
                        DodajAktywa(new Lokata(nazwa, wartInw, oprocentowanie));
                        break;
                    case 2:
                        getline(input,line);
                        skladka = stoi(line);
                        getline(input,line);
                        oprocentowanie = stoi(line);
                        DodajAktywa(new IKE(nazwa, wartInw, skladka, oprocentowanie));
                        break;
                    case 3:
                        getline(input,line);
                        liczba = stoi(line);
                        getline(input,line);
                        wartJednostki = stoi(line);
                        DodajAktywa(new JednostkiFunduszu(nazwa, wartInw, liczba, wartJednostki));
                        break;
                    case 4:
                        getline(input,line);
                        podmiot = line;
                        DodajAktywa(new Kontrakt(nazwa, wartInw, podmiot));
                        break;
                    case 5:
                        getline(input,line);
                        adres = line;
                        DodajAktywa(new Nieruchomosc(nazwa, wartInw, adres));
                        break;
                }
            }
            input.close();
        }
    }
};