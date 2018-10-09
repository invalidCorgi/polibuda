//
// Created by Stan on 2018-01-13.
//

#ifndef EWIDENCJA_KONTRAKT_H
#define EWIDENCJA_KONTRAKT_H
#include <iostream>
#include "Aktywa.h"

class Kontrakt : public Aktywa {
private:
    std::string podmiot;
public:
    void WyswietlAktywa() override;
    Kontrakt(std::string,int,std::string);
    std::string GetPodmiot();
    void SetPodmiot(std::string);
};


#endif //EWIDENCJA_KONTRAKT_H
