/**************************************************
 * Nombre del archivo: HuffmanMain.cpp
 * Tipo de archivo   : Implementación (.cpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : Punto de entrada del programa.
 **************************************************/
#include <cstdio>
#include "ArbolHuffman.hpp"

int main(int argc, char **argv) {
    if (argc < 3) {
        std::printf("Uso:\n");
        std::printf("  %s c <archivo>\n", argv[0]);
        std::printf("  %s d <archivo.huff>\n", argv[0]);
        return 0;
    }

    if (argv[1][0] == 'c') {
        ComprimirArchivoGeneral(argv[2]);
    } else if (argv[1][0] == 'd') {
        DescomprimirArchivo(argv[2]);
    } else {
        std::printf("Opcion invalida.\n");
    }
    return 0;
} // fin de main
