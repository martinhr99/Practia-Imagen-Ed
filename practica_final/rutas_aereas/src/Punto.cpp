/**
 * @file Punto.cpp
 * @author Juan Manuel Rodri­guez Gomez
 */

#include "Punto.h"

/*********/
/* Punto */
/*********/

Punto::Punto() : latitud(0), longitud(0) {

}

Punto::Punto(double lat, double lng, string dcn) {
  latitud = lat;
  longitud = lng;
  descripcion = dcn;
}

double Punto::GetLatitud() const {
  return latitud;
}

double Punto::GetLongitud() const {
  return longitud;
}

bool Punto::operator==(const Punto &p) const {
  return ( (latitud == p.latitud) && (longitud == p.longitud) );
}

/************************************************************/
/* Operadores de lectura y escritura de datos de tipo Punto */
/************************************************************/

istream &operator>>(istream &is, Punto &p) {
    
  double lat, lng;
  char parentesis1, coma, parentesis2;

  is >> parentesis1 >> lat >> coma >> lng >> parentesis2;

  p = Punto(lat, lng, "");

  return is;
}

ostream &operator<<(ostream &os, const Punto &p) {
    
  os << "(" << p.latitud << "," << p.longitud << ")";

  return os;
}
