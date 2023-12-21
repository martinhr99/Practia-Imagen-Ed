/**
  * @file Paises.cpp
  * @brief Fichero con definiciones para la la clase Paises
  
  */

#include "Paises.h"




void Paises::Insertar(const Pais &P){

    datos.insert(P);

}

void Paises::Borrar(const Pais &P){

    datos.erase(P);
}

//******************************************************//
// Implementacion de la clase iterator dentro de paises // 
//******************************************************//   

    

Paises::iterator &Paises::iterator::operator++(){
    ++p;
    return *this;
}

Paises::iterator &Paises::iterator::operator--(){
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
    return it.p!=p;
}


//************************************************************//
// Implementacion de la clase const_iterator dentro de paises // 
//************************************************************//  

Paises::const_iterator::const_iterator(const iterator &it){
    p=it.p;
}

Paises::const_iterator &Paises::const_iterator::operator=(const Paises::iterator &it){
    p=it.p;
    return *this;
}

Paises::const_iterator &Paises::const_iterator::operator++(){
    ++p;
    return *this;
}

Paises::const_iterator &Paises::const_iterator::operator--(){
    --p; 
    return *this;
}

const Pais &Paises::const_iterator::operator*()const{
    return *p;
}

bool Paises::const_iterator::operator==(const Paises::const_iterator &it){
    return it.p == p;
}

bool Paises::const_iterator::operator!=(const Paises::const_iterator &it){
    return it.p!=p;
}

//*****************************************************************//
// Implementacion de los Metodos de la clase Paises con iteradores // 
//*****************************************************************//  

Paises::iterator Paises::begin(){

    iterator it;
    it.p = datos.begin();
    return it;
}  

Paises::const_iterator Paises::cbegin()const{

    const_iterator it;
    it.p = datos.begin();
    return it;

}

Paises::iterator Paises::end(){
    iterator it;
    it.p = datos.end();
    return it;
}

Paises::const_iterator Paises::cend()const{

    const_iterator it;
    it.p = datos.end();
    return it;

}

Paises::iterator Paises::find(const Pais &p){

    iterator it;
    set<Pais>::iterator i;

    for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i){
        
        it.p=i;
    }
    
    return it;
}

Paises::iterator Paises::find(const Punto &p){

    iterator it;
    set<Pais>::iterator i;
    for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
    it.p=i;
    return it;
}

istream &operator>>(istream &is, Paises &Ps) {
	
	Paises pslocal;
	
	// Leemos el comentario
	if(is.peek() == '#') {
		string a;
		getline(is, a);
	}	
	      
	Pais P;
	
	while(is >> P) {
		pslocal.Insertar(P);
	}
		  
	Ps = pslocal;
	
	return is;
}

ostream &operator<<(ostream &os, const Paises &Ps) {
	
	Paises::const_iterator it;

	for(it = Ps.cbegin(); it != Ps.cend(); ++it) {
		os << *it << "\t";
	}

	return os;
}


/* Fin Fichero: Paises.cpp */