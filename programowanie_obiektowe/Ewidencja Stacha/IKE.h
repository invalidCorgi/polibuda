//
// Created by Stan on 2018-01-13.
//

#ifndef EWIDENCJA_IKE_H
#define EWIDENCJA_IKE_H


#include "Aktywa.h"

class IKE : public Aktywa {
private:
    int skladka;
    int oprocentowanie;
public:
    void WyswietlAktywa() override;
    IKE(std::string,int,int,int);
    int GetSkladka();
    void SetSkladka(int);
    int GetOprocentowanie();
    void SetOprocentowanie(int);
};


#endif //EWIDENCJA_IKE_H
