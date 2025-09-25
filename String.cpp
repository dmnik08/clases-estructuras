/**************************************************
 * Nombre del archivo: string.cpp
 * Tipo de archivo   : Implementación (.cpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : Implementación de String.
 **************************************************/
#include "String.hpp"

int String::SLen_(const char *p_cadena) const {
    if (p_cadena == 0) return 0;
    int n = 0;
    while (p_cadena[n] != '\0') {
        n = n + 1;
    }
    return n;
} // fin de SLen_

void String::CopiarDesde_(const char *p_cadena) {
    int n = SLen_(p_cadena);
    apDatos = new char[n + 1];
    int i = 0;
    while (i < n) {
        apDatos[i] = p_cadena[i];
        i = i + 1;
    }
    apDatos[n] = '\0';
} // fin de CopiarDesde_

String::String() : apDatos(0) {
    apDatos = new char[1];
    apDatos[0] = '\0';
} // fin de ctor por defecto

String::String(const char *p_cadena) : apDatos(0) {
    CopiarDesde_(p_cadena == 0 ? "" : p_cadena);
} // fin de ctor C-string

String::String(const String &otra) : apDatos(0) {
    CopiarDesde_(otra.apDatos);
} // fin de ctor copia

String::~String() {
    delete[] apDatos;
} // fin de destructor

String &String::operator=(const String &otra) {
    if (this == &otra) return *this;
    delete[] apDatos;
    CopiarDesde_(otra.apDatos);
    return *this;
} // fin de operator=

int String::Len() const {
    return SLen_(apDatos);
} // fin de Len

int String::Length() const {
    return Len();
} // fin de Length

const char *String::CStr() const {
    return apDatos;
} // fin de CStr

char &String::operator[](int indice) {
    int n = Len();
    if (n == 0) return apDatos[0];
    if (indice < 0) indice = n + indice;
    if (indice < 0) indice = 0;
    if (indice >= n) indice = n - 1;
    return apDatos[indice];
} // fin de operator[] no-const

char String::operator[](int indice) const {
    int n = Len();
    if (n == 0) return '\0';
    if (indice < 0) indice = n + indice;
    if (indice < 0) indice = 0;
    if (indice >= n) indice = n - 1;
    return apDatos[indice];
} // fin de operator[] const

String String::operator+(const char *p_derecha) const {
    if (p_derecha == 0) p_derecha = "";
    int n1 = Len();
    int n2 = SLen_(p_derecha);
    char *p_buf = new char[n1 + n2 + 1];

    int i = 0;
    while (i < n1) {
        p_buf[i] = apDatos[i];
        i = i + 1;
    }
    int j = 0;
    while (j < n2) {
        p_buf[n1 + j] = p_derecha[j];
        j = j + 1;
    }
    p_buf[n1 + n2] = '\0';

    String res(p_buf);
    delete[] p_buf;
    return res;
} // fin de operator+(const char*)

String String::operator+(const String &derecha) const {
    return (*this) + derecha.CStr();
} // fin de operator+(const String&)

String &String::operator+=(char c) {
    char tmp[2];
    tmp[0] = c;
    tmp[1] = '\0';
    return (*this += tmp);
} // fin de operator+=(char)

String &String::operator+=(const char *p_derecha) {
    if (p_derecha == 0) return *this;
    int n1 = Len();
    int n2 = SLen_(p_derecha);
    char *p_buf = new char[n1 + n2 + 1];

    int i = 0;
    while (i < n1) {
        p_buf[i] = apDatos[i];
        i = i + 1;
    }
    int j = 0;
    while (j < n2) {
        p_buf[n1 + j] = p_derecha[j];
        j = j + 1;
    }
    p_buf[n1 + n2] = '\0';

    delete[] apDatos;
    apDatos = p_buf;
    return *this;
} // fin de operator+=(const char*)

String &String::operator+=(const String &derecha) {
    return (*this += derecha.CStr());
} // fin de operator+=(const String&)
