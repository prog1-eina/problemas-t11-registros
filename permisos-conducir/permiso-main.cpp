/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 13 de noviembre de 2020
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
 *          Programa de prueba de las funciones del módulo «permiso».
 * Nota: El código de esta versión está repartido en varios módulos. Para
 *       compilarlo, hay que ejecutar el comando
 *           make permisos
 *       o, en Windows,
 *           mingw32-make permisos
 *       o ejecutar la tarea "Compilar programa «permisos»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           ./permisos
 *       o, en Windows,
 *           .\permisos.exe
 *       o ejecutar la tarea "Ejecutar programa «permisos»" de VSC.
\******************************************************************************/

#include <iostream>
#include "permiso.hpp"
using namespace std;


/*
 * Pre:  ---
 * Post: Ha escrito el nombre del titular de «permiso», sus puntos y si es novel
 *       o no.
 */
void mostrar(const Permiso permiso) {
    cout << permiso.nombreCompleto << " tiene " << puntos(permiso)
         << " puntos y ";
    if (!esNovel(permiso)) {
        cout << "ya no ";
    }
    cout << "es novel." << endl;
}

/*
 * Pre:  ---
 * Post: Ha utilizado las funciones definidas en el módulo «permiso».
 */
int main() {
    cout << "Se saca el carnet: ";
    Permiso permiso;
    inicializarComoNuevo(permiso, "Juan González González");
    mostrar(permiso);

    cout << "Han pasado dos años: ";
    permiso.antiguedadMeses += 24;
    registrarBonificacion(permiso, 4);
    mostrar(permiso);

    cout << "Han pasado tres años más: ";
    permiso.antiguedadMeses += 36;
    registrarBonificacion(permiso, 2);
    mostrar(permiso);

    cout << "Han pasado otros tres años más: ";
    permiso.antiguedadMeses += 36;
    registrarBonificacion(permiso, 2);
    mostrar(permiso);

    cout << "Le han sancionado: ";
    permiso.antiguedadMeses += 7;
    registrarSancion(permiso, 6);
    mostrar(permiso);

    return 0;
}
