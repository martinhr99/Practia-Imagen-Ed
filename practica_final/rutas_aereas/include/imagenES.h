/**
 * @file imagenES.h
 * @brief Fichero cabecera para la E/S de imágenes
 *
 * Permite la E/S de archivos de tipos PGM,PPM
 *
 * @author Juan Manuel Rodri­guez Gomez
 */

#ifndef _IMAGEN_ES_H_
#define _IMAGEN_ES_H_

/**
 * @brief Tipo de imagen
 * 
 * Declara una serie de constantes para representar los distintos tipos
 * de imágenes que se pueden manejar.
 *
 * @see LeerTipoImagen
 */
enum TipoImagen {IMG_DESCONOCIDO, /**< Tipo de imagen desconocido */ 
                 IMG_PGM,         /**< Imagen tipo PGM */ 
                 IMG_PPM          /**< Imagen tipo PPM */ 
                };

/**
 * @brief Consulta el tipo de imagen del archivo y sus dimensiones.
 * @param nombre Nombre del archivo de disco a consultar.
 * @param filas Parametro de salida con las filas de la imagen.
 * @param columnas Parametro de salida con las columnas de la imagen.
 * @return Devuelve el tipo de la imagen en el archivo.
 * @see TipoImagen
 */
TipoImagen LeerTipoImagen(const char nombre[], int& filas, int& columnas);

/**
 * @brief Lee una imagen de tipo PPM sobre memoria reservada.
 * @param nombre Nombre del archivo a leer.
 * @param filas Parametro de salida con las filas de la imagen.
 * @param columnas Parametro de salida con las columnas de la imagen.
 * @param buffer Zona de memoria para obtener el valor de cada uno de los pixeles
 * como tripletas consecutivas en formato RGB (RGBRGBRGB...) por filas
 * desde la esquina superior izqda a la inferior drcha. 
 * @return Si se ha tenido exito en la lectura.
 * @pre Buffer debe ser una zona de memoria suficientemente grande como para
 * almacenar @a filas x @a columnas x 3 * bytes de datos de la imagen.
 */
bool LeerImagenPPM(const char nombre[], int& filas, int& columnas, unsigned char buffer[]);

/**
 * @brief Escribe una imagen de tipo PPM.
 * @param nombre Nombre del archivo a escribir.
 * @param datos Punteros a los @a f x @a c x 3 bytes que corresponden a los valores
 * de los píxeles de la imagen en formato RGB.
 * @param f Filas de la imagen.
 * @param c Columnas de la imagen.
 * @retval True (1) si se ha tenido exito en la escritura.
 * @retval False (0) si se ha producido algun error en la escritura.
 */
bool EscribirImagenPPM(const char nombre[], const unsigned char datos[], int f, int c);

/**
 * @brief Lee una imagen de tipo PGM sobre memoria reservada.
 * @param nombre Nombre del archivo a leer.
 * @param filas Parametro de salida con las filas de la imagen.
 * @param columnas Parametro de salida con las columnas de la imagen.
 * @param buffer Zona de memoria para obtener el valor de cada uno de los pixeles
 * como un valor de gris desde la esquina superior izqda a la inferior drcha. 
 * @return Si se ha tenido exito en la lectura.
 * @pre Buffer debe ser una zona de memoria suficientemente grande como para
 * almacenar @a filas x @a columnas bytes de datos de la imagen.
 */
bool LeerImagenPGM(const char nombre[], int& filas, int& columnas, unsigned char buffer[]);

/**
 * @brief Escribe una imagen de tipo PGM.
 * @param nombre Nombre del archivo a escribir.
 * @param datos Punteros a los @a f x @a c bytes que corresponden a los valores
 * de los píxeles de la imagen de grises.
 * @param f Filas de la imagen.
 * @param c Columnas de la imagen.
 * @retval True (1) si se ha tenido exito en la escritura.
 * @retval False (0) si se ha producido algún error en la escritura.
 */
bool EscribirImagenPGM(const char nombre[], const unsigned char datos[], int f, int c);

#endif /* _IMAGEN_ES_H_ */