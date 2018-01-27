//
// Created by Stan on 2018-01-13.
//

#include "Nieruchomosc.h"

void Nieruchomosc::WyswietlAktywa()
{
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Wartosc: " << wartInw << std::endl;
    std::cout << "Adres: " << adres << std::endl;
}

Nieruchomosc::Nieruchomosc(std::string nazwa, int wartInw, std::string adres)
{
    this->nazwa = nazwa;
    this->wartInw = wartInw;
    this->adres = adres;
}
std::string Nieruchomosc::GetAdres()
{
    return adres;
}
void Nieruchomosc::SetAdres(std::string adres)
{
    this->adres = adres;
}