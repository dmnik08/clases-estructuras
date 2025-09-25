/**************************************************
 * Nombre del archivo: ArbolHuffman.cpp
 * Tipo de archivo   : Implementación (.cpp)
 * Proyecto          : Compresor Huffman (sin STL)
 * Autor             : Tu Nombre
 * Descripción       : Implementación completa Huffman:
 *  - conteo de frecuencias
 *  - heap y árbol
 *  - códigos, serialización
 *  - escritura/lectura de bits
 **************************************************/
#include "ArbolHuffman.hpp"
#include "heap.hpp"

/* ===== Utilidades de bits ===== */

static void EscribirBits_(FILE *p_f, const String &binario, int &bit_buffer, int &bit_count) {
    int i = 0;
    while (i < binario.Length()) {
        bit_buffer = (bit_buffer << 1);
        if (binario[i] == '1') {
            bit_buffer = bit_buffer | 1;
        }
        bit_count = bit_count + 1;
        if (bit_count == 8) {
            unsigned char b = (unsigned char)(bit_buffer & 0xFF);
            fwrite(&b, 1, 1, p_f);
            bit_buffer = 0;
            bit_count = 0;
        }
        i = i + 1;
    }
} // fin de EscribirBits_

static void VolcarRestoBits_(FILE *p_f, int &bit_buffer, int &bit_count) {
    if (bit_count > 0) {
        int faltan = 8 - bit_count;
        bit_buffer = (bit_buffer << faltan);
        unsigned char b = (unsigned char)(bit_buffer & 0xFF);
        fwrite(&b, 1, 1, p_f);
        bit_buffer = 0;
        bit_count = 0;
    }
} // fin de VolcarRestoBits_

/* ===== Conteo de frecuencias ===== */

static void ContarFrecuenciasArchivo_(const char *p_nombre, int *p_freq, int &total_bytes) {
    int i = 0;
    while (i < 256) {
        p_freq[i] = 0;
        i = i + 1;
    }
    total_bytes = 0;

    FILE *p_f = std::fopen(p_nombre, "rb");
    if (p_f == 0) {
        return;
    }
    unsigned char c = 0;
    while (fread(&c, 1, 1, p_f) == 1) {
        p_freq[(int)c] = p_freq[(int)c] + 1;
        total_bytes = total_bytes + 1;
    }
    fclose(p_f);
} // fin de ContarFrecuenciasArchivo_

/* ===== Construcción de árbol ===== */

static Nodo *ConstruirArbolHuffman_(int *p_freq) {
    Heap heap;
    int i = 0;
    while (i < 256) {
        if (p_freq[i] > 0) {
            heap.Insertar(new Nodo((char)i, p_freq[i]));
        }
        i = i + 1;
    }
    if (heap.Tamano() == 0) {
        return 0;
    }
    if (heap.Tamano() == 1) {
        Nodo *p_unico = heap.ExtraerMin();
        Nodo *p_dummy = new Nodo('\0', p_unico->ObtenerFrecuencia());
        return new Nodo(p_unico, p_dummy);
    }
    while (heap.Tamano() > 1) {
        Nodo *p_a = heap.ExtraerMin();
        Nodo *p_b = heap.ExtraerMin();
        heap.Insertar(new Nodo(p_a, p_b));
    }
    return heap.ExtraerMin();
} // fin de ConstruirArbolHuffman_

/* ===== Códigos ===== */

static void GenerarCodigos_(Nodo *p_nodo, String actual, String *p_codigos) {
    if (p_nodo == 0) {
        return;
    }
    if (p_nodo->EsHoja()) {
        if (actual.Length() == 0) {
            actual = String("0");
        }
        p_codigos[(unsigned char)p_nodo->ObtenerCaracter()] = actual;
        return;
    }
    GenerarCodigos_(p_nodo->ObtenerIzquierda(),  actual + "0", p_codigos);
    GenerarCodigos_(p_nodo->ObtenerDerecha(),    actual + "1", p_codigos);
} // fin de GenerarCodigos_

/* ===== Serialización ===== */

static void SerializarArbol_(Nodo *p_nodo, String &out) {
    if (p_nodo == 0) {
        return;
    }
    if (p_nodo->EsHoja()) {
        out += 'L';
        out += p_nodo->ObtenerCaracter();
    } else {
        out += 'I';
        SerializarArbol_(p_nodo->ObtenerIzquierda(), out);
        SerializarArbol_(p_nodo->ObtenerDerecha(), out);
    }
} // fin de SerializarArbol_

static Nodo *ReconstruirArbolDesdeBuffer_(const char *p_buf, int &indice, int tam) {
    if (indice >= tam) {
        return 0;
    }
    char tag = p_buf[indice];
    indice = indice + 1;

    if (tag == 'L') {
        if (indice >= tam) {
            return 0;
        }
        char c = p_buf[indice];
        indice = indice + 1;
        return new Nodo(c, 0);
    }
    if (tag == 'I') {
        Nodo *p_izq = ReconstruirArbolDesdeBuffer_(p_buf, indice, tam);
        Nodo *p_der = ReconstruirArbolDesdeBuffer_(p_buf, indice, tam);
        return new Nodo(p_izq, p_der);
    }
    return 0;
} // fin de ReconstruirArbolDesdeBuffer_

