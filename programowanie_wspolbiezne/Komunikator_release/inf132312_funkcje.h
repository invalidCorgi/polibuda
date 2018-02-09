//
// Created by wojtekreg on 13.01.18.
//

#ifndef SERWER_INF132312_FUNKCJE_H
#define SERWER_INF132312_FUNKCJE_H

#include "inf132312_struktury.h"

int read_config(struct klient klienci[], struct grupa grupy[]);
int znajdz_klienta(struct klient klienci[], char nazwa[]);
int znajdz_grupe(struct grupa grupy[], char nazwa[]);
void wyswietl_stan_klientow(struct klient klienci[]);
void wyswietl_stan_grup(struct grupa grupy[]);

#endif //SERWER_INF132312_FUNKCJE_H
