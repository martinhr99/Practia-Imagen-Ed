#include "ruta.h"
#include <iterator>



using namespace std;

Ruta::Ruta(){
    puntos.clear();
    code=nullptr;

}

void Ruta::Insertar(const Punto &n){

    puntos.push_back(n);

}
void Ruta::Borrar(const Punto & n){

    for(auto i=puntos.begin(); i!=puntos.end(); i++){
        if(*i==n){
            puntos.erase(i);
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
        
        for (auto i=puntos.begin(); i!=puntos.end(); i++){

        }
    }

    if(this->code != R.getCode()) return false;
    
}
bool Ruta::operator<(const Ruta &R )const{}

Ruta::iterator &Ruta::iterator::operator++(){
    ++p;
    return *this;
}

Ruta::iterator &Ruta::iterator::operator--(){
    --p;
    return *this;
}

const Punto &Ruta::iterator::operator*()const{
    return *p;
}


bool Ruta::iterator::operator==(const Ruta::iterator &it){
    return it.p == p;
}

bool Ruta::iterator::operator!=(const Ruta::iterator &it){
    return !(it.p==p);
}

Ruta::const_iterator &Ruta::const_iterator::operator=(const Ruta::iterator &it){
    p=it.p;
    return *this;
}
Ruta::const_iterator &Ruta::const_iterator::operator++(){
    ++p; 
    return *this;
}
Ruta::const_iterator &Ruta::const_iterator::operator--(){
    --p; 
    return *this;
}
bool Ruta::const_iterator::operator==(const const_iterator &it){
    return it.p == p;
}
bool Ruta::const_iterator::operator!=(const const_iterator &it){
    return !(it.p==p);
}
const Punto &Ruta::const_iterator::operator*()const{
    return *p;
} 




Ruta::iterator Ruta::begin(){
    iterator it;
    it.p = puntos.begin();
    return it;
}
Ruta::const_iterator Ruta::begin()const{
    const_iterator it;
    it.p = puntos.begin();
    return it;
}
Ruta::iterator Ruta::end(){
    iterator it;
    it.p = puntos.end();
    return it;
}
Ruta::const_iterator Ruta::cend()const{
    const_iterator it;
    it.p = puntos.end();
    return it;
}
Ruta::iterator Ruta::find(const Punto & p){
    
    iterator it;
    list<Punto>::iterator i;
    for ( auto i=puntos.begin(); i!=puntos.end();++i) {
        if(*i == p){
            it.p=i;
        }
        
    } 
    return it;
    
}
istream &operator >>(istream &is, Ruta & R){}
ostream &operator<<(ostream & os, Ruta & R){}



