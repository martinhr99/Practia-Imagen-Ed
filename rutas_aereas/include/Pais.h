#ifndef _PAIS_
#define _PAIS_

#include <iostream>
#include "Punto.h"

using namespace std;

class Pais{
  private:
    Punto p;
    string pais;
    string bandera;

  public:
    Pais()=default;
    Punto GetPunto()const;
    string GetPais()const;
    string GetBandera()const;
    bool operator<(const Pais &P)const;
    bool operator==(const Pais &P)const;
    bool operator==(const Punto &P)const;

    friend istream & operator>>(istream & is, Pais & P);
    friend ostream & operator<<(ostream & os, const Pais &P);
};

#endif
