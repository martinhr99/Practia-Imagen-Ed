/**
 * @file Ruta.h
 * @author Juan Manuel Rodri­guez Gomez
 */

#ifndef __RUTA__
#define __RUTA__

#include "Punto.h"
#include <iostream>
#include <list>

using namespace std;

/**
 * @class Ruta
 * @brief Clase creada para representar una ruta, la cual no es mas que una lista de puntos del mapa.
 */
class Ruta {

    private:

        list<Punto> puntos;		/**< Lista de puntos del mapa */
    
    public:

		/**
		 * @brief Constructor por defecto.
		 */	
        Ruta() = default;

		/**
		 * @brief Constructor de copia.
		 * @param R Ruta a copiar.
		 */	
        Ruta(const Ruta &R);

		/**
		 * @brief Operador de asignacion.
		 * @param R Ruta a asignar.
		 * @return *this Ruta actual tras la asignacion.
		 */	
        Ruta &operator=(const Ruta &R);

		/**
		 * @brief Destructor.
		 */
        ~Ruta() = default;

		/**
		 * @brief Comprueba si la ruta esta vacia.
		 * @return True (1) si la ruta esta vacia y False (0) si no lo esta.
		 */
		bool Vacia();

		/**
		 * @brief Añade un nuevo punto del mapa al principio de la ruta.
		 * @param p Punto del mapa a añadir al principio de la ruta.
		 */
        void AniadirAlPrincipio(const Punto &p);

		/**
		 * @brief Elimina un punto del mapa del principio de la ruta.
		 */
		void QuitarAlPrincipio();

		/**
		 * @brief Añade un nuevo punto del mapa al final de la ruta.
		 * @param p Punto del mapa a añadir al final de la ruta.
		 */
        void AniadirAlFinal(const Punto &p);

		/**
		 * @brief Elimina un punto del mapa del final de la ruta.
		 */
		void QuitarAlFinal();

        /**
         * @brief Operador de igualdad.
         * @param R Ruta a comparar. 
         * @return True (1) si las rutas son iguales y False (0) si no lo son.
         */
		bool operator==(const Ruta &R) const;

		/**
		 * @brief Inserta un nuevo punto del mapa a la ruta en la posicion apuntada por el iterador "it".
		 * @param it Iterador que apunta a una posición de la lista de puntos del mapa.
		 * @param p Punto del mapa a insertar en la posicion apuntada por el iterador "it".
		 */
      	void Insertar(const list<Punto>::iterator &it, const Punto &p);

		/**
		 * @brief Elimina un punto del mapa de la ruta situado en la posicion apuntada por el iterador "it".
		 * @param it Iterador que apunta a una posición de la lista de puntos del mapa.
		 */
		void Eliminar(const list<Punto>::iterator &it);

		/**
		 * @brief Limpia la ruta totalmente, es decir, la deja vacia.
		 */
		void Limpiar();

		/**
		 * @brief Devuelve el numero de elementos de la ruta.
		 * @return Numero de elementos de la ruta.
		 */
		int NumeroDePuntos() const;

      	class const_iterator;

		/**
 		 * @class iterator
 		 * @brief Clase iteradora (version no constante) creada para recorrer la ruta.
 		 */
		class iterator {
		
			private:
	    		
				list<Punto>::iterator vit;
			
			public:

				/**
		 		 * @brief Constructor por defecto.
		 		 */	
				iterator() = default;

				/**
		 		 * @brief Constructor de copia.
		 		 * @param it Iterador a copiar.
		 		 */	
				iterator(const iterator &it);

				/**
		 		 * @brief Operador de asignacion.
		 		 * @param it Iterador a asignar.
		 		 * @return *this Iterador actual tras la asignacion.
		 		 */	
			    iterator &operator=(const iterator &it);

				/**
		 		 * @brief Operador de incremento prefijo.
		 		 * @return *this Iterador actual tras el incremento.
		 		 */
				iterator &operator++();

				/**
		 		 * @brief Operador de decremento prefijo.
		 		 * @return *this Iterador actual tras el decremento.
		 		 */
	    		iterator &operator--();