static void LiberarArbol_(Nodo *p_nodo) {
    if (p_nodo == 0) {
        return;
    }
    LiberarArbol_(p_nodo->ObtenerIzquierda());
    LiberarArbol_(p_nodo->ObtenerDerecha());
    delete p_nodo;
} // fin de LiberarArbol_

/* ===== I/O de enteros ===== */

static void EscribirU32_(FILE *p_f, std::uint32_t v) {
    fwrite(&v, 4, 1, p_f);
} // fin de EscribirU32_

static std::uint32_t LeerU32_(FILE *p_f) {
    std::uint32_t v = 0;
    fread(&v, 4, 1, p_f);
    return v;
} // fin de LeerU32_

/* ===== API pública ===== */

void ComprimirArchivoGeneral(const char *p_nombre_original) {
    if (p_nombre_original == 0) {
        return;
    }

    int freq[256];
    int total_bytes = 0;
    ContarFrecuenciasArchivo_(p_nombre_original, freq, total_bytes);

    Nodo *p_raiz = ConstruirArbolHuffman_(freq);
    if (p_raiz == 0) {
        String nombre_salida = String(p_nombre_original) + ".huff";
        FILE *p_out = fopen(nombre_salida.CStr(), "wb");
        if (p_out != 0) {
            std::uint32_t tree_size = 0, data_bits = 0;
            EscribirU32_(p_out, tree_size);
            EscribirU32_(p_out, data_bits);
            fclose(p_out);
        }
        return;
    }

    String codigos[256];
    GenerarCodigos_(p_raiz, String(""), codigos);

    String tree_buf;
    SerializarArbol_(p_raiz, tree_buf);

    FILE *p_in = fopen(p_nombre_original, "rb");
    String nombre_salida = String(p_nombre_original) + ".huff";
    FILE *p_out = fopen(nombre_salida.CStr(), "wb");
    if (p_in == 0 || p_out == 0) {
        if (p_in != 0) fclose(p_in);
        if (p_out != 0) fclose(p_out);
        LiberarArbol_(p_raiz);
        return;
    }

    std::uint32_t tree_size = (std::uint32_t)tree_buf.Length();
    EscribirU32_(p_out, tree_size);
    if (tree_size > 0) {
        fwrite(tree_buf.CStr(), 1, tree_size, p_out);
    }

    std::uint32_t data_bits = 0;
    unsigned char c = 0;
    while (fread(&c, 1, 1, p_in) == 1) {
        data_bits = data_bits + (std::uint32_t)codigos[c].Length();
    }
    fseek(p_in, 0, SEEK_SET);

    EscribirU32_(p_out, data_bits);

    int bit_buffer = 0;
    int bit_count = 0;
    while (fread(&c, 1, 1, p_in) == 1) {
        EscribirBits_(p_out, codigos[c], bit_buffer, bit_count);
    }
    VolcarRestoBits_(p_out, bit_buffer, bit_count);

    fclose(p_in);
    fclose(p_out);
    LiberarArbol_(p_raiz);
} // fin de ComprimirArchivoGeneral

void DescomprimirArchivo(const char *p_nombre_huff) {
    if (p_nombre_huff == 0) {
        return;
    }
    FILE *p_in = fopen(p_nombre_huff, "rb");
    if (p_in == 0) {
        return;
    }

    std::uint32_t tree_size = LeerU32_(p_in);

    char *p_tree_bytes = 0;
    if (tree_size > 0) {
        p_tree_bytes = new char[tree_size];
        fread(p_tree_bytes, 1, tree_size, p_in);
    }

    std::uint32_t data_bits = LeerU32_(p_in);

    int idx = 0;
    Nodo *p_raiz = 0;
    if (tree_size > 0) {
        p_raiz = ReconstruirArbolDesdeBuffer_(p_tree_bytes, idx, (int)tree_size);
    }

    String nombre_final = String(p_nombre_huff) + "_dec";
    FILE *p_out = fopen(nombre_final.CStr(), "wb");
    if (p_out == 0) {
        fclose(p_in);
        delete[] p_tree_bytes;
        LiberarArbol_(p_raiz);
        return;
    }

    Nodo *p_actual = p_raiz;
    std::uint32_t bits_leidos = 0;
    int bit_index = -1;
    int byte_leido = 0;
    unsigned char cur = 0;

    while (bits_leidos < data_bits) {
        if (bit_index < 0) {
            byte_leido = fgetc(p_in);
            if (byte_leido == EOF) {
                break;
            }
            cur = (unsigned char)byte_leido;
            bit_index = 7;
        }
        int bit = (cur >> bit_index) & 1;
        bit_index = bit_index - 1;
        bits_leidos = bits_leidos + 1;

        if (p_actual == 0) {
            break;
        }
        if (bit == 0) {
            p_actual = p_actual->ObtenerIzquierda();
        } else {
            p_actual = p_actual->ObtenerDerecha();
        }
        if (p_actual != 0 && p_actual->EsHoja()) {
            unsigned char ch = (unsigned char)p_actual->ObtenerCaracter();
            fwrite(&ch, 1, 1, p_out);
            p_actual = p_raiz;
        }
    }

    fclose(p_out);
    fclose(p_in);
    delete[] p_tree_bytes;
    LiberarArbol_(p_raiz);
} // fin de DescomprimirArchivo
