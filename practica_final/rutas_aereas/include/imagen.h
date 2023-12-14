/**
 * @file imagen.h
 * @author Juan Manuel Rodri­guez Gomez
 */

#ifndef __IMAGEN_H
#define __IMAGEN_H

#include "imagenES.h"
#include <cassert>
#include <iostream>
#include <string>

/**
 * @brief Tipo de pegado
 *
 * Declara una serie de constantes para representar los distintos tipos
 * de pegado de imagenes que se pueden manejar.
 */
enum Tipo_Pegado {OPACO, BLENDING};

using namespace std;

/**
 * @brief Pixel
 *
 * Declara una serie de datos para representar un pixel de una imagen.
 */
struct Pixel {
	unsigned char r, g, b;  /**< Colores del pixel (red, green, blue) */
  	unsigned char transp;   /**< Transparencia del pixel (0 no, 255 si) */
};

/**
 * @class Imagen
 * @brief Clase creada para representar una imagen PGM o PPM.
*/
class Imagen {
  
	private:

    	Pixel **data;                 /**< Imagen (Matriz dinamica de 2D) */
    	int nf, nc;                   /**< Numero de filas y columnas de la imagen */

    	/**
		 * @brief Borra la imagen.
		 */
    	void Borrar();

    	/**
		 * @brief Copia una imagen en otra.
		 * @param I Imagena copiar.
		 */
    	void Copiar(const Imagen &I);
  
  	public:

		/**
		 * @brief Constructor por defecto.
		 */
    	Imagen();

		/**
		 * @brief Constructor con parametros.
		 * @param f Numero de filas de la imagen.
		 * @param c Numero de columnas de la imagen.
		 */
    	Imagen(int f, int c);

		/**
		 * @brief Constructor de copia
		 * @param I Imagen a copiar.
		 */
    	Imagen(const Imagen &I);

		/**
		 * @brief Operador de asignacion.
		 * @param I Imagen a asignar.
		 * @return *this Imagen actual tras la asignacion.
		 */	
    	Imagen &operator=(const Imagen &I);

		/**
		 * @brief Destructor.
		 */	
    	~Imagen();

		/**
		 * @brief Operador de indexacion (version no constante). Devuelve un pixel de la imagen.
		 * @param i Fila del pixel de la imagen que se quiere devolver.
     	 * @param j Columna del pixel de la imagen que se quiere devolver.
		 * @return Pixel de la imagen situado en la posicion (i,j).
		 */
    	Pixel &operator()(int i, int j);

		/**
		 * @brief Operador de indexacion (version constante). Devuelve un pixel constante de la imagen.
		 * @param i Fila del pixel constante de la imagen que se quiere devolver.
     	 * @param j Columna del pixel de la imagen que se quiere devolver.
		 * @return Pixel constante de la imagen situado en la posicion (i,j).
		 */
    	const Pixel &operator()(int i, int j) const;

		/**
		 * @brief Escribe una imagen en un archivo PGM o PPM segun corresponda.
		 * @param nombre Nombre de la imagen.
		 */
    	void EscribirImagen(const char *nombre);

		/**
		 * @brief Lee una imagen a partir un archivo PGM o PPM segun corresponda 
     	 * y tambien lee la respectiva mascara asociada a la imagen.
		 * @param nombre Nombre de la imagen.
		 * @param nombremascara Mascara asociada a la imagen.
		 */
    	void LeerImagen(const char *nombre, const string &nombremascara="");

		/**
		 * @brief Elimina completamente la transparencia de la imagen, es decir,
     	 * pone a 0 el valor de "transp" de cada pixel de la imagen.
		 */
    	void LimpiarTransp();

		/**
		 * @brief Coloca una imagen I en la posicion (posi, posj) de otra imagen.
		 * @param posi Fila de la imagen sobre la cual se va a colocar otra imagen I.
		 * @param posj Columna de la imagen sobre la cual se va a colocar otra imagen I.
		 * @param I Imagen a colocar.
     	 * @param tippegado Tipo de pegado con el que se va a colocar la imagen I sobre otra imagen.
		 */
    	void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado=OPACO);

		/**
		 * @brief Devuelve una subimagen a partir de una imagen.
		 * @param posi Fila de la imagen a partir de la cual se quiere obtener una subimagen. 
		 * @param posj Columna de la imagen a partir de la cual se quiere obtener una subimagen. 
		 * @param dimi Ancho de la subimagen.
     	 * @param dimj Alto de la subimagen.
     	 * @return Subimagen de dimensiones dimi x dimj obtenida a partir de la posicion (posi, posj)
     	 * de una imagen. 
     	 */
    	Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);

		/**
		 * @brief Devuelve el numero de filas de la imagen.
		 * @return Numero de filas de la imagen.
		 */
    	int num_filas() const;

		/**
		 * @brief Devuelve el numero de columnas de la imagen.
		 * @return Numero de columnas de la imagen.
		 */
    	int num_cols() const;
};   
   
#endif /* __IMAGEN_H */