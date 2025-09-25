/**************************************************
 * Nombre del archivo: heap.cpp
 * Tipo de archivo   : Implementación (.cpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : Implementación Heap mínimo.
 **************************************************/
#include "heap.hpp"

Heap::Heap() {
    aCantidad = 0;
} // fin de ctor Heap

void Heap::Insertar(Nodo *p_nodo) {
    if (p_nodo == 0) {
        return;
    }
    if (aCantidad >= HEAP_MAX_NODOS) {
        return; // sin crecimiento dinámico por estándar
    }
    apDatos[aCantidad] = p_nodo;
    Subir_(aCantidad);
    aCantidad = aCantidad + 1;
} // fin de Insertar

Nodo *Heap::ExtraerMin() {
    if (aCantidad == 0) {
        return 0;
    }
    Nodo *p_min = apDatos[0];
    aCantidad = aCantidad - 1;
    apDatos[0] = apDatos[aCantidad];
    Bajar_(0);
    return p_min;
} // fin de ExtraerMin

int Heap::Tamano() const {
    return aCantidad;
} // fin de Tamano

void Heap::Subir_(int indice) {
    int i = indice;
    while (i > 0) {
        int padre = (i - 1) / 2;
        if (apDatos[i]->ObtenerFrecuencia() < apDatos[padre]->ObtenerFrecuencia()) {
            Nodo *p_tmp = apDatos[i];
            apDatos[i] = apDatos[padre];
            apDatos[padre] = p_tmp;
            i = padre;
        } else {
            break;
        }
    }
} // fin de Subir_

void Heap::Bajar_(int indice) {
    int i = indice;
    while (1) {
        int izq = 2 * i + 1;
        int der = 2 * i + 2;
        int menor = i;

        if (izq < aCantidad &&
            apDatos[izq]->ObtenerFrecuencia() < apDatos[menor]->ObtenerFrecuencia()) {
            menor = izq;
        }
        if (der < aCantidad &&
            apDatos[der]->ObtenerFrecuencia() < apDatos[menor]->ObtenerFrecuencia()) {
            menor = der;
        }
        if (menor != i) {
            Nodo *p_tmp = apDatos[i];
            apDatos[i] = apDatos[menor];
            apDatos[menor] = p_tmp;
            i = menor;
        } else {
            break;
        }
    }
} // fin de Bajar_
