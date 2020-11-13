/********************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 21 de noviembre de 2019
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/
#include <cstring>
#include "permiso.hpp"

/*
 * Cantidad máxima legal de puntos que puede tener un conductor.
 */
const int PUNTOS_MAXIMO_LEGAL = 15;

/*
 * Cantidad máxima legal de puntos que puede tener un conductor.
 */
const int PUNTOS_NOVEL = 8;

/*
 * Pre:  La cadena «nombre» no tiene más de MAX_LONG_NOMBRE caracteres.
 * Post: Ha inicializado el permiso «p» de forma que representa el permiso de
 *       conducir de una persona llamada «nombre» que acaba de obtenerlo.
 */
void inicializarComoNuevo(Permiso& p, const char nombre[]) {
    strcpy(p.nombreCompleto, nombre);
    p.antiguedadMeses = 0;
    p.movimientos[0] = PUNTOS_NOVEL;
    p.numMovimientos = 1;
}


/*
 * Pre:  ---
 * Post: Ha devuelto «true» si y solo si el titular del permiso «p» es un
 *       conductor novel.
 */
bool esNovel(const Permiso& p) {
    return p.antiguedadMeses < MESES_NOVEL;
}

/*
 * Pre:  ---
 * Post: Ha devuelto la cantidad de puntos asociados al permiso de conducir «p».
 */
int puntos(const Permiso& p) {
    int resultado = 0;
    for (int i = 0; i < p.numMovimientos; i++) {
        resultado += p.movimientos[i];
    }
    return resultado;
}


/*
 * Pre:  0 < sancion <= 6
 * Post: Ha registrado entre los movimientos de puntos del permiso «p» una
 *       sanción de «sancion» puntos (solo si había componentes libres en el
 *       vector de movimientos).
 */
void registrarSancion(Permiso& p, const int sancion) {
    if (p.numMovimientos < MAX_NUM_MOVIMIENTOS) {
        p.movimientos[p.numMovimientos] = -sancion;
        p.numMovimientos++;
    }
}


/*
 * Pre:  puntos > 0
 * Post: Ha registrado entre los movimientos de puntos del permiso «p» una
 *       bonificación de «bonificacion» puntos o inferior, en el caso de que se
 *       sobrepasara la cantidad legal máxima de 15 puntos (solo si había
 *       componentes libres en el vector de movimientos).
 */
void registrarBonificacion(Permiso& p, const int bonificacion) {
    if (p.numMovimientos < MAX_NUM_MOVIMIENTOS) {
        int puntosARegistrar = bonificacion;
        int puntosActuales = puntos(p);
        if (puntosActuales + bonificacion > PUNTOS_MAXIMO_LEGAL) {
            puntosARegistrar = PUNTOS_MAXIMO_LEGAL - puntosActuales;
        }
        p.movimientos[p.numMovimientos] = puntosARegistrar;
        p.numMovimientos++;
    }
}