				/**
		 		 * @brief Operador de igualdad.
				 * @param it Iterador a comparar. 
		 		 * @return True (1) si los iteradores son iguales y False (0) si no lo son.
		 		 */
	    		bool operator==(const iterator &it);

				/**
		 		 * @brief Operador de desigualdad.
				 * @param it Iterador a comparar. 
		 		 * @return True (1) si los iteradores no son iguales y False (0) si lo son.
		 		 */
				bool operator!=(const iterator &it);

				/**
		 		 * @brief Operador de consulta.
		 		 * @return Elemento al que apunta el iterador.
		 		 */
		 		const Punto &operator*() const;

	    		friend class Ruta;
	    		friend class const_iterator;
		};

		/**
 		 * @class const_iterator
 		 * @brief Clase iteradora (version constante) creada para recorrer la ruta.
 		 */
		class const_iterator {
			
			private:

				list<Punto>::const_iterator vit;
			
			public:

				/**
		 		 * @brief Constructor por defecto.
		 		 */
				const_iterator() = default;

				/**
		 		 * @brief Constructor de copia.
		 		 * @param it Iterador constante a copiar.
		 		 */	
				const_iterator(const const_iterator &it);

				/**
		 		 * @brief Operador de asignacion.
		 		 * @param it Iterador constante a asignar.
		 		 * @return *this Iterador constante actual tras la asignacion.
		 		 */	
	    		const_iterator &operator=(const const_iterator &it);

				/**
		 		 * @brief Operador de incremento prefijo.
		 		 * @return *this Iterador constante actual tras el incremento.
		 		 */
				const_iterator &operator++();

				/**
		 		 * @brief Operador de decremento prefijo.
		 		 * @return *this Iterador constante actual tras el decremento.
		 		 */
	    		const_iterator &operator--();

				/**
		 		 * @brief Operador de igualdad.
				 * @param it Iterador constante a comparar. 
		 		 * @return True (1) si los iteradores constantes son iguales y False (0) si no lo son.
		 		 */
				bool operator==(const const_iterator &it);

				/**
		 		 * @brief Operador de desigualdad.
				 * @param it Iterador constante a comparar. 
		 		 * @return True (1) si los iteradores constantes no son iguales y False (0) si lo son.
		 		 */
				bool operator!=(const const_iterator &it);

				/**
		 		 * @brief Operador de consulta.
		 		 * @return Elemento al que apunta el iterador constante.
		 		 */
				const Punto &operator*() const;
	    
				friend class Ruta;
		};

		/**
		 * @brief Devuelve un iterador que apunta al inicio de la ruta.
		 * @return Iterador que apunta al inicio de la ruta.
		 */
		iterator begin();

		/**
		 * @brief Devuelve un iterador constante que apunta al inicio de la ruta.
		 * @return Iterador constante que apunta al inicio de la ruta.
		 */
		const_iterator cbegin() const;

		/**
		 * @brief Devuelve un iterador que apunta al final de la ruta.
		 * @return Iterador que apunta al final de la ruta.
		 */
		iterator end();

		/**
		 * @brief Devuelve un iterador constante que apunta al final de la ruta.
		 * @return Iterador constante que apunta al final de la ruta.
		 */
		const_iterator cend() const;

		/**
		 * @brief Busca un punto del mapa en la ruta.
		 * @param p Punto del mapa a buscar.
		 * @return Iterador que apuntara al punto del mapa buscado si se ha encontrado o
		 * al final de la ruta si no se ha encontrado.
		 */
		iterator find(const Punto &p);

        friend istream &operator>>(istream &is, Ruta &R);

        friend ostream &operator<<(ostream &os, Ruta &R);
};

/**
 * @brief Operador de entrada. Lee una ruta.
 * @param is Flujo de entrada.
 * @param R Ruta a leer.
 * @return Flujo de entrada "is".
 */
istream &operator>>(istream &is, Ruta &R);

/**
 * @brief Operador de salida. Muestra por pantalla una ruta.
 * @param os Flujo de salida.
 * @param R Ruta a mostrar.
 * @return Flujo de salida "os".
 */
ostream &operator<<(ostream &os, Ruta &R);

#endif /* __RUTA__ */