/********************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 15 de noviembre de 2018
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include "racional.hpp"
#include "calculos.hpp"
using namespace std;


/*
 * Pre:  r.denominador ≠ 0
 * Post: Ha devuelto el racional representante canónico del conjunto de racionales
 *       equivalentes al valor de «r».
 */
Racional reducir(const Racional r) {
    int maximoComunDivisor = mcd(r.denominador, r.numerador);
    Racional irreducible;
    irreducible.numerador = r.numerador / maximoComunDivisor;
    irreducible.denominador = r.denominador / maximoComunDivisor;
    if (irreducible.denominador < 0) {
        irreducible.numerador = -irreducible.numerador;
        irreducible.denominador = -irreducible.denominador;
    }
    return irreducible;
}


/*
 * Pre:  denominador ≠ 0
 * Post: Ha devuelto un registro de tipo «Racional» cuyo valor es el representante
 *       canónico de numerador∕denominador.
 */
Racional definirRacional(const int numerador, const int denominador) {
    Racional r = {numerador, denominador};
    return reducir(r);
}


/*
 * Pre:  «a» y «b» son racionales representantes canónicos.
 * Post: Ha devuelto a + b.
 */
Racional sumar(const Racional a, const Racional b) {
    int denominadorComun = mcm(a.denominador, b.denominador);
    int numeradorSuma = a.numerador * (denominadorComun / a.denominador)
                        + b.numerador * (denominadorComun / b.denominador);
    return definirRacional(numeradorSuma, denominadorComun);
}


/*
 * Pre:  «a» y «b» son racionales representantes canónicos.
 * Post: Ha devuelto a − b.
 */
Racional restar(const Racional a, const Racional b) {
    return sumar(a, opuesto(b));
}


/*
 * Pre:  ---
 * Post: Ha devuelto −a.
 */
Racional opuesto(const Racional a) {
    Racional resultado = {-a.numerador, a.denominador};
    return resultado;
}


/*
 * Pre:  «a» y «b» son racionales representantes canónicos.
 * Post: Ha devuelto a x b.
 */
Racional multiplicar(const Racional a, const Racional b) {
    Racional producto = {a.numerador * b.numerador,
                         a.denominador * b.denominador};
    return reducir(producto);
}


/*
 * Pre:  «a» y «b» son racionales representantes canónicos y b ≠ 0.
 * Post: Ha devuelto a∕b.
 */
Racional dividir(const Racional a, const Racional b) {
    return multiplicar(a, inverso(b));
}


/*
 * Pre:  a ≠ 0
 * Post: Ha devuelto 1∕a
 */
Racional inverso(const Racional a) {
    Racional reciproco = {a.denominador, a.numerador};
    return reciproco;
}


/*
 * Pre:  ---
 * Post: Ha devuelto el valor real de «a»
 */
double valorReal(const Racional a) {
    return double(a.numerador) / double(a.denominador);
}


/*
 * Pre:  ---
 * Post: Ha escrito el racional «a» en la pantalla.
 */
void escribir(const Racional a) {
    cout << a.numerador << "/" << a.denominador;
}


/*
 * Pre:  ---
 * Post: Ha devuelto true si y solo si los racionales «a» y «b» son iguales.
 */
bool sonIguales(const Racional a, const Racional b) {
    return valorReal(a) == valorReal(b);
}
