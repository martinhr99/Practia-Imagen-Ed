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
    list<Punto>::iterator i;
    for(i=puntos.begin(); i!=puntos.end(); i++){
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
   return puntos==R.puntos;
    
}
bool Ruta::operator<(const Ruta & R )const{

    list<Punto>::const_iterator it;
    list<Punto>::const_iterator r;
    it=puntos.begin();
    r=R.puntos.begin();

    //Suponemos que una ruta es menor que la otra si almenos un un punto es menor que el otro
    for(; it!=puntos.end() && r!=R.puntos.end(); it++){

        if(*it<*r) return true;

    }

}

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
Ruta::const_iterator Ruta::cbegin()const{
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

istream &operator >>(istream &is, Ruta & R){
   Ruta aux;

  int num_puntos = 0;

  is >> num_puntos;

  Punto p;

  for(int i = 0; i < num_puntos; ++i) {
    is >> p;
    aux.Insertar(p);
  }

  R = aux;
    
  return is;
}
ostream &operator<<(ostream & os, Ruta & R){
    Ruta::const_iterator it;

  os << R.puntos.size() << " ";
  
  for(it = R.cbegin(); it != R.cend(); ++it) {
    
    Punto p = (*it);
    
    os << p << " ";
  }

  return os;

}



