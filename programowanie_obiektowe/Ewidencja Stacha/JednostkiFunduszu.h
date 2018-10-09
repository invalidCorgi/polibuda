//
// Created by Stan on 2018-01-13.
//

#ifndef EWIDENCJA_JEDNOSTKIFUNDUSZU_H
#define EWIDENCJA_JEDNOSTKIFUNDUSZU_H


#include "Aktywa.h"

class JednostkiFunduszu : public Aktywa {
private:
    int liczba;
    int wartJednostki;
public:
    void WyswietlAktywa() override;
    JednostkiFunduszu(std::string,int,int, int);
    int GetLiczba();
    void SetLiczba(int);
    int GetWartoscJednostki();
    void SetWartoscJednostki(int);
};


#endif //EWIDENCJA_JEDNOSTKIFUNDUSZU_H
