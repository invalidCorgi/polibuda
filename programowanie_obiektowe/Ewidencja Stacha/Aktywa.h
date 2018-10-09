//
// Created by Stan on 2018-01-13.
//

#ifndef EWIDENCJA_AKTYWA_H
#define EWIDENCJA_AKTYWA_H
#include <iostream>

class Aktywa {
protected:
    std::string nazwa;
    int wartInw;
public:
    virtual void WyswietlAktywa()=0;
    int GetWartoscInwestycji();
    void SetWartoscInwestycji(int);
    std::string GetNazwa();
    void SetNazwa(std::string);
};


#endif //EWIDENCJA_AKTYWA_H
