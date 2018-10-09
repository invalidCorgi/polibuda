//
// Created by Stan on 2018-01-13.
//

#include "ProduktStrukturyzowany.h"

void ProduktStrukturyzowany::WyswietlAktywa()
{
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Wartosc: " << wartInw << std::endl;
}
ProduktStrukturyzowany::ProduktStrukturyzowany(std::string nazwa, int wartInw)
{
    this->nazwa = nazwa;
    this->wartInw = wartInw;
}