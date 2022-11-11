/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 24 de noviembre de 2021
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
\******************************************************************************/


/*
 * Representación de números racionales.
 */
struct Racional {
    int numerador;
    int denominador;
};


/*
 * Pre:  denominador ≠ 0
 * Post: Devuelve un registro de tipo «Racional» cuyo valor es el 
 *       representante canónico de numerador∕denominador.
 */
Racional definirRacional(const int numerador, const int denominador);

/*
 * Pre:  «a» y «b» son racionales válidos (a.denominador ≠ 0 y b.denominador ≠ 0).
 * Post: Devuelve el representante canónico de a + b.
 */
Racional sumar(const Racional a, const Racional b);

/*
 * Pre:  «a» y «b» son racionales válidos (a.denominador ≠ 0 y b.denominador ≠ 0).
 * Post: Devuelve el representante canónico de a − b.
 */
Racional restar(const Racional a, const Racional b);

/*
 * Pre:  «a» es un racional válido (a.denominador ≠ 0).
 * Post: Devuelve el representante canónico de −a.
 */
Racional opuesto(const Racional a);

/*
 * Pre:  «a» y «b» son racionales válidos (a.denominador ≠ 0 y b.denominador ≠ 0).
 * Post: Devuelve el representante canónico de a x b.
 */
Racional multiplicar(const Racional a, const Racional b);

/*
 * Pre:  «a» y «b» son racionales válidos (a.denominador ≠ 0 y
         b.denominador ≠ 0) y b ≠ 0.
 * Post: Devuelve el representante canónico de a∕b.
 */
Racional dividir(const Racional a, const Racional b);

/*
 * Pre:  «a» es un racional válido (a.denominador ≠ 0) y a ≠ 0
 * Post: Devuelve el representante canónico de 1∕a
 */
Racional inverso(const Racional a);

/*
 * Pre:  «a» es un racional válido (a.denominador ≠ 0).
 * Post: Devuelve el valor real de «a»
 */
double valorReal(const Racional a);

/*
 * Pre:  «a» es un racional válido (a.denominador ≠ 0).
 * Post: Escribe el racional «a» en la pantalla.
 */
void escribir(const Racional a);

/*
 * Pre:  «a» y «b» son racionales válidos (a.denominador ≠ 0 y b.denominador ≠ 0).
 * Post: Devuelve true si y solo si los racionales «a» y «b» son iguales.
 */
bool sonIguales(const Racional a, const Racional b);