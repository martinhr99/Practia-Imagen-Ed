#ifndef _RUTA_
#define _RUTA_

#include "Punto.h"
#include <string>
#include <list>
#include <iterator>
#include <iostream>

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

        class iterator{
            private:
                list<Punto>::iterator p;

            public:

                iterator &operator++();
                iterator &operator--();
                bool operator==(const iterator &it);
                bool operator!=(const iterator &it);
                const Punto &operator*()const;
         
                friend class Ruta;
                friend class const_iterator;

        };

        class const_iterator{
            private: 
                list<Punto>::const_iterator p;
            public:
                //const_iterator (const iterator &it);
                const_iterator &operator=(const Ruta::iterator &it); 
                const_iterator &operator++();
                const_iterator &operator--();
                bool const_iterator::operator==(const const_iterator &it);
                bool const_iterator::operator!=(const const_iterator &it);
                const Punto &const_iterator::operator*()const;   
                friend class Ruta;
        

        };

        iterator begin();
        const_iterator begin()const;
        iterator end();
        const_iterator cend()const;
        iterator find(const Punto & p);
        friend istream &operator >>(istream &is, Ruta & R);
        friend ostream &operator<<(ostream & os, Ruta & R);



};

#endif