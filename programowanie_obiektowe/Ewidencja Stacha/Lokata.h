//
// Created by Stan on 2018-01-13.
//

#ifndef EWIDENCJA_LOKATA_H
#define EWIDENCJA_LOKATA_H


#include "Aktywa.h"

class Lokata : public Aktywa {
private:
    int oprocentowanie;
public:
    void WyswietlAktywa() override;
    Lokata(std::string,int,int);
    int GetOprocentowanie();
    void SetOprocentowanie(int);
};


#endif //EWIDENCJA_LOKATA_H
