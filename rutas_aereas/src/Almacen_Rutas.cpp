/**
 * @file Almacen_Rutas.cpp
 * @author Juan Manuel Rodri­guez Gomez
 */

#include "Almacen_Rutas.h"

/*********************************************/
/* Operador de lectura de datos de tipo pair */
/*********************************************/

istream &operator>>(istream &is, pair<string,Ruta> &p) {
	  
	is >> p.first;
	is >> p.second;

	return is;
}

/*****************/
/* Almacen_Rutas */
/*****************/

Almacen_Rutas::Almacen_Rutas(const Almacen_Rutas &Ar) : rutas( Ar.rutas.begin(), Ar.rutas.end() ) {

}

Almacen_Rutas &Almacen_Rutas::operator=(const Almacen_Rutas &Ar) {

    if(this != &Ar)
        this->rutas = Ar.rutas;

    return *this;
}

Ruta &Almacen_Rutas::operator[](const string &identificador) {
  return rutas[identificador];
}

Ruta Almacen_Rutas::GetRuta(const string &identificador) {
  return rutas[identificador];
}

bool Almacen_Rutas::Vacio() {
  return rutas.empty();
}

pair<map<string,Ruta>::iterator,bool> Almacen_Rutas::Aniadir(pair<string,Ruta> p) {

	pair<map<string,Ruta>::iterator,bool> ret;

	ret = rutas.insert(p); 
	
	return ret;   
}

void Almacen_Rutas::Eliminar(const string &identificador) {

  map<string,Ruta>::iterator itlow = rutas.lower_bound(identificador);		// Primero que tiene dicho identificador
	map<string,Ruta>::iterator itupper = rutas.upper_bound(identificador);	// Primero que ya no tiene dicho identificador
	
	rutas.erase(itlow, itupper);		// Borramos todos aquellos que tienen dicho identificador
}

void Almacen_Rutas::Limpiar() {
  rutas.clear();
}

int Almacen_Rutas::NumeroDeRutas() const {
  return rutas.size();
}

bool Almacen_Rutas::operator==(const Almacen_Rutas &Ar) {
  return rutas == Ar.rutas;
}

/***************************/
/* Almacen_Rutas::iterator */
/***************************/

Almacen_Rutas::iterator::iterator(const Almacen_Rutas::iterator &it) {
	this->vit = it.vit;
}

Almacen_Rutas::iterator &Almacen_Rutas::iterator::operator=(const Almacen_Rutas::iterator &it) {

  if(this != &it)
    this->vit = it.vit;

	return *this;
}

Almacen_Rutas::iterator &Almacen_Rutas::iterator::operator++() {
  ++vit;
  return *this;
}

Almacen_Rutas::iterator &Almacen_Rutas::iterator::operator--() {
  --vit;
  return *this;
}

bool Almacen_Rutas::iterator::operator==(const Almacen_Rutas::iterator &it) {
  return it.vit == this->vit;
}

bool Almacen_Rutas::iterator::operator!=(const Almacen_Rutas::iterator &it) {
  return it.vit != this->vit;
}

pair<const string,Ruta> &Almacen_Rutas::iterator::operator*() {
  return *vit;
}

/*********************************/
/* Almacen_Rutas::const_iterator */
/*********************************/

Almacen_Rutas::const_iterator::const_iterator(const Almacen_Rutas::const_iterator &it) {
  this->vit = it.vit;
}

Almacen_Rutas::const_iterator &Almacen_Rutas::const_iterator::operator=(const Almacen_Rutas::const_iterator &it) {

  if(this != &it)
    this->vit = it.vit;

	return *this;
}	

Almacen_Rutas::const_iterator &Almacen_Rutas::const_iterator::operator++() {
  ++vit;
  return *this;
}

Almacen_Rutas::const_iterator &Almacen_Rutas::const_iterator::operator--() {
  --vit;
  return *this;
}

bool Almacen_Rutas::const_iterator::operator==(const Almacen_Rutas::const_iterator &it) {
  return it.vit == this->vit;
}

bool Almacen_Rutas::const_iterator::operator!=(const Almacen_Rutas::const_iterator &it) {
  return it.vit != this->vit;
}

const pair<const string,Ruta> &Almacen_Rutas::const_iterator::operator*() const {
  return *vit;
}

/*****************/
/* Almacen_Rutas */
/*****************/

Almacen_Rutas::iterator Almacen_Rutas::begin() {

  iterator it;

  it.vit = rutas.begin();

  return it;
}  

Almacen_Rutas::const_iterator Almacen_Rutas::cbegin() const {

  const_iterator it;
    
  it.vit = rutas.begin();
    
  return it;
}

Almacen_Rutas::iterator Almacen_Rutas::end() {
    
  iterator it;
    
  it.vit = rutas.end();
    
  return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::cend() const {
    
  const_iterator it;
    
  it.vit = rutas.end();
    
  return it;
}

Almacen_Rutas::iterator Almacen_Rutas::find(Ruta &R) {

  iterator it;
  map<string,Ruta>::iterator i;

  for(i = rutas.begin(); i != rutas.end() && !( (*i).second == R ); ++i);
    it.vit = i;
  
  return it;
}

/********************************************************************/
/* Operadores de lectura y escritura de datos de tipo Almacen_Rutas */
/********************************************************************/

istream &operator>>(istream &is, Almacen_Rutas &Ar) {

	pair<string,Ruta> p;
	Almacen_Rutas aux;
	
	// Leemos el comentario
	if(is.peek() == '#') {
		string a;
	        getline(is, a);
	}

	while(is >> p)
		aux.Aniadir(p);

	Ar = aux;

	return is;
}

ostream &operator<<(ostream &os, Almacen_Rutas &Ar) {

	map<string,Ruta>::iterator it;

	for(it = Ar.rutas.begin(); it != Ar.rutas.end(); ++it)
		os << it->first << " " << it->second << endl;

	return os;
}
