/**
 * @file Almacen_Rutas.h
 * @author Juan Manuel Rodri­guez Gomez
 */

#ifndef __ALMACEN_RUTAS__
#define __ALMACEN_RUTAS__

#include "Ruta.h"
#include <iostream>
#include <map>

/**
 * @brief Operador de entrada. Lee un tipo de dato pair.
 * @param is Flujo de entrada.
 * @param p Pair a leer.
 * @return Flujo de entrada "is".
 */
istream &operator>>(istream &is, pair<string,Ruta> &p);

/**
 * @class Almacen_Rutas
 * @brief Clase creada para representar un conjunto de rutas, el cual no es mas que un map
 * con claves de tipo string y valores de tipo Ruta.
 */
class Almacen_Rutas {

    private:

		map<string,Ruta> rutas;		/**< Identificadores y rutas */
		multimap<Punto,string>puntos;

    public:

		/**
		 * @brief Constructor por defecto.
		 */	
        Almacen_Rutas() = default;

		/**
		 * @brief Constructor de copia.
		 * @param Ar Almacen de rutas a copiar.
		 */	
        Almacen_Rutas(const Almacen_Rutas &Ar);

		/**
		 * @brief Operador de asignacion.
		 * @param Ar Almacen de rutas a asignar.
		 * @return *this Almacen de rutas actual tras la asignacion.
		 */	
        Almacen_Rutas &operator=(const Almacen_Rutas &Ar);

		/**
		 * @brief Destructor.
		 */	
        ~Almacen_Rutas() = default;

		/**
		 * @brief Operador de indexacion (version no constante). Devuelve una ruta del almacen de rutas.
		 * @param identificador Identificador asociado a la ruta que se quiere devolver.
		 * @return Ruta asociada al identificador.
		 */
		Ruta &operator[](const string &identificador);

		/**
		 * @brief Devuelve la ruta asociada a un identificador dado.
		 * @param identificador Identificador asociado a la ruta a la que se quiere acceder.
		 * @return Ruta asociada al identificador.
		 */
		Ruta GetRuta(const string &identificador);

		/**
		 * @brief Get the Codigo object
		 * 
		 * @param ruta 
		 * @return string 
		 */
		string GetCodigo(const Ruta & ruta)const;

		/**
		 * @brief Insertar un aruta en el Almacen de Rutas
		 * 
		 * @param ruta 
		 */
		void insertar(const Ruta & ruta);
		/**
		 * @brief Comprueba si el almacen de rutas esta vacio.
		 * @return True (1) si el almacen de rutas esta vacio y False (0) si no lo esta.
		 */
		bool Vacio();

		/**
		 * @brief Añade una nueva ruta junto con su identificador asociado.
		 * @param p Pair con la ruta y su identificador asociado.
		 * @return Pair donde first apunta al nuevo elemento insertado y second es 
		 * un bool, el cual es True (1) si se ha insertado el nuevo elemento
		 *  y False (0) si no se ha insertado.
		 */
		pair<map<string,Ruta>::iterator,bool> Aniadir(pair<string,Ruta> p);

		/**
		 * @brief Elimina un identificador.
		 * @param identificador Identificador a eliminar.
		 * @note En caso de que fuese un multimap eliminaria todos los elementos con ese identificador.
		 */
		void Eliminar(const string &identificador);

		/**
		 * @brief Limpia el almacen de rutas totalmente, es decir, lo deja vacio.
		 */
		void Limpiar();
		
		/**
		 * @brief Set the Ruta object
		 * 
		 * @param cad 
		 * @param ruta 
		 */
		void SetRuta(const string cad, const Ruta &ruta);
		/**
		 * @brief Devuelve el numero de elementos del almacen de rutas.
		 * @return Numero de elementos del almacen de rutas. 
		 */
		int NumeroDeRutas() const;

        /**
         * @brief Operador de igualdad.
         * @param Ar Almacen de rutas a comparar. 
         * @return True (1) si los almacenes de rutas son iguales y False (0) si no lo son.
         */
		bool operator==(const Almacen_Rutas &Ar);

      	class const_iterator;

		/**
 		 * @class iterator
 		 * @brief Clase iteradora (version no constante) creada para recorrer el almacen de rutas.
 		 */
		class iterator {
		
			private:
	    		
				map<string,Ruta>::iterator vit;
			
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
		 		pair<const string, Ruta> &operator*();

	    		friend class Almacen_Rutas;
	    		friend class const_iterator;
		};

		/**
 		 * @class const_iterator
 		 * @brief Clase iteradora (version constante) creada para recorrer el almacen de rutas.
 		 */
		class const_iterator {
			
			private:

				map<string,Ruta>::const_iterator vit;
			
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
				const pair<const string, Ruta> &operator*() const;
	    
				friend class Almacen_Rutas;
		};

		/**
		 * @brief Devuelve un iterador que apunta al inicio del almacen de rutas.
		 * @return Iterador que apunta al inicio del almacen de rutas.
		 */
		iterator begin();

		/**
		 * @brief Devuelve un iterador constante que apunta al inicio del almacen de rutas.
		 * @return Iterador constante que apunta al inicio del almacen de rutas.
		 */
		const_iterator cbegin() const;

		/**
		 * @brief Devuelve un iterador que apunta al final del almacen de rutas.
		 * @return Iterador que apunta al final del almacen de rutas.
		 */
		iterator end();

		/**
		 * @brief Devuelve un iterador constante que apunta al final del almacen de rutas.
		 * @return Iterador constante que apunta al final del almacen de rutas.
		 */
		const_iterator cend() const;

		/**
		 * @brief Busca una ruta en el almacen de rutas.
		 * @param R Ruta a buscar.
		 * @return Iterador que apuntara a la ruta buscada si se ha encontrado o
		 *         al final del almacen de rutas si no se ha encontrado.
		 */
		iterator find(Ruta &R);

        friend istream &operator>>(istream &is, Almacen_Rutas &Ar);

        friend ostream &operator<<(ostream &os, Almacen_Rutas &Ar);
		
			
		
};



#endif /* __ALMACEN_RUTAS__ */