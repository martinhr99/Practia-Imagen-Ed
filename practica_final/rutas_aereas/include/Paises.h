/**
 * @file Paises.h
 * @author Juan Manuel RodriÂ­guez Gomez
 */

#ifndef __PAISES__
#define __PAISES__

#include "Pais.h"
#include <iostream>
#include <set>

using namespace std;

/**
 * @class Paises
 * @brief Clase creada para representar un conjunto de paises, el cual no es mas que un set 
 * valores de tipo Pais.
 */
class Paises {

	private:
    	
    	set<Pais> datos;		/**< Conjunto de paises */

  	public:

		/**
		 * @brief Constructor por defecto.
		 */
		Paises() = default;
    
		/**
		 * @brief Inserta un nuevo pais.
		 * @param P Pais a insertar.
		 */
	  	void Insertar(const Pais &P);

		/**
		 * @brief Borra un pais.
		 * @param P Pais a borrar.
		 */
		void Borrar(const Pais &P);
      
	  	class const_iterator;

		/**
 		 * @class iterator
 		 * @brief Clase iteradora (version no constante) creada para recorrer el conjunto de paises.
 		 */
		class iterator {
			
			private:
	    		
				set<Pais>::iterator p;
			
			public:

				/**
		 		 * @brief Constructor por defecto.
		 		 */
				iterator() = default;

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
				const Pais &operator*() const;
	    		
				friend class Paises;
	    		friend class const_iterator;
		};    

		/**
 		 * @class const_iterator
 		 * @brief Clase iteradora (version constante) creada para recorrer el conjunto de paises.
 		 */
		class const_iterator {
			
			private:
	    		
				set<Pais>::const_iterator p;
		
			public:

				/**
		 		 * @brief Constructor por defecto.
		 		 */
				const_iterator() = default;

				/**
		 		 * @brief Constructor de copia.
		 		 * @param it Iterador constante a copiar.
		 		 */	
				const_iterator(const iterator &it);

				/**
		 		 * @brief Operador de asignacion.
		 		 * @param it Iterador constante a asignar.
		 		 * @return *this Iterador constante actual tras la asignacion.
		 		 */
				const_iterator &operator=(const iterator &it);

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
				const Pais &operator*() const;
	    		
				friend class Paises;
		};

		/**
		 * @brief Devuelve un iterador que apunta al inicio del conjunto de paises.
		 * @return Iterador que apunta al inicio del conjunto de paises.
		 */
		iterator begin();

		/**
		 * @brief Devuelve un iterador constante que apunta al inicio del conjunto de paises.
		 * @return Iterador constante que apunta al inicio del conjunto de paises.
		 */
		const_iterator begin() const;

		/**
		 * @brief Devuelve un iterador que apunta al final del conjunto de paises.
		 * @return Iterador que apunta al final del conjunto de paises.
		 */
		iterator end();

		/**
		 * @brief Devuelve un iterador constante que apunta al final del conjunto de paises.
		 * @return Iterador constante que apunta al final del conjunto de paises.
		 */
		const_iterator end() const;

		/**
		 * @brief Busca un pais en el conjunto de paises.
		 * @param P Pais a buscar.
		 * @return Iterador que apuntara al pais buscado si se ha encontrado o
		 * al final del conjunto de paises si no se ha encontrado.
		 */
		iterator find(const Pais &p);

		/**
		 * @brief Busca un pais en el conjunto de paises a partir de sus coordenadas en el mapa.
		 * @param p Coordenadas en el mapa del pais a buscar.
		 * @return Iterador que apuntara al pais buscado si se ha encontrado o
		 * al final del conjunto de paises si no se ha encontrado.
		 */
		iterator find(const Punto &p);
		
		friend istream &operator>>(istream &is, Paises &R);

		friend ostream &operator<<(ostream &os, const Paises &R);
};

/**
 * @brief Operador de entrada. Lee un conjunto de paises.
 * @param is Flujo de entrada.
 * @param Ps Conjunto de paises a leer.
 * @return Flujo de entrada "is".
 */
istream &operator>>(istream &is, Paises &Ps);

/**
 * @brief Operador de salida. Muestra por pantalla un conjunto de paises.
 * @param os Flujo de salida.
 * @param Ps Conjunto de paises a mostrar.
 * @return Flujo de salida "os".
 */
ostream &operator<<(ostream &os, const Paises &Ps);

#endif /* __PAISES__ */