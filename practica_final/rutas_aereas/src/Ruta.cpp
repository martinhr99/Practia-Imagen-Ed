/**
 * @file Ruta.cpp
 * @author Juan Manuel Rodri­guez Gomez
 */

#include "Ruta.h"

/********/
/* Ruta */
/********/

Ruta::Ruta(const Ruta &R) : puntos(R.puntos) {

}

Ruta &Ruta::operator=(const Ruta &R) {

    if(this != &R)
        this->puntos = R.puntos;

    return *this;
}

bool Ruta::Vacia() {
  return puntos.empty();
}

void Ruta::AniadirAlPrincipio(const Punto &p) {
  puntos.push_front(p);
}

void Ruta::QuitarAlPrincipio() {
  if( !Vacia() )
    puntos.pop_front();
}

void Ruta::AniadirAlFinal(const Punto &p) {
  puntos.push_back(p);
}

void Ruta::QuitarAlFinal() {
  if( !Vacia() )
    puntos.pop_back();
}

bool Ruta::operator==(const Ruta &R) const {
  return puntos == R.puntos;
}

void Ruta::Insertar(const list<Punto>::iterator &it, const Punto &p) {
  puntos.insert(it, p);
}

void Ruta::Eliminar(const list<Punto>::iterator &it) {
  puntos.erase(it);
}

void Ruta::Limpiar() {
  puntos.clear();
}

int Ruta::NumeroDePuntos() const {
  return puntos.size();
}

/******************/
/* Ruta::iterator */
/******************/

Ruta::iterator::iterator(const Ruta::iterator &it) {
	this->vit = it.vit;
}

Ruta::iterator &Ruta::iterator::operator=(const Ruta::iterator &it) {
  
  if(this != &it)
    this->vit = it.vit;

	return *this;
}

Ruta::iterator &Ruta::iterator::operator++() {
  ++vit;
  return *this;
}

Ruta::iterator &Ruta::iterator::operator--() {
  --vit;
  return *this;
}

bool Ruta::iterator::operator==(const Ruta::iterator &it) {
  return it.vit == this->vit;
}

bool Ruta::iterator::operator!=(const Ruta::iterator &it) {
  return it.vit != this->vit;
}

const Punto &Ruta::iterator::operator*() const {
  return *vit;
}

/************************/
/* Ruta::const_iterator */
/************************/

Ruta::const_iterator::const_iterator(const Ruta::const_iterator &it) {
  this->vit = it.vit;
}

Ruta::const_iterator &Ruta::const_iterator::operator=(const Ruta::const_iterator &it) {

  if(this != &it)
    this->vit = it.vit;

	return *this;
}	

Ruta::const_iterator &Ruta::const_iterator::operator++() {
  ++vit;
  return *this;
}

Ruta::const_iterator &Ruta::const_iterator::operator--() {
  --vit;
  return *this;
}

bool Ruta::const_iterator::operator==(const Ruta::const_iterator &it) {
  return it.vit == this->vit;
}

bool Ruta::const_iterator::operator!=(const Ruta::const_iterator &it) {
  return it.vit != this->vit;
}

const Punto &Ruta::const_iterator::operator*() const {
  return *vit;
}

/********/
/* Ruta */
/********/

Ruta::iterator Ruta::begin() {

  iterator it;

  it.vit = puntos.begin();

  return it;
}  

Ruta::const_iterator Ruta::cbegin() const {

  const_iterator it;
    
  it.vit = puntos.begin();
    
  return it;
}

Ruta::iterator Ruta::end() {
    
  iterator it;
    
  it.vit = puntos.end();
    
  return it;
}

Ruta::const_iterator Ruta::cend() const {
    
  const_iterator it;
    
  it.vit = puntos.end();
    
  return it;
}

Ruta::iterator Ruta::find(const Punto &p) {

  iterator it;
  list<Punto>::iterator i;

  for(i = puntos.begin(); i != puntos.end() && !( (*i) == p ); ++i);
    it.vit = i;
  
  return it;
}

/***********************************************************/
/* Operadores de lectura y escritura de datos de tipo Ruta */
/***********************************************************/

istream &operator>>(istream &is, Ruta &R) {
  
  Ruta aux;

  int num_puntos = 0;

  is >> num_puntos;

  Punto p;

  for(int i = 0; i < num_puntos; ++i) {
    is >> p;
    aux.AniadirAlFinal(p);
  }

  R = aux;
    
  return is;
}

ostream &operator<<(ostream &os, Ruta &R) {
  
  Ruta::const_iterator it;

  os << R.NumeroDePuntos() << " ";
  
  for(it = R.cbegin(); it != R.cend(); ++it) {
    
    Punto p = (*it);
    
    os << p << " ";
  }

  return os;
}
