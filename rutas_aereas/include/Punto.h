/**
  * @file Punto.h
  * @brief Fichero cabecera clase Punto
  *
  */


#ifndef _Punto_
#define _Punto_

#include <iostream>

using namespace std;

/**
 * @class Punto.
 * @brief Esta clase representa un punto en el mapa.
 */
class Punto {
    private:

    double latitud;
    double longitud; 

    public:

     /**
     * @brief Constructor por defecto de la clase punto.  
    */ 
    Punto();

    /**
     * @brief Constructor por parámetros de la clase punto. 
     * @param lt  Parámetro que hace referencia a la latitud del punto.
     * @param log  Parámetro que hace referencia a la longitud de punto.
     * 
    */  
    Punto(double lt, double log);

    /**
     * @brief  Constructor de copia de la clase punto.
     * @param p Punto de referencia para crear el nuevo punto.
    */
    Punto (const Punto &p);

    /**
     * @brief Método consultor de la latitud del punto.
     * @return Latitud del punto.
    */
    double getLatitud() const;

    /**
     * @brief Método consultor de la longitud del punto.
     * @return Longitud del punto.
    */ 
    double getLongitud() const;

    /**
     * @brief Método modificador de la latitud del punto.
     * @param lt Latitud a modificar del punto.
    */
    void setLatitud(double lt);

    /**
     * @brief Método modificador de la longitud del punto.
     * @param lg Longitud a modificar del punto.
    */
    void setLongitud(double lg);

    /**
     * @brief Sobrecarga del operador relacional < en la clase punto.
     * @param p Punto pasado como parámetro para comparar con el otro punto.
     * @return Devuelve si el punto es menor que el pasado o no.
    */
    bool operator <(const Punto &p)const;

    /**
     * @brief Sobrecarga del operador relacional == en la clase punto.
     * @param p Punto pasado como parámetro para comparar con el otro punto.
     * @return Devuelve si los puntos son iguales o no.
    */
    bool operator ==(const Punto&p)const;

    /**
     * @brief Operador de flujo de entrada.
     * @param is Flujo de entrada.
     * @param p Punto del mapa a leer.
     * @return Devuelve el flujjo de entrada is.
    */
    friend istream &operator>>(istream &is, Punto &p);

     /**
     * @brief Operador de flujo de salida.
     * @param os Flujo de entrada.
     * @param p Punto del mapa a mostrar.
     * @return Devuelve el flujjo de salida os.
    */
    friend ostream &operator<<(ostream &os, const Punto &p);

};



#endif
/* Fin Fichero: Punto.h */