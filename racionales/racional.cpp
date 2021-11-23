/********************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 22 de noviembre de 2021
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include "racional.hpp"
#include <iostream>
#include "calculos.hpp"
using namespace std;


/*
 * Pre:  denominador ≠ 0
 * Post: Ha devuelto un registro de tipo «Racional» cuyo valor es el 
 *       representante canónico de numerador∕denominador.
 */
Racional definirRacional(const int numerador, const int denominador) {
    // Hay que ser extremadamente cuidadosos con las operaciones de
    // multiplicación y división entre enteros con y sin signo, puesto que las
    // reglas de conversión implicita de C++ convierten un entero con signo en
    // entero sin signo cuando se mezclan.
    // Por eso se han declarado los campos del tipo registro «Racional» como
    // «int» en ambos casos y por eso se declara la variable
    // «maximoComunDivisor» de esta función también como «int».
    int maximoComunDivisor = mcd(denominador, numerador);
    Racional resultado = {numerador / maximoComunDivisor,
                          denominador / maximoComunDivisor};
    if (resultado.denominador < 0) {
        resultado.numerador = -resultado.numerador;
        resultado.denominador = -resultado.denominador;
    }
    return resultado;
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
    return definirRacional(a.numerador * b.numerador,
                           a.denominador * b.denominador);
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
    if (a.numerador > 0) {
        return {int(a.denominador), unsigned(a.numerador)};
    }
    else {
        return {int(-a.denominador), unsigned(-a.numerador)};
    }
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
