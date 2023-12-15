#ifndef _Punto_
#define _Punto_

#include <iostream>

using namespace std;

//@brief Esta clase representa un punto en el mapa
class Punto {
    private:

    double latitud;
    double longitud; 

    public:

    Punto();
    Punto(double lt, double log);
    Punto (const Punto &p);
    double getLatitud() const;
    double getLongitud() const;
    void setLatitud(double lt);
    void setLongitud(double lg);
    //sobre carge de menor
    bool operator ==(const Punto&p)const;

    friend istream &operator>>(istream &is, Punto &p);

    friend ostream &operator<<(ostream &os, const Punto &p);

};



#endif