#ifndef _RUTA_
#define _RUTA_

#include "Punto.h"
#include <string>
#include <list>
#include <iterator>
#include <iostream>

using namespace std;
/**
 * @class Ruta
 * @brief Clase Ruta: Representa una ruta en el mapa, lo cuál es basicamente un lista de puntos del mapa.
*/

class Ruta{

    private :

        list <Punto> puntos;
        string code;

    public: 

        /**
         * @brief Constructor por defecto de la clase ruta.
        */
        Ruta();

        /**
         * @brief Método Insertar: inserta un punto en la lista de puntos o ruta.
         * @param n Punto a insertar en la ruta.
        */
        void Insertar(const Punto &n);

        /**
         * @brief Método Borrar: borra un punto de la ruta.
         * @param n Punto de la ruta a borrar.
        */
        void Borrar(const Punto & n);

        /**
         * @brief Método consultor del código ,nombre, de la ruta.
         * @return Nombre de la ruta.
        */
        string getCode()const;

        /**
         * @brief Método que modifica el nombre de la ruta,
         * @param code Nombre a asignar a la ruta.
        */
        void setCode(const string &code);

        /**
         * @brief Sobrecarga del operador relacional == en la clase ruta.
         * @param R Ruta pasada como parámetro para comparar la otra ruta.
         * @return Devuelve si las rutas son iguales o no.
        */
        bool operator==(const Ruta & R )const;

        /**
         * @brief Sobrecarga del operador relacional < en la clase ruta. Tanto la latid como la longitud han de ser menores.
         * @param R Ruata pasada como parámetro para comparar con la otra ruta.
         * @return Devuelve si la ruta es menor que la pasada o no.
        */
        bool operator<(const Ruta &R )const;

        /**
         * @class Clase iterator implemnenta un interador (no constante) para recorrer una ruta. 
        */
        class iterator{
            private:
                list<Punto>::iterator p;

            public:

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
                 * @return Devuelve el elemento de tipo Punto al que  apunta el iterador.
                 *  
                */
                const Punto &operator*()const;

                /**
                 * @brief La clase iterator es "amiga" de la clase Ruta.
                */
                friend class Ruta;

                /**
                 * @brief La clase iterator es "amiga" de la clase const_iterator.
                */
                friend class const_iterator;

        };

        class const_iterator{
            private: 
                list<Punto>::const_iterator p;
            public:
                //const_iterator (const iterator &it);
                /**
                 * @brief Sobrecarga del operador de asigancion. 
                 * @param it Iterador de tipo Ruta constante.
                 * @return Devuelve el puntero del iterador constante al que se ha asigando. 
                */
                const_iterator &operator=(const Ruta::iterator &it); 

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
                bool const_iterator::operator==(const const_iterator &it);

               /**
                 * @brief Sobrecarga del operador relacional != en la clase const_iterator.
                 * @param it Iterador constante pasado como parámetro para comparar con el otro iterador constante.
                 * @return Devuelve si los iteradores constantes son distintos o no.
                */  
                bool const_iterator::operator!=(const const_iterator &it);

                /**
                 * @brief Sobrecarga del operador consulta * en la clase const_iterator.
                 * @return Devuelve el elemento de tipo Punto al que apunta el iterador constante.
                */ 
                const Punto &const_iterator::operator*()const;  

                /**
                 * @brief La clase const_iterator es "amiga" de la clase Ruta.
                */ 
                friend class Ruta;
        

        };

        /**
         * @brief Método que hace apuntar el iterador al incio de la ruta.
         * @return Devuelve un iterador que apunta al inicio de la ruta.
        */
        iterator begin();

         /**
         * @brief Método que hace apuntar el iterador constante al incio de la ruta.
         * @return Devuelve un iterador constante que apunta al inicio de la ruta.
        */
        const_iterator cbegin()const;

         /**
         * @brief Método que hace apuntar el iterador al final de la ruta.
         * @return Devuelve un iterador que apunta al final de la ruta.
        */ 
        iterator end();

         /**
         * @brief Método que hace apuntar el iterador constante al final de la ruta.
         * @return Devuelve un iterador constante que apunta al final de la ruta.
        */
        const_iterator cend()const;

        /**
         * @brief Busca en la runta un punto que se la pasa como parámetro.
         * @param p Punto a buscar.
         * @return Devuelve un iterador que apunta al punto que se buscaba.
        */
        iterator find(const Punto & p);

        /**
         * @brief Operador de flujo de entrada.
         * @param is Flujo de entrada.
         * @param R Ruta del mapa a leer.
         * @return Devuelve el flujjo de entrada is.
        */
        friend istream &operator >>(istream &is, Ruta & R);

        /**
         * @brief Operador de flujo de salida.
         * @param os Flujo de entrada.
         * @param R Ruta del mapa a mostrar.
         * @return Devuelve el flujjo de salida os.
        */
        friend ostream &operator<<(ostream & os, Ruta & R);



};

#endif