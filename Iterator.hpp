/*****Datos administrativos************************
 * Nombre del archivo: Iterator.hpp
 * Tipo de archivo: Encabezado de clase
 * Proyecto: Libreria String
 * Autores: Sebastian Sanchez, Dominick Viales, Trever Lopez
 * Universidad: TEC
 *****Descripción**********************************
 * Declaración de la clase Iterator para recorrer cadenas.
 **************************************************/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/*****Nombre***************************************
 * Iterator
 *****Descripción**********************************
 * Clase para recorrer los caracteres de una cadena.
 *****Atributos************************************
 * char *apPuntero: Puntero actual dentro de la cadena.
 *****Métodos**************************************
 * Iterator(char *pPtr);
 * char &operator*();
 * Iterator &operator++();
 * bool operator!=(const Iterator &otra);
 **************************************************/
class Iterator {
private:
    char *apPuntero;
public:
    /*****Nombre***************************************
     * Iterator
     *****Descripción**********************************
     * Constructor que inicializa el puntero interno.
     *****Retorno**************************************
     * 
     *****Entradas*************************************
     * char *pPtr: puntero al carácter inicial.
     **************************************************/
    Iterator(char *pPtr);

    /*****Nombre***************************************
     * operator*
     *****Descripción**********************************
     * Permite acceder al carácter actual apuntado por el iterador.
     *****Retorno**************************************
     * char&: referencia al carácter actual.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    char &operator*();

    /*****Nombre***************************************
     * operator++
     *****Descripción**********************************
     * Avanza el iterador al siguiente carácter.
     *****Retorno**************************************
     * Iterator&: referencia al propio iterador.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    Iterator &operator++();

    /*****Nombre***************************************
     * operator!=
     *****Descripción**********************************
     * Compara si dos iteradores son diferentes.
     *****Retorno**************************************
     * bool: true si son diferentes, false si son iguales.
     *****Entradas*************************************
     * const Iterator &otra: referencia al otro iterador.
     **************************************************/
    bool operator!=(const Iterator &otra);
};

#endif