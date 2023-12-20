#ifndef _IMAGEN_
#define _IMAGEN_
#include <iostream>



using namespace std;
/**
 * @enum Tipo_Pegado
 * @brief Dato de tipo enum que representa el tipo de pegado de imagen que se puede realizar.
 *  - El opaco pega la imagen con una transparencia=0.
 *  - EL Blending pega la imagen con transparencia.
*/
enum Tipo_Pegado {OPACO, BLENDING};

/**
 * @struct Pixel
 * @brief Struct que almacena el nivel de rojo, verde y azul (rgb) de la imagen y su nivel de transparencia conformando asi el pixel de la imagen.
*/

struct Pixel{

  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si

};  
/**
 * @class Imagen
 * @brief TDA Imagen creado para poder leer una imagen, realizar modificaciones y escribir dicha imagen de tipo PGM o PPM.
 * 
*/
class Imagen{

  private:
    Pixel ** data;
    int nf,nc;

    /**
     * @brief Borrar: 
     * Método encargado de borrar la imagen.
    */
    void Borrar();
   /**
     * @brief Copiar: 
     * Método encargado de copiar una imagen, pasada como parámetro I, en otra.
     * @param I 
    */ 
    void Copiar(const Imagen &I);

  public:

    /**
     * @brief Constructor por defecto de la clase imagen.  
    */ 
    Imagen();

   /**
     * @brief Constructor por parámetros de la clase imagen. 
     * @param f  Parámetro que hace referencia al número de filas.
     * @param c  Parámetro que hace referencia al número de columnas.
     * 
    */  
    Imagen(int f,int c);

    /**
     * @brief  Constructor de copia de la clase imagen.
     * @param I Imagen de referencia para crear la nueva imagen.
    */
    Imagen(const Imagen & I);

    /**
     * @brief Sobrecarga del operador de asignacion en la clase imagen.
     * @param I Imagen pasada como parámetro para asignarla a la otra imagen.
    */
    Imagen & operator=(const Imagen & I);

    /**
     * @brief Destructor de la clase imagen.
    */
    ~Imagen();

    //set y get
    /**
     * @brief Método consultor del número de filas de la imagen.
     * @return número de filas.
    */
    int num_filas()const;

     /**
     * @brief Método consultor del número de columnas de la imagen.
     * @return número de columnas.
    */
    int num_cols()const;

    /**
     * @brief Método consultor del pixel de una imagen.
     * @param i Fila donde se encuentra el pixel.
     * @param j Columna donde se encuentra el pixel.
     * @return Devuelve un pixel.
    */
    Pixel getdata(int i, int j)const;

    /**
     * @brief Sobrecarga del operador de indexacion (dato no constante).
     * @param i Fila donde se encuentra el pixel.
     * @param j Columna donde se encuentra el pixel.
     * @return Devuelve un pixel.
    */
    Pixel & operator ()(int i,int j);

     /**
     * @brief Sobrecarga del operador de indexacion (dato constante).
     * @param i Fila donde se encuentra el pixel.
     * @param j Columna donde se encuentra el pixel.
     * @return Devuelve un pixel.
    */
    const Pixel & operator ()(int i,int j)const;

    /**
     * @brief Escribe una imagen en un archivo con formato PGM o PPM según proceda.
     * @param nombre Nombre de la imagen a escribir.
    */
    void EscribirImagen(const char * nombre);

    /**
     * @brief Lee una imagen de un archivo con formato PGM o PPM según proceda.
     * @param nombre Nombre de la imagen a escribir.
     * @param nombremascara Nombre de la mascara asociada a la imagen.
    */
    void LeerImagen (const char *nombre,const string &nombremascara="");
    
    /**
     * @brief Elimina el nivel de transparencia de una imagen, dejando cada pixel con una transparencia=0. 
    */
    void LimpiarTransp();

    /**
     * @brief Posiciona una imagen  I desde la ubicación i, j de la otra imagen, con un pegado Opaco.
     * @param posi Fila desde la que se va poner la imagen.
     * @param posj Columna desde la que se va poner la imagen.
     * @param I Imagen a posicionar.
     * @param tippegado Tipo de pegado.
    */
    void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

    /**
     * @brief Extrae una parte de la imagen desde la posicion i,j.
     * @param posi Fila desde done se va a extraer.
     * @param posj Columna desde donde se va a extraer.
     * @param dimi Dimensión de las filas a extraer.
     * @param dimj Dimensión de las columnas a extraer.
    */
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);

}; 

#endif