/**************************************************
 * Nombre del archivo: nodo.cpp
 * Tipo de archivo   : Implementación (.cpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : Implementación Nodo.
 **************************************************/
#include "nodo.hpp"

Nodo::Nodo(char c, int f) {
    aCaracter = c;
    aFrecuencia = f;
    apIzquierda = 0;
    apDerecha = 0;
} // fin de ctor hoja

Nodo::Nodo(int f, Nodo *p_izq, Nodo *p_der) {
    aCaracter = '\0';
    aFrecuencia = f;
    apIzquierda = p_izq;
    apDerecha = p_der;
} // fin de ctor interno con frecuencia

Nodo::Nodo(Nodo *p_izq, Nodo *p_der) {
    aCaracter = '\0';
    apIzquierda = p_izq;
    apDerecha = p_der;

    int f_izq = (p_izq ? p_izq->aFrecuencia : 0);
    int f_der = (p_der ? p_der->aFrecuencia : 0);
    aFrecuencia = f_izq + f_der;
} // fin de ctor interno por hijos

bool Nodo::EsHoja() const {
    return (apIzquierda == 0) && (apDerecha == 0);
} // fin de EsHoja

char Nodo::ObtenerCaracter() const {
    return aCaracter;
} // fin de ObtenerCaracter

int Nodo::ObtenerFrecuencia() const {
    return aFrecuencia;
} // fin de ObtenerFrecuencia

Nodo *Nodo::ObtenerIzquierda() const {
    return apIzquierda;
} // fin de ObtenerIzquierda

Nodo *Nodo::ObtenerDerecha() const {
    return apDerecha;
} // fin de ObtenerDerecha

void Nodo::AsignarFrecuencia(int f) {
    aFrecuencia = f;
} // fin de AsignarFrecuencia
