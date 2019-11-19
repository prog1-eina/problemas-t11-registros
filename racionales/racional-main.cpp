/********************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 16 de noviembre de 2016
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include "racional.h"

/*
 * Pre:  ---
 * Post: Ha comprobado el funcionamiento del módulo «racional», escribiendo en la
 *       pantalla el racional 9/8 resultante de realizar la operación
 *       [(2/4 + 1/6) - 8/3] * [6/8 ÷ 4/(-3)].
 */
int main() {
    Racional p1 = definirRacional(2, 4);  //  2/4
    Racional p2 = definirRacional(1, 6);  //  1/6
    Racional p3 = definirRacional(8, 3);  //  8/3
    Racional p4 = definirRacional(6, 8);  //  6/8
    Racional p5 = definirRacional(4, -3); //  4/(-3)

    Racional q1 = sumar(p1, p2);        //  2/4 + 1/6
    Racional q2 = restar(q1, p3);       //  (2/4 + 1/6) - 8/3
    Racional q3 = dividir(p4, p5);      //  6/8 ÷ 4/(-3)
    Racional r = multiplicar(q2, q3);   //  [(2/4 + 1/6) - 8/3] * [6/8 ÷ 4/(-3)]
    escribir(r);

    return 0;
}
