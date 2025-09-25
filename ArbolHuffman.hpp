/**************************************************
 * Nombre del archivo: ArbolHuffman.hpp
 * Tipo de archivo   : Encabezado (.hpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : API de compresión/descompresión.
 **************************************************/
#ifndef ARBOLHUFFMAN_HPP
#define ARBOLHUFFMAN_HPP

#include <cstdio>
#include <cstdint>
#include "String.hpp"
#include "nodo.hpp"

/**************************************************
 * Nombre      : ComprimirArchivoGeneral
 * Descripción : Comprime archivo y genera <nombre>.huff
 * Entradas    : const char *p_nombre_original
 * Retorno     : void
 **************************************************/
void ComprimirArchivoGeneral(const char *p_nombre_original);

/**************************************************
 * Nombre      : DescomprimirArchivo
 * Descripción : Descomprime archivo .huff a <nombre>_dec
 * Entradas    : const char *p_nombre_huff
 * Retorno     : void
 **************************************************/
void DescomprimirArchivo(const char *p_nombre_huff);

#endif  // ARBOLHUFFMAN_HPP
