/**
 * @file Punto.h
 * @author Juan Manuel Rodri­guez Gomez
 */

#ifndef __PUNTO__
#define __PUNTO__

#include <iostream>

using namespace std;

/**
 * @class Punto
 * @brief Clase creada para representar un punto en el mapa.
 */
class Punto {

    private:

        double latitud;         /**< Latitud del punto */
        double longitud;        /**< Longitud del punto */
        string descripcion;     /**< Descripcion del lugar descrito por el punto */
    
    public:

		/**
		 * @brief Constructor por defecto.
		 */	
        Punto();

		/**
		 * @brief Constructor con parametros.
		 */	
        Punto(double lat, double lng, string dcn);

		/**
		 * @brief Devuelve la latitud del punto del mapa.
		 * @return Latitud del punto del mapa.
		 */
        double GetLatitud() const;

		/**
		 * @brief Devuelve la longitud del punto del mapa.
		 * @return Longitud del punto del mapa.
		 */
        double GetLongitud() const;

        /**
         * @brief Operador de igualdad.
         * @param p Punto del mapa a comparar. 
         * @return True (1) si los puntos del mapa son iguales y False (0) si no lo son.
         */
        bool operator==(const Punto &p) const;

        friend istream &operator>>(istream &is, Punto &p);

        friend ostream &operator<<(ostream &os, const Punto &p);
};

/**
 * @brief Operador de entrada. Lee un punto del mapa.
 * @param is Flujo de entrada.
 * @param p Punto del mapa a leer.
 * @return Flujo de entrada "is".
 */
istream &operator>>(istream &is, Punto &p);

/**
 * @brief Operador de salida. Muestra por pantalla un punto del mapa.
 * @param os Flujo de salida.
 * @param p Punto del mapa a mostrar.
 * @return Flujo de salida "os".
 */
ostream &operator<<(ostream &os, const Punto &p);

#endif /* __PUNTO__ */