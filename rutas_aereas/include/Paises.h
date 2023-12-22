/**
  * @file Paises.h
  * @brief Fichero cabecera Paises
  *
  * ALmacena datos de tipo Pais
  *
  */


#ifndef _PAISES_
#define _PAISES_
#include "Pais.h"
#include <set>
#include <iostream>
#include <iterator>


using namespace std;

/**
 * @brief Clase Paises
 * Clase que implementa un contenedor para almacenar y gestionar datos de tipo Paises
 * 
 */

class Paises{

    private:

        set<Pais> datos;

    public:

         /**
         * @brief Constructor por defecto de la clase paises.
        */
        Paises()=default;

        /**
         * @brief Método Insertar: inserta un país en el contenedor de paises.
         * @param P País a insertar en el contenedor.
        */
        void Insertar(const Pais &P);

        /**
         * @brief Método Borrar: borra un país del contenedor.
         * @param P País a borrar.
        */
        void Borrar(const Pais &P);

        /**
         * @brief Clase iterator implemnenta un interador (no constante) para recorrer paises. 
        */
        class const_iterator;  
                         
        class iterator{
            private:
                set<Pais>::iterator p;
            public:
                /**
                 * @brief Constructor por defecto de iteartor
                 * 
                 */
                iterator()=default;

                /**
                 * @brief Sobrecarga del operador de incremento. Incrementa en una unidad el iterador.
                 * @return Devuelve un iterador mayor en una unidad.
                */
                iterator &operator++();

                 /**
                 * @brief Sobrecarda del operador de decremento. Decrementa en una unidad el iterador.
                 * @return Devuelve un iterador menor en una unidad.
                */
                iterator &operator--();

                 /**
                 * @brief Sobrecarga del operador relacional == en la clase iterator.
                 * @param it Iterador pasado como parámetro para comparar con el otro iterador.
                 * @return Devuelve si los iteradores son iguales o no.
                */ 
                bool operator==(const iterator &it);

                /**
                 * @brief Sobrecarga del operador relacional != en la clase iterator.
                 * @param it Iterador pasado como parámetro para comparar con el otro iterador.
                 * @return Devuelve si los iteradores son distintos o no.
                */ 
                bool operator!=(const iterator &it);

                /**
                 * @brief Sobrecarga del operador consulta * en la clase iterator.
                 * @return Devuelve el elemento de tipo Pais al que apunta el iterador.
                */
                const Pais &operator*()const;

                /**
                 * @brief La clase iterator es "amiga" de la clase Paises.
                */
                friend class Paises;

                /**
                 * @brief La clase iterator es "amiga" de la clase const_iterator.
                */
                friend class const_iterator;
        };  

         /**
         * @brief clase iterador constante implementada para recorrer paises.
        */
        class const_iterator{
            private:
                set<Pais>::const_iterator p;
            public:
                /**
                 * @brief Constructor por defecto
                 * 
                 */
                const_iterator()=default;

                /**
                 * @brief Constructor por parámetros
                 * 
                 * @param it iterador 
                 */
                const_iterator (const iterator &it);
                
                //const_iterator (const iterator &it);
                /**
                 * @brief Sobrecarga del operador de asigancion. 
                 * @param it Iterador de tipo Paises constante.
                 * @return Devuelve el puntero del iterador constante al que se ha asigando. 
                */
                const_iterator &operator=(const Paises::iterator &it);

                /**
                 * @brief Sobrecarga del operador de incremento. Incrementa en una unidad el iterador constante.
                 * @return Devuelve un iterador constante mayor en una unidad.
                */
                const_iterator &operator++();

                /**
                 * @brief Sobrecarda del operador de decremento. Decrementa en una unidad el iterador constante.
                 * @return Devuelve un iterador constante constante menor en una unidad.
                */
                const_iterator &operator--();

                /**
                 * @brief Sobrecarga del operador relacional == en la clase const_iterator.
                 * @param it Iterador constante pasado como parámetro para comparar con el otro iterador constante.
                 * @return Devuelve si los iteradores constantes son iguales o no.
                */ 
                bool operator==(const const_iterator &it);

                /**
                 * @brief Sobrecarga del operador relacional != en la clase const_iterator.
                 * @param it Iterador constante pasado como parámetro para comparar con el otro iterador constante.
                 * @return Devuelve si los iteradores constantes son distintos o no.
                */  
                bool operator!=(const const_iterator &it);

                /**
                 * @brief Sobrecarga del operador consulta * en la clase const_iterator.
                 * @return Devuelve el elemento de tipo Pais al que apunta el iterador constante.
                */ 
                const Pais &operator*()const; 

                /**
                 * @brief La clase const_iterator es "amiga" de la clase Paises.
                */ 
                friend class Paises;
        
        };

        /**
         * @brief Método que hace apuntar el iterador al incio del contenedor de Paises.
         * @return Devuelve un iterador que apunta al inicio del contenedor.
        */
        iterator begin();

        /**
         * @brief Método que hace apuntar el iterador constante al incio del contenedor de Paises.
         * @return Devuelve un iterador constante que apunta al inicio del contenedor.
        */ 
        const_iterator cbegin()const;

        /**
         * @brief Método que hace apuntar el iterador al final de la contenedor de Paises.
         * @return Devuelve un iterador que apunta al final de la contenedor.
        */ 
        iterator end();

         /**
         * @brief Método que hace apuntar el iterador constante al final de la contenedor de Paises.
         * @return Devuelve un iterador constante que apunta al final de la contenedor.
        */ 
        const_iterator cend()const;

        /**
         * @brief Busca entre los paises un país que se la pasa como parámetro.
         * @param p País a buscar.
         * @return Devuelve un iterador que apunta al País que se buscaba.
        */
        iterator find(const Pais &p);

        /**
         * @brief Busca en entre los paises un punto que se la pasa como parámetro.
         * @param p Punto a buscar.
         * @return Devuelve un iterador que apunta al punto que se buscaba.
        */
        iterator find(const Punto &p);

        /**
         * @brief Operador de flujo de entrada.
         * @param is Flujo de entrada.
         * @param R Paises del mapa a leer.
         * @return Devuelve el flujjo de entrada is.
        */
        friend istream & operator>>(istream & is, Paises & R);
           
         /**
         * @brief Operador de flujo de salida.
         * @param os Flujo de entrada.
         * @param R Paises del mapa a mostrar.
         * @return Devuelve el flujjo de salida os.
        */
        friend ostream & operator<<(ostream & os, const Paises &R);


        
    

};




#endif 

/* Fin Fichero: Paises.h */