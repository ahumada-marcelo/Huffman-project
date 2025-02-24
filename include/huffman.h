#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>

typedef struct Nodo {
    char simbolo;
    int frecuencia;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
} Nodo;

Nodo* crearNodo(char simbolo, int frecuencia);
Nodo* construirArbolHuffman(char simbolos[], int frecuencias[], int n);
void generarCodigos(Nodo *raiz, char *codigo, int nivel, FILE *codigos_file);
void liberarArbol(Nodo *raiz);
void comprimirArchivo(const char *input_file, const char *output_file);
void descomprimirArchivo(const char *compressed_file, const char *output_file, const char *codes_file);

#endif
