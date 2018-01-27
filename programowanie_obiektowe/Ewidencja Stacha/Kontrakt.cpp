//
// Created by Stan on 2018-01-13.
//

#include "Kontrakt.h"

void Kontrakt::WyswietlAktywa()
{
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Wartosc: " << wartInw << std::endl;
    std::cout << "Podmiot: " << podmiot << std::endl;
}
Kontrakt::Kontrakt(std::string nazwa, int wartInw, std::string podmiot)
{
    this->nazwa = nazwa;
    this->wartInw = wartInw;
    this->podmiot = podmiot;
}

std::string Kontrakt::GetPodmiot()
{
    return podmiot;
}
void Kontrakt::SetPodmiot(std::string podmiot)
{
    this->podmiot = podmiot;
}