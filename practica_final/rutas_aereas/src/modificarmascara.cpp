/**
 * @file modificarmascara.cpp
 * @author Juan Manuel Rodri­guez Gomez
 */

#include "imagen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/**
 * @brief Funcion principal.
 */
int main(int argc, char *argv[]) {

  if(argc != 3) {
    cout << "Los parametros son :" << endl;
    cout << "1.-La imagen de entrada" << endl;
    cout << "1.-La imagen mascara" << endl;
    return 0;
  }

  Imagen I;
  I.LeerImagen(argv[1],argv[2]);
  I.LimpiarTransp();
  I.EscribirImagen(argv[1]);
}  