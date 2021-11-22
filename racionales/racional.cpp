/********************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 22 de noviembre de 2021
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include "racional.hpp"
#include <cstdlib>
#include <iostream>
#include "calculos.hpp"
using namespace std;

/*
 * Pre:  ---
 * Post: Devuelve 1 si «n» es mayor o igual que 0 y -1 si «n» es estrictamente
 *       negativo. 
 */
int signo(int n) {
    if (n >= 0) {
        return 1;
    }
    else {
        return -1;
    }
}

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
    int signoRacional = signo(numerador) * signo(denominador);
    unsigned maximoComunDivisor = mcd(denominador, numerador);
    int numeradorIrreducible = abs(numerador) / maximoComunDivisor;
    unsigned denominadorIrreducible = abs(denominador) / maximoComunDivisor;
    return {signoRacional * numeradorIrreducible, denominadorIrreducible};
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
