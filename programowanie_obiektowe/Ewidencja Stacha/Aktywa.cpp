//
// Created by Stan on 2018-01-13.
//

#include "Aktywa.h"
int Aktywa::GetWartoscInwestycji()
{
    return wartInw;
}
void Aktywa::SetWartoscInwestycji(int wartInw)
{
    this->wartInw = wartInw;
}
std::string Aktywa::GetNazwa()
{
    return nazwa;
}
void Aktywa::SetNazwa(std::string nazwa)
{
    this->nazwa = nazwa;
}