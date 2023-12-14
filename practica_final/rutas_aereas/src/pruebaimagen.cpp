/**
 * @file pruebaimagen.cpp
 * @author Juan Manuel Rodri­guez Gomez
 */

#include "imagen.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Funcion principal.
 */
int main(int argc, char *argv[]) {

  Imagen I;

  I.LeerImagen(argv[1]);
  
  I.EscribirImagen("prueba.ppm");
}