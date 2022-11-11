/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 11 de noviembre de 2022
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
\******************************************************************************/

#include <string>
using namespace std;

/*
 * Estimación del máximo número de movimientos del historial de puntos
 */
const unsigned MAX_NUM_MOVIMIENTOS = 200;

/*
 * Tiempo en meses durante el que a un conductor se le considera novel.
 */
const unsigned MESES_NOVEL = 12;


/*
 * Los registros de tipo Permiso representan (de forma muy parcial)
 * permisos de conducir por puntos. Únicamente tenemos en cuenta el nombre del
 * conductor, su antigüedad en meses y el historial de puntos (asignación
 * inicial, bonificaciones y sanciones).
 */
struct Permiso {
    string nombreCompleto;
    unsigned antiguedadMeses;
    int movimientos[MAX_NUM_MOVIMIENTOS];
    unsigned numMovimientos;
    // Aquí iría la definición de campos para otra información como
    // DNI, fecha de expedición, tipo de carnet, ...
};


/*
 * Pre:  ---
 * Post: Inicializa el permiso «p» de forma que representa el permiso de
 *       conducir de una persona llamada «nombre» que acaba de obtenerlo, es
 *       decir, el permiso de esa persona irá a su nombre, tendrá una antigüedad
 *       de 0 meses y un único movimiento en su historial correspondiente a la
 *       asignación inicial de 8 puntos.
 */
void inicializarComoNuevo(Permiso& p, const string nombre);

/*
 * Pre:  ---
 * Post: Devuelve «true» si y solo si el titular del permiso «p» es un
 *       conductor novel.
 */
bool esNovel(const Permiso& p);

/*
 * Pre:  ---
 * Post: Devuelve la cantidad de puntos asociados al permiso de conducir «p».
 */
int puntos(const Permiso& p);


/*
 * Pre:  0 < sancion ≤ 6
 * Post: Registra en el historial de puntos del permiso «p» una sanción de «sancion»
 *       puntos.
 */
void registrarSancion(Permiso& p, const unsigned sancion);


/*
 * Pre:  bonificacion > 0
 * Post: Registra en el historial de puntos del permiso «p» una bonificación de
 *       «bonificacion» puntos, sin sobrepasar la cantidad legal máxima de 15 puntos.
 */
void registrarBonificacion(Permiso& p, const unsigned bonificacion);
