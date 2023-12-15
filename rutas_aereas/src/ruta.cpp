#include "ruta.h"

using namespace std;

Ruta::Ruta(){
    puntos.clear();
    code=nullptr;

}

void Ruta::Insertar(const Punto &n){
    puntos.insert(++puntos.end(), n);
}
void Ruta::Borrar(const Punto & n){
    iterator it=puntos.begin();
    
    for(auto i=it; i<puntos.end(); i++){
        if(*it==n){
            puntos.erase(it);
        }
    }
    
}

string Ruta::getCode()const{
    return code;
}

void Ruta::setCode(const string &c){
    this->code=c;
}

bool Ruta::operator==(const Ruta & R )const{
    if(puntos.size()!= R.puntos.size()) return false;
    else{
        
        for (auto i=puntos.begin(); i<puntos.end(); i++){

        }
    }

    if(this->code != R.getCode()) return false;
    
}
bool operator<(const Ruta &R )const;

        Ruta::list<Punto>::iterator &Ruta::iterator::operator++(){
            ++p;
            return *this;
        }

        Ruta::iterator &Ruta::iterator::operator--(){
            --p;
            return *this;
        }

         const Pais &Paises::iterator::operator*()const{
            return *p;
        }


        bool Paises::iterator::operator==(const Paises::iterator &it){
            return it.p == p;
        }

        bool Paises::iterator::operator!=(const Paises::iterator &it){
            return !(it.p==p);
        }

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
        
