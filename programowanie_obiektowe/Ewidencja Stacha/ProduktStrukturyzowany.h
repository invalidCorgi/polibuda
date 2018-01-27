//
// Created by Stan on 2018-01-13.
//

#ifndef EWIDENCJA_PRODUKTSTRUKTURYZOWANY_H
#define EWIDENCJA_PRODUKTSTRUKTURYZOWANY_H


#include "Aktywa.h"

class ProduktStrukturyzowany : public Aktywa {
public:
    void WyswietlAktywa() override;
    ProduktStrukturyzowany(std::string,int);
};


#endif //EWIDENCJA_PRODUKTSTRUKTURYZOWANY_H
