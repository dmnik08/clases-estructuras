/**************************************************
 * Nombre del archivo: nodo.hpp
 * Tipo de archivo   : Encabezado (.hpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : Nodo del árbol de Huffman.
 **************************************************/
#ifndef NODO_HPP
#define NODO_HPP

/**************************************************
 * Nombre      : class Nodo
 * Descripción : Representa nodo hoja o interno del
 *               árbol de Huffman.
 * Atributos   :
 *  - char aCaracter        : '\0' si interno
 *  - int  aFrecuencia      : frecuencia acumulada
 *  - Nodo *apIzquierda     : hijo izquierdo
 *  - Nodo *apDerecha       : hijo derecho
 **************************************************/
class Nodo {
private:
    char aCaracter;
    int aFrecuencia;
    Nodo *apIzquierda;
    Nodo *apDerecha;

public:
    /**************************************************
     * Nombre      : Nodo (hoja)
     * Descripción : Crea hoja con carácter y frecuencia.
     * Entradas    : char c, int f
     * Retorno     : N/A
     **************************************************/
    Nodo(char c, int f);

    /**************************************************
     * Nombre      : Nodo (interno con frecuencia)
     * Descripción : Interno con frecuencia explícita.
     * Entradas    : int f, Nodo *p_izq, Nodo *p_der
     * Retorno     : N/A
     **************************************************/
    Nodo(int f, Nodo *p_izq, Nodo *p_der);

    /**************************************************
     * Nombre      : Nodo (interno por hijos)
     * Descripción : Interno cuya frecuencia es la suma
     *               de las frecuencias de sus hijos.
     * Entradas    : Nodo *p_izq, Nodo *p_der
     * Retorno     : N/A
     **************************************************/
    Nodo(Nodo *p_izq, Nodo *p_der);

    /**************************************************
     * Nombre      : EsHoja
     * Descripción : Indica si no tiene hijos.
     * Entradas    : N/A
     * Retorno     : bool
     **************************************************/
    bool EsHoja() const;

    // Accesores
    char ObtenerCaracter() const;
    int  ObtenerFrecuencia() const;
    Nodo *ObtenerIzquierda() const;
    Nodo *ObtenerDerecha() const;

    void AsignarFrecuencia(int f);
};

#endif  // NODO_HPP
