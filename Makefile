################################################################################
## Fichero «Makefile» para el programa «permisos» y el programa «racionales»
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS

# Variable que define el directorio donde está el código fuente del proyecto 
# «permisos»
SOURCE_PERMISOS_DIR = permisos-conducir

# Variable que define el directorio donde está el código fuente del proyecto
#«racionales»
SOURCE_RACIONALES_DIR = racionales

# Variable que define el directorio donde los profesores tenemos el código
# fuente de la biblioteca «calculos» de la práctica 3 con la solución
SOURCE_CALCULOS_PROFS_DIR = ../../codigo-c++-privado/practica3/src/calculadora

# Variable que define el directorio donde deberías tener el código fuente de la 
# biblioteca «calculos» de la práctica 3.
# ESTRUCTURA TU CÓDIGO PARA QUE EL DIRECTORIO problemas-t11-registros SE
# ENCUENTRE AL MISMO NIVEL QUE EL DIRECTORIO practica3 O MODIFICA EL VALOR DE
# ESTA VARIABLE CON LA RUTA CORRESPONDIENTE AL MÓDULO «calculos»
SOURCE_CALCULOS_DIR = ../practica3/src/calculadora

# Variable que define el directorio en el que crear los ficheros intermedios 
# de compilación
BUILD_DIR = build

# Variable que define el directorio en el que crear los ficheros ejecutables 
BIN_DIR = bin

# Variable preestablecida de «make» que en la que se pueden definir los 
# directorios en los que pueden hallarse los ficheros de codigo fuente a 
# compilar, con el objetivo de evitar tenerlos que poner de forma explícita
# en las reglas. 
# En este caso, en el directorio de codigo fuente, en el
# de codigo de pruebas y el de la biblioteca para mostrar resultados de preubas
VPATH = $(SOURCE_PERMISOS_DIR) $(SOURCE_RACIONALES_DIR) \
        $(SOURCE_CALCULOS_PROFS_DIR) $(SOURCE_CALCULOS_DIR)
        


## COMPILADOR Y OPCIONES DE COMPILACIÓN:

# Variable preestablecida de «make» que en la que se puede definir el nombre del
# compilador. Esto permite que «make» genere recetas y reglas por defecto. 
CXX = g++

# Variable preestablecida de «make» que en la que se puede definir las opciones
# con las que debe invocarse al compilador.
# En este caso, son las siguientes:
#    -g:   indica al compilador que incluya información de depuración al generar
#          los ejecutables o los ficheros intermedios de compilación. Esta 
#          información es necesaria si luego se quiere utilizar el depurador.
#    -Wall:  indica al compilador que informe de todos los 
#          _warnings_ (advertencias o usos del lenguaje que, pese a ser
#          sintácticamente correctos, plantean un problema que casi siempre
#          resulta ser un error.
#    -Wextra:   indica al compilador que informe de algunos tipos de 
#          advertencias adicionales.
#    -I _dir_:  indica al compilador que, cuando encuentre una cláusula
#          de inclusión de un fichero, si este no se encuentra en el directorio
#          actual, busque también en el directorio _dir_.
CXXFLAGS = -g -Wall -Wextra -I$(SOURCE_CALCULOS_PROFS_DIR) -I$(SOURCE_CALCULOS_DIR) 


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):

# Variable para definir la lista
# de ficheros objeto de los que depende el programa «permisos».
OBJECTS_PERMISOS =  $(addprefix $(BUILD_DIR)/, permiso.o permiso-main.o)

# Variable para definir la lista
# de ficheros objeto de los que depende el programa «racionales».
OBJECTS_RACIONALES = $(addprefix $(BUILD_DIR)/, racional.o racional-main.o \
                                                calculos.o)

################################################################################
## Reglas del fichero «Makefile»

permisos: $(OBJECTS_PERMISOS) | $(BIN_DIR)
	$(CXX) -g $(OBJECTS_PERMISOS) -o $(BIN_DIR)/$@ 

racionales: $(OBJECTS_RACIONALES) | $(BIN_DIR)
	$(CXX) -g $(OBJECTS_RACIONALES) -o $(BIN_DIR)/$@ 

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(OBJECTS_PERMISOS): permiso.hpp 
$(OBJECTS_RACIONALES): racional.hpp calculos.hpp 

# Reglas con objetivo pero sin prerrequisitos, que establecen como crear 
# los directorios bin y build.
$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
else
	rm -f $(OBJECTS) $(TESTING_OBJECTS) $(BIN_DIR)/*
endif
