#include "Punto.h"

#include <iostream>

using namespace std;

//@brief Esta clase representa un punto en el mapa


    Punto::Punto(){
        longitud=0;
        latitud=0;
    }
    Punto::Punto(double lt, double log){
        latitud=lt;
        longitud=log;

    }

    Punto::Punto (const Punto &p){
        latitud=p.getLatitud();
        longitud=p.getLongitud();
    }
    double Punto::getLatitud()const{
        return latitud;
    }
    double Punto::getLongitud()const{
        return longitud;
    }
    bool Punto::operator ==(const Punto&p)const{
        return ((this->getLatitud()== p.getLatitud()) && (this->getLongitud() == p.getLongitud()));
    }



  istream &operator>>(istream &is, Punto&p){
  double lt, log;
  char parentesis1, coma, parentesis2;

  is >> parentesis1 >> lt >> coma >> log >> parentesis2;

  p = Punto(lt, log);

  return is;
}

ostream &operator<<(ostream &os, const Punto &p) {
    
  os << "(" << p.latitud << "," << p.longitud << ")";

  return os;
}