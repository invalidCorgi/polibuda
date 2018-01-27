//
// Created by Stan on 2018-01-13.
//

#ifndef EWIDENCJA_NIERUCHOMOSC_H
#define EWIDENCJA_NIERUCHOMOSC_H


#include "Aktywa.h"

class Nieruchomosc : public Aktywa {
private:
    std::string adres;
public:
    void WyswietlAktywa() override;
    Nieruchomosc(std::string,int,std::string);
    std::string GetAdres();
    void SetAdres(std::string);
};


#endif //EWIDENCJA_NIERUCHOMOSC_H
