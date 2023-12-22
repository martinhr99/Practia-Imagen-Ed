

#ifndef _RUTA_AEREA_
#define _RUTA_AEREA_
/**
 * @file ruta_aerea.cpp
 * @author Martín Hernnadez Ruiz y Sergio Albacete Martín
 * @version 0.1
 * @date 2023-12-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 *@include "imagen.h"
  *@include "Almacen_Rutas.h"
  *@include "Paises.h"
  *@include <iostream>
  *@include <cmath>
  *@include <fstream>
  *@include <iterator>
 * 
 */
#include "imagen.h"
#include "Almacen_Rutas.h"
#include "Paises.h"

#include <iostream>
#include <cmath>
#include <fstream>
#include <iterator>

using namespace std;



/** 
 * 
 * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada
 * @param Io: imagen de entrada
 * @param angulo: angulo a rotar la imagen de entrada. Debe estar en radianes.
 * @return Una nueva imagen que es la versión rotada de Io.
 * */

Imagen Rota(const Imagen & Io,double angulo){

    double rads=angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);

    //Para obtener las dimensiones de la imagen
    int rcorners[4],ccorners[4];
    int newimgrows,newimgcols;
    double new_row_min,new_col_min,new_row_max,new_col_max;
    double inter,inter1;
    rcorners[0]=0;
    rcorners[1]=0;
    ccorners[0]=0;
    ccorners[2]=0;
    rcorners[2]=Io.num_filas()-1;
    rcorners[3]=Io.num_filas()-1;
    ccorners[1]=Io.num_cols()-1;
    ccorners[3]=Io.num_cols()-1;
    new_row_min=0;
    new_col_min=0;
    new_row_max=0;
    new_col_max=0;
    newimgrows=0;
    newimgcols=0;

    for(int count=0;count<4;count++)
    {
	    inter=rcorners[count]*coseno+ccorners[count]*seno;
	   
	    if(inter<new_row_min)
		    new_row_min=inter;

	    if(inter>new_row_max)
		    new_row_max=inter;

	    inter1=-rcorners[count]*seno+ccorners[count]*coseno;
	   
	    if(inter1<new_col_min)
		    new_col_min=inter1;	

	    if(inter1>new_col_max)
		    new_col_max=inter1;
   }
    
    newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
    newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);
   
    Imagen Iout(newimgrows,newimgcols);

    for(int rows=0;rows<newimgrows;rows++) {
	      for(int cols=0;cols<newimgcols;cols++){

            float oldrowcos=((float)rows+new_row_min)*cos(-rads);
            float oldrowsin=((float)rows+new_row_min)*sin(-rads);
            float oldcolcos=((float)cols+new_col_min)*cos(-rads);
            float oldcolsin=((float)cols+new_col_min)*sin(-rads);
            float old_row=oldrowcos+oldcolsin;
            float old_col=-oldrowsin+oldcolcos;

            old_row=ceil((double)old_row);
            old_col=ceil((double)old_col);

	          if((old_row>=0) && (old_row<Io.num_filas()) && 
               (old_col>=0) && (old_col<Io.num_cols())){

	            Iout(rows,cols)=Io(old_row,old_col); 

            }else{ 
            Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
            Iout(rows,cols).transp=0;
            }
        }

    }
    return Iout;
	  
}

/**
 
 * 
 * @brief Pinta imagenes de un avion encima de otra imagen.
 * @param f1 Fila inicial de la imagen sobre la cual se va a pintar el avion.
 * @param f2 Fila final de la imagen sobre la cual se va a pintar el avion.
 * @param c1 Columna inicial de la imagen sobre la cual se va a pintar el avion.
 * @param c2 Columna final de la imagen sobre la cual se va a pintar el avion.
 * @param I Imagen sobre la cual se va a pintar el avion.
 * @param avion Imagen de un avion que se va a pintar encima de otra imagen.
 * @param mindisf Distancia entre f1 y f2.
 * @param mindisc Distancia entre c1 y c2.
 */

