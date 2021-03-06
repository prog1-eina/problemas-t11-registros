﻿/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 13 de noviembre de 2020
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
\******************************************************************************/

#include <string>
using namespace std;

/*
 * Estimación del máximo número de movimientos del historial de puntos
 */
const unsigned int MAX_NUM_MOVIMIENTOS = 200;

/*
 * Tiempo en meses durante el que a un conductor se le considera novel.
 */
const unsigned int MESES_NOVEL = 12;


/*
 * Los registros de tipo Permiso representan (de forma muy parcial)
 * permisos de conducir por puntos. Únicamente tenemos en cuenta el nombre del
 * conductor, su antigüedad en meses y el historial de puntos (asignación
 * inicial, bonificaciones y sanciones).
 */
struct Permiso {
    string nombreCompleto;
    unsigned int antiguedadMeses;
    int movimientos[MAX_NUM_MOVIMIENTOS];
    unsigned int numMovimientos;
    // Aquí iría la definición de campos para otra información como
    // DNI, fecha de expedición, tipo de carnet, ...
};


/*
 * Pre:  ---
 * Post: Ha inicializado el permiso «p» de forma que representa el permiso de
 *       conducir de una persona llamada «nombre» que acaba de obtenerlo.
 */
void inicializarComoNuevo(Permiso& p, const string nombre);

/*
 * Pre:  ---
 * Post: Ha devuelto «true» si y solo si el titular del permiso «p» es un
 *       conductor novel.
 */
bool esNovel(const Permiso& p);

/*
 * Pre:  ---
 * Post: Ha devuelto la cantidad de puntos asociados al permiso de conducir «p».
 */
int puntos(const Permiso& p);


/*
 * Pre:  0 < sancion <= 6
 * Post: Ha registrado entre los movimientos de puntos del permiso «p» una
 *       sanción de «sancion» puntos.
 */
void registrarSancion(Permiso& p, const unsigned int sancion);


/*
 * Pre:  puntos > 0
 * Post: Ha registrado entre los movimientos de puntos del permiso «p» una
 *       bonificación de «bonificacion» puntos o inferior, en el caso de que se
 *       sobrepasara la cantidad legal máxima de 15 puntos.
 */
void registrarBonificacion(Permiso& p, const unsigned int bonificacion);
