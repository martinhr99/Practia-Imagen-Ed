#include<iostream>
#include"Pais.h"

using namespace std;



Punto Pais::GetPunto()const{
    return p;
}

string Pais::GetPais()const{
    return pais;
}

string Pais::GetBandera()const{
    return bandera;
}

bool Pais::operator<(const Pais &P)const{
    return pais<P.pais;
  
}

bool Pais::operator==(const Pais &P)const{
    return pais == P.pais;
}
bool Pais::operator==(const Punto &P)const{
    return (this->p == P);
}

 istream & operator>>(istream & is, Pais & P){
    double lat,lng;

    is>>lat>>lng>>P.pais>>P.bandera;
    P.p=Punto(lat,lng,"");

    return is;
}

 ostream & operator<<(ostream & os, const Pais &P){
    os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
    return os;
}
