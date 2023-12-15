#ifndef _PAISES_
#define _PAISES_
#include "Pais.h"
#include <set>
#include <iostream>
#include <iterator>


using namespace std;

class Paises{

    private:

        set<Pais> datos;

    public:

        Paises(){}

        void Insertar(const Pais &P);

        void Borrar(const Pais &P);

        class const_iterator;  
                         //Porq está aqui def y luego mas abajo y ala implemneta?
        class iterator{
            private:
                set<Pais>::iterator p;
            public:
                
                iterator &operator++();
                iterator &operator--();
                bool iterator::operator==(const iterator &it);
                bool iterator::operator!=(const iterator &it);
                const Pais &iterator::operator*()const;
         
                friend class Paises;
                friend class const_iterator;
        };  

        class const_iterator{
            private:
                set<Pais>::const_iterator p;
            public:
                //const_iterator (const iterator &it);
                const_iterator &operator=(const Paises::iterator &it); 
                const_iterator &operator++();
                const_iterator &operator--();
                bool const_iterator::operator==(const const_iterator &it);
                bool const_iterator::operator!=(const const_iterator &it);
                const Pais &const_iterator::operator*()const;   
                friend class Paises;
        
        };

        iterator begin();
        
        const_iterator begin()const;

        iterator end();

        const_iterator end()const;

        iterator find(const Pais &p);

        iterator find(const Punto &p);

        friend istream & operator>>(istream & is, Paises & R);
           
        friend ostream & operator<<(ostream & os, const Paises &R);
    

};

#endif 