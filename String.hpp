/**************************************************
 * Nombre del archivo: string.hpp
 * Tipo de archivo   : Encabezado (.hpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : Declaración de clase String mínima
 *                     (sin STL), con operaciones básicas
 *                     requeridas por el proyecto.
 **************************************************/
#ifndef STRING_HPP
#define STRING_HPP

/**************************************************
 * Nombre      : class String
 * Descripción : Cadena propia nulo-terminada con
 *               construcción, copia, concatenación,
 *               acceso por índice y utilidades.
 * Atributos   :
 *  - char *apDatos : buffer nulo-terminado (propietario)
 **************************************************/
class String {
private:
    char *apDatos;

    /**************************************************
     * Nombre      : SLen_
     * Descripción : Calcula longitud de C-string segura.
     * Entradas    : const char *p_cadena
     * Retorno     : int (longitud)
     **************************************************/
    int SLen_(const char *p_cadena) const;

    /**************************************************
     * Nombre      : CopiarDesde_
     * Descripción : Reserva y copia p_cadena en apDatos.
     * Entradas    : const char *p_cadena
     * Retorno     : void
     **************************************************/
    void CopiarDesde_(const char *p_cadena);

public:
    /**************************************************
     * Nombre      : String (ctor por defecto)
     * Descripción : Inicializa cadena vacía.
     * Entradas    : N/A
     * Retorno     : N/A
     **************************************************/
    String();

    /**************************************************
     * Nombre      : String (ctor C-string)
     * Descripción : Construye a partir de const char*.
     * Entradas    : const char *p_cadena
     * Retorno     : N/A
     **************************************************/
    String(const char *p_cadena);

    /**************************************************
     * Nombre      : String (ctor copia)
     * Descripción : Copia segura.
     * Entradas    : const String &otra
     * Retorno     : N/A
     **************************************************/
    String(const String &otra);

    /**************************************************
     * Nombre      : ~String
     * Descripción : Libera buffer.
     * Entradas    : N/A
     * Retorno     : N/A
     **************************************************/
    ~String();

    /**************************************************
     * Nombre      : operator=
     * Descripción : Asignación por copia.
     * Entradas    : const String &otra
     * Retorno     : String& (this)
     **************************************************/
    String &operator=(const String &otra);

    /**************************************************
     * Nombre      : Len
     * Descripción : Longitud (sin '\0').
     * Entradas    : N/A
     * Retorno     : int
     **************************************************/
    int Len() const;

    /**************************************************
     * Nombre      : Length
     * Descripción : Alias de Len().
     * Entradas    : N/A
     * Retorno     : int
     **************************************************/
    int Length() const;

    /**************************************************
     * Nombre      : CStr
     * Descripción : Acceso de solo lectura al buffer.
     * Entradas    : N/A
     * Retorno     : const char*
     **************************************************/
    const char *CStr() const;

    /**************************************************
     * Nombre      : operator[] (no-const)
     * Descripción : Acceso por índice seguro (ajusta a rango).
     * Entradas    : int indice
     * Retorno     : char& (referencia a carácter)
     **************************************************/
    char &operator[](int indice);

    /**************************************************
     * Nombre      : operator[] (const)
     * Descripción : Acceso por índice seguro (ajusta a rango).
     * Entradas    : int indice
     * Retorno     : char (carácter)
     **************************************************/
    char operator[](int indice) const;

    /**************************************************
     * Nombre      : operator+ (const char*)
     * Descripción : Concatena y retorna nuevo String.
     * Entradas    : const char *p_derecha
     * Retorno     : String
     **************************************************/
    String operator+(const char *p_derecha) const;

    /**************************************************
     * Nombre      : operator+ (const String&)
     * Descripción : Concatena y retorna nuevo String.
     * Entradas    : const String &derecha
     * Retorno     : String
     **************************************************/
    String operator+(const String &derecha) const;

    /**************************************************
     * Nombre      : operator+= (char)
     * Descripción : Agrega un carácter al final.
     * Entradas    : char c
     * Retorno     : String& (this)
     **************************************************/
    String &operator+=(char c);

    /**************************************************
     * Nombre      : operator+= (const char*)
     * Descripción : Agrega C-string al final.
     * Entradas    : const char *p_derecha
     * Retorno     : String& (this)
     **************************************************/
    String &operator+=(const char *p_derecha);

    /**************************************************
     * Nombre      : operator+= (const String&)
     * Descripción : Agrega String al final.
     * Entradas    : const String &derecha
     * Retorno     : String& (this)
     **************************************************/
    String &operator+=(const String &derecha);
};

#endif  // STRING_HPP