void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){
      
    int fila,col;

    if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){ 
	
      if (c1!=c2){

        double a,b;
        a= double(f2-f1) / double(c2-c1);
        b= f1 - a*c1;
        col = (int)(c1+c2)/2;
        fila = (int)rint(a*col+b);

      }else{

        col = c1;
        fila = (f1+f2)/2;
	    }  
	  
	  
	  double angulo = atan2((f2-f1),(c2-c1));
	  Imagen Irota= Rota(avion,angulo);
	
	  I.PutImagen(fila,col,Irota,Tipo_Pegado::OPACO);//pensar si debe ser opaco o blending
	  
	  angulo = atan2((f2-fila),(c2-col));
	  Irota=Rota(avion,angulo);
	
	  I.PutImagen(f2,c2,Irota, Tipo_Pegado::OPACO);//pensar si debe ser opaco o blending
	  angulo = atan2((fila-f1),(col-c1));
	  Irota=Rota(avion,angulo);
	
	  I.PutImagen(f1,c1,Irota, Tipo_Pegado::OPACO);//pensar si debe ser opaco o blending
	 
      
      }
     
}  
/**
 * 
 * @brief FUNCIÓN PRINCIPAL
 * @param argc 
 * @param argv Archivos .txt con la informacion de las rutas, paises y los .pgm o .ppm con las imágenes
 * @return int 
 */
int main(int argc, char * argv[]){

    if (argc!=7){

      cout<<"Los parametros son:"<<endl;
      cout<<"1.-Fichero con la informacion de los paises"<<endl;
      cout<<"2.-Nombre de la imagen con el mapa del mundo"<<endl;
      cout<<"3.-Directorio con las banderas"<<endl;
      cout<<"4.-Fichero con el almacen de rutas"<<endl;
      cout<<"5.- Nombre de la imagen con el avion"<<endl;
      cout<<"6.- Nombre de la imagen de la mascara del avion"<<endl;
      return 0;
      
    }    

    Paises Pses;
    ifstream f (argv[1]);
    f>>Pses;
    cout<<Pses;

    Imagen I;
    I.LeerImagen(argv[2]);
    
    //Leemos los aviones 
    Imagen avion;
    avion.LeerImagen(argv[5],argv[6]);

    Almacen_Rutas Ar;
    f.close();
    f.open (argv[4]);
    f>>Ar;
    cout<<"Las rutas: "<<endl<<Ar;
    cout <<endl<< "Dime el codigo de una ruta" << endl;
    string a;
    cin>>a;
    Ruta R =Ar.GetRuta(a);

    cout<<"rUTA:"<<endl;
    cout<<R<<endl;
    
    Ruta::iterator it_anterior, it;
    Paises::iterator i_paises_anterior = Pses.end();
    Paises::iterator i_paises=Pses.end();

    Imagen bandera_inicio;
    int posi_ini, posj_ini;

    
    for (it=R.begin(); it!=R.end(); ++it){
     
      Punto punto=(*it);

      cout<<endl<<"Punto "<<punto;

      i_paises_anterior=i_paises;
      i_paises=Pses.find(punto);

      string name=(*i_paises).GetBandera();
      cout<<endl<<name<<endl;
      string n_com= argv[3] + name;

      Imagen bandera;
      bandera.LeerImagen(n_com.c_str(), "");

      cout<<(*i_paises).GetPais()<<" ";

      int x= (int)((I.num_cols()/360.0) * (180 + punto.getLongitud()));
      int y= (int) ((I.num_filas()/180) * (90 - punto.getLatitud()));

      if(i_paises_anterior != Pses.end()){

        int x_old= (int)((I.num_cols()/360.0) * (180 + (*it_anterior).getLongitud()));
        int y_old= (int) ((I.num_filas()/180) * (90 - (*it_anterior).getLatitud()));

        int f1=y_old-avion.num_filas()/2;
        int f2=y-avion.num_filas()/2;
        int c1=x_old-avion.num_cols()/2;
        int c2=x-avion.num_cols()/2;
        int mindisf=20;       //Probar modificaciones 
        int mindisc=20;       //Probar modificaciones
        
        Pintar(f1,f2,c1,c2, I, avion,mindisf, mindisc);
      }

      int posi = y-bandera.num_filas()/2;
      int posj = x-bandera.num_cols()/2;
      
      I.PutImagen(posi, posj, bandera, Tipo_Pegado::BLENDING);
    
      if(i_paises != Pses.begin() ){

       posi = posi_ini-bandera_inicio.num_filas()/2;
       posj = posj_ini-bandera_inicio.num_cols()/2;
      
      I.PutImagen(posi, posj, bandera_inicio, Tipo_Pegado::BLENDING);
      }

      bandera_inicio=bandera;
      posi_ini=y;
      posj_ini=x;
      it_anterior=it;
    }
    
    string nsal = a + ".ppm";
    I.EscribirImagen(nsal.c_str());

    cout<<endl;

    
    
    

    return 0;
}

# endif
