/**
 * @file Pais.h
 * @author Juan Manuel Rodri­guez Gomez
 */

#ifndef __PAIS__
#define __PAIS__

#include "Punto.h"
#include <iostream>

/**
 * @class Pais
 * @brief Clase creada para representar un pais en el mapa.
 */
class Pais {
    
    private:

        Punto p;            /**< Punto del mapa donde se encuentra el pais */
        string pais;        /**< Nombre del pais */
        string bandera;     /**< Bandera del pais */
    
    public:

		/**
		 * @brief Constructor por defecto.
		 */	
        Pais() = default;

		/**
		 * @brief Devuelve el punto del mapa donde se encuentra el pais.
		 * @return Punto del mapa donde se encuentra el pais.
		 */
        Punto GetPunto() const;

		/**
		 * @brief Devuelve el nombre del pais.
		 * @return Nombre del pais.
		 */
        string GetPais() const;

		/**
		 * @brief Devuelve la bandera del pais.
		 * @return Bandera del pais.
		 */
        string GetBandera() const;

        /**
         * @brief Operador relacional "menor que".
         * @param P Pais a comparar. 
         * @return True (1) si el nombre del pais P es "menor" que el nombre del pais actual
         * y False (0) si no lo es.
         */
        bool operator<(const Pais &P) const;

        /**
         * @brief Operador de igualdad. Compara dos paises a partir de sus nombres.
         * @param P Nombre del pais a comparar. 
         * @return True (1) si los nombres son iguales y False (0) si no lo son.
         */
        bool operator==(const Pais &P) const;

        /**
         * @brief Operador de igualdad. Compara dos paises a partir de los puntos del mapa donde se encuentran.
         * @param P Punto del mapa donde se encuentra el pais a comparar. 
         * @return True (1) si los puntos del mapa son iguales y False (0) si no lo son.
         */
        bool operator==(const Punto &P) const;

        friend istream &operator>>(istream &is, Pais &P);

        friend ostream &operator<<(ostream &os, const Pais &P);
};


/**
 * @brief Operador de entrada. Lee un pais.
 * @param is Flujo de entrada.
 * @param P Pais a leer.
 * @return Flujo de entrada "is".
 
istream &operator>>(istream &is, Pais &P);

/**
 * @brief Operador de salida. Muestra por pantalla un pais.
 * @param os Flujo de salida.
 * @param P Pais a mostrar.
 * @return Flujo de salida "os".
 
ostream &operator<<(ostream &os, const Pais &P);
*/



#endif /* __PAIS__ */
