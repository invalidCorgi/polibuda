//
// Created by Stan on 2018-01-13.
//

#include "IKE.h"

void IKE::WyswietlAktywa()
{
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Wartosc: " << wartInw << std::endl;
    std::cout << "Skladka: " << skladka << std::endl;
    std::cout << "Oprocentowanie: " << oprocentowanie << std::endl;
}
IKE::IKE(std::string nazwa, int wartInw, int skladka, int oprocentowanie)
{
    this->nazwa = nazwa;
    this->wartInw = wartInw;
    this->skladka = skladka;
    this->oprocentowanie = oprocentowanie;
}
int IKE::GetSkladka()
{
    return skladka;
}
void IKE::SetSkladka(int skladka)
{
    this->skladka = skladka;
}
int IKE::GetOprocentowanie()
{
    return oprocentowanie;
}
void IKE::SetOprocentowanie(int oprocentowanie)
{
    this->oprocentowanie = oprocentowanie;
}