//
// Created by Stan on 2018-01-13.
//

#include "JednostkiFunduszu.h"

void JednostkiFunduszu::WyswietlAktywa()
{
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Wartosc: " << wartInw << std::endl;
    std::cout << "Liczba jednostek: " << liczba << std::endl;
    std::cout << "Wartosc jednostki: " << wartJednostki << std::endl;
}
JednostkiFunduszu::JednostkiFunduszu(std::string nazwa, int wartInw, int liczba, int wartJednostki)
{
    this->nazwa = nazwa;
    this->wartInw = wartInw;
    this->liczba = liczba;
    this->wartJednostki = wartJednostki;
}
int JednostkiFunduszu::GetLiczba()
{
    return liczba;
}
void JednostkiFunduszu::SetLiczba(int liczba)
{
    this->liczba = liczba;
}
int JednostkiFunduszu::GetWartoscJednostki()
{
    return wartJednostki;
}
void JednostkiFunduszu::SetWartoscJednostki(int wartJednostki)
{
    this->wartJednostki = wartJednostki;
}