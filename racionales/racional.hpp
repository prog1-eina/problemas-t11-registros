/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 13 de noviembre de 2020
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
\******************************************************************************/


/*
 * Representación de números racionales canónicos.
 */
struct Racional {
    int numerador;
    unsigned denominador;
};


/*
 * Pre:  denominador ≠ 0
 * Post: Ha devuelto un registro de tipo «Racional» cuyo valor es el 
 *       representante canónico de numerador∕denominador.
 */
Racional definirRacional(const int numerador, const int denominador);

/*
 * Pre:  «a» y «b» son racionales representantes canónicos.
 * Post: Ha devuelto a + b.
 */
Racional sumar(const Racional a, const Racional b);


/*
 * Pre:  «a» y «b» son racionales representantes canónicos.
 * Post: Ha devuelto a − b.
 */
Racional restar(const Racional a, const Racional b);


/*
 * Pre:  ---
 * Post: Ha devuelto −a.
 */
Racional opuesto(const Racional a);


/*
 * Pre:  «a» y «b» son racionales representantes canónicos.
 * Post: Ha devuelto a x b.
 */
Racional multiplicar(const Racional a, const Racional b);


/*
 * Pre:  «a» y «b» son racionales representantes canónicos y b ≠ 0.
 * Post: Ha devuelto a∕b.
 */
Racional dividir(const Racional a, const Racional b);


/*
 * Pre:  a ≠ 0
 * Post: Ha devuelto 1∕a
 */
Racional inverso(const Racional a);


/*
 * Pre:  ---
 * Post: Ha devuelto el valor real de «a»
 */
double valorReal(const Racional a);


/*
 * Pre:  ---
 * Post: Ha escrito el racional «a» en la pantalla.
 */
void escribir(const Racional a);


/*
 * Pre:  ---
 * Post: Ha devuelto true si y solo si los racionales «a» y «b» son iguales.
 */
bool sonIguales(const Racional a, const Racional b);
