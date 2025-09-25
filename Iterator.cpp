/*****Datos administrativos************************
 * Nombre del archivo: Iterator.cpp
 * Tipo de archivo: Implementación de clase
 * Proyecto: Libreria String
 * Autores: Sebastian Sanchez, Dominick Viales, Trever Lopez
 * Universidad: TEC
 *****Descripción**********************************
 * Implementación de los métodos de la clase Iterator.
 **************************************************/

#include "Iterator.hpp"

/*****Nombre***************************************
 * Iterator
 *****Descripción**********************************
 * Constructor que inicializa el puntero interno.
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * char *pPtr: puntero al carácter inicial.
 **************************************************/
Iterator::Iterator(char *pPtr) {
    apPuntero = pPtr;
}

/*****Nombre***************************************
 * operator*
 *****Descripción**********************************
 * Permite acceder al carácter actual apuntado por el iterador.
 *****Retorno**************************************
 * char&: referencia al carácter actual.
 *****Entradas*************************************
 * Ninguna.
 **************************************************/
char &Iterator::operator*() {
    return *apPuntero;
}

/*****Nombre***************************************
 * operator++
 *****Descripción**********************************
 * Avanza el iterador al siguiente carácter.
 *****Retorno**************************************
 * Iterator&: referencia al propio iterador.
 *****Entradas*************************************
 * Ninguna.
 **************************************************/
Iterator &Iterator::operator++() {
    ++apPuntero;
    return *this;
}

/*****Nombre***************************************
 * operator!=
 *****Descripción**********************************
 * Compara si dos iteradores son diferentes.
 *****Retorno**************************************
 * bool: true si son diferentes, false si son iguales.
 *****Entradas*************************************
 * const Iterator &otra: referencia al otro iterador.
 **************************************************/
bool Iterator::operator!=(const Iterator &otra) {
    return apPuntero != otra.apPuntero;
}