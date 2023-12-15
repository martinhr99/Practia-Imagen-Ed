#ifndef _RUTA_
#define _RUTA_

#include "Punto.h"
#include <string>
#include <list>
#include <iterator>

using namespace std;
class Ruta{

    private :

        list <Punto> puntos;
        string code;

    public: 

        Ruta();
        void Insertar(const Punto &n);
        void Borrar(const Punto & n);
        string getCode()const;
        void setCode(const string &code);
        bool operator==(const Ruta & R )const;
        bool operator<(const Ruta &R )const;

        class iterrator{
            private:
                list<Punto>::iterator p;

            public:

        };

        class const_iterator{
            private: 
                list<Punto>::const_iterator p;
            public:

        };
        iterator begin();
        const_iterator begin()const;
        iterator end();
        const_iterator end()const;
        iterator find(const Punto & p);
        friend istream &operator >>(istream &is, Ruta & R);
        friend ostream &operator<<(ostream & os, Ruta & R);



}

#endif