/**************************************************
 * Nombre del archivo: heap.hpp
 * Tipo de archivo   : Encabezado (.hpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : Montículo mínimo (Nodo*).
 **************************************************/
#ifndef HEAP_HPP
#define HEAP_HPP

#include "nodo.hpp"

/**************************************************
 * Nombre      : class Heap
 * Descripción : Heap mínimo por frecuencia para Nodo*.
 * Atributos   :
 *  - Nodo *apDatos[HEAP_MAX_NODOS] : almacenamiento
 *  - int  aCantidad                : número de usados
 **************************************************/
#define HEAP_MAX_NODOS 512  // 256 hojas + 255 internos + margen

class Heap {
private:
    Nodo *apDatos[HEAP_MAX_NODOS];
    int aCantidad;

    /**************************************************
     * Nombre      : Subir_
     * Descripción : Corrige invariante subiendo el nodo.
     * Entradas    : int indice
     * Retorno     : void
     **************************************************/
    void Subir_(int indice);

    /**************************************************
     * Nombre      : Bajar_
     * Descripción : Corrige invariante bajando el nodo.
     * Entradas    : int indice
     * Retorno     : void
     **************************************************/
    void Bajar_(int indice);

public:
    /**************************************************
     * Nombre      : Heap
     * Descripción : Inicializa heap vacío.
     * Entradas    : N/A
     * Retorno     : N/A
     **************************************************/
    Heap();

    /**************************************************
     * Nombre      : Insertar
     * Descripción : Inserta elemento (si hay espacio).
     * Entradas    : Nodo *p_nodo
     * Retorno     : void
     **************************************************/
    void Insertar(Nodo *p_nodo);

    /**************************************************
     * Nombre      : ExtraerMin
     * Descripción : Remueve y retorna el mínimo.
     * Entradas    : N/A
     * Retorno     : Nodo* (o 0 si vacío)
     **************************************************/
    Nodo *ExtraerMin();

    /**************************************************
     * Nombre      : Tamano
     * Descripción : Cantidad de elementos en el heap.
     * Entradas    : N/A
     * Retorno     : int
     **************************************************/
    int Tamano() const;
};

#endif  // HEAP_HPP
