//
// Created by Stan on 2018-01-13.
//

#include "Lokata.h"

void Lokata::WyswietlAktywa()
{
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Wartosc: " << wartInw << std::endl;
    std::cout << "Oprocentowanie: " << oprocentowanie << std::endl;
}
Lokata::Lokata(std::string nazwa, int wartInw, int oprocentowanie)
{
    this->nazwa = nazwa;
    this->wartInw = wartInw;
    this->oprocentowanie = oprocentowanie;
}
int Lokata::GetOprocentowanie()
{
    return oprocentowanie;
}
void Lokata::SetOprocentowanie(int oprocentowanie)
{
    this->oprocentowanie = oprocentowanie;
}