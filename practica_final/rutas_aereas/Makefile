SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

# ************ Compilación ************	

$(OBJ)/rutas_aereas: $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/Pais.o $(OBJ)/Paises.o $(OBJ)/Punto.o $(OBJ)/Ruta.o $(OBJ)/Almacen_Rutas.o
	echo Creando el ejecutable rutas_aereas
	g++ $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/Pais.o $(OBJ)/Paises.o $(OBJ)/Punto.o $(OBJ)/Ruta.o $(OBJ)/Almacen_Rutas.o -o $(BIN)/rutas_aereas

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp
	echo Creando rutas_aereas.o
	g++ -g -c -I./$(INC) $(SRC)/rutas_aereas.cpp -o $(OBJ)/rutas_aereas.o -std=c++11

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	echo Creando imagen.o
	g++ -g -c -I./$(INC) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -std=c++11

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	echo Creando imagenES.o
	g++ -g -c -I./$(INC) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o -std=c++11

$(OBJ)/Pais.o: $(SRC)/Pais.cpp $(INC)/Pais.h
	echo Creando Pais.o
	g++ -g -c -I./$(INC) $(SRC)/Pais.cpp -o $(OBJ)/Pais.o -std=c++11

$(OBJ)/Paises.o: $(SRC)/Paises.cpp $(INC)/Paises.h
	echo Creando Paises.o
	g++ -g -c -I./$(INC) $(SRC)/Paises.cpp -o $(OBJ)/Paises.o -std=c++11

$(OBJ)/Punto.o: $(SRC)/Punto.cpp $(INC)/Punto.h
	echo Creando Punto.o
	g++ -g -c -I./$(INC) $(SRC)/Punto.cpp -o $(OBJ)/Punto.o -std=c++11

$(OBJ)/Ruta.o: $(SRC)/Ruta.cpp $(INC)/Ruta.h
	echo Creando Ruta.o
	g++ -g -c -I./$(INC) $(SRC)/Ruta.cpp -o $(OBJ)/Ruta.o -std=c++11

$(OBJ)/Almacen_Rutas.o: $(SRC)/Almacen_Rutas.cpp $(INC)/Almacen_Rutas.h
	echo Creando Almacen_Rutas.o
	g++ -g -c -I./$(INC) $(SRC)/Almacen_Rutas.cpp -o $(OBJ)/Almacen_Rutas.o -std=c++11

# ************ Generación de documentación ******************

documentacion:
	echo Creando la documentacion.
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean :
	echo Limpiando.
	-rm $(OBJ)/* $(BIN)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	echo Limpiando (la documentacion tambien se borrara).
	-rm doc/html/*
