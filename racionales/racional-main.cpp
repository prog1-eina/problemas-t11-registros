/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 13 de noviembre de 2020
 * Resumen: Soluciones a los problemas de Programación 1 planteados en la clase
 *          de problemas de registros.
 * Nota: El código de este programa está repartido en varios módulos. 
 *       Para compilarlo, hay que ejecutar el comando
 *           make racionales
 *       o, en Windows,
 *           mingw32-make racionales
 *       o ejecutar la tarea "Compilar programa «racionales»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           ./racionales
 *       o, en Windows,
 *           .\racionales.exe
 *       o ejecutar la tarea "Ejecutar programa «racionales»" de VSC.
 *       
 *       Este programa necesita del módulo `calculos` de la práctica 3 para
 *       reutilizar las funciones mcd y mcm. El fichero `Makefile` ha sido 
 *       escrito considerando que dicho módulo se encuentra en un directorio 
 *       denominado «calculadora/src» dentro de un directorio «practica3» 
 *       ubicado en la misma carpeta que el directorio correspondiente a estas
 *       soluciones («problemas-t11-registros»). La ruta a este módulo puede
 *       modificarse en el propio fichero `Makefile` si fuese preciso.
\******************************************************************************/

#include <iostream>
#include "racional.hpp"

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
