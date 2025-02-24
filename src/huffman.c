#include "huffman.h"
#include <stdlib.h>

Nodo* crearNodo(char simbolo, int frecuencia) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) exit(1);
    nuevo->simbolo = simbolo;
    nuevo->frecuencia = frecuencia;
    nuevo->izquierdo = nuevo->derecho = NULL;
    return nuevo;
}

int compararNodos(const void *a, const void *b) {
    return (*(Nodo**)a)->frecuencia - (*(Nodo**)b)->frecuencia;
}

Nodo* construirArbolHuffman(char simbolos[], int frecuencias[], int n) {
    Nodo **nodos = (Nodo**)malloc(n * sizeof(Nodo*));
    for (int i = 0; i < n; i++) nodos[i] = crearNodo(simbolos[i], frecuencias[i]);
    int tam = n;
    while (tam > 1) {
        qsort(nodos, tam, sizeof(Nodo*), compararNodos);
        Nodo *izq = nodos[0];
        Nodo *der = nodos[1];
        Nodo *padre = crearNodo('\0', izq->frecuencia + der->frecuencia);
        padre->izquierdo = izq;
        padre->derecho = der;
        nodos[0] = padre;
        for (int i = 1; i < tam - 1; i++) nodos[i] = nodos[i + 1];
        tam--;
    }
    Nodo *raiz = nodos[0];
    free(nodos);
    return raiz;
}

void generarCodigos(Nodo *raiz, char *codigo, int nivel, FILE *codigos_file) {
    if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
        codigo[nivel] = '\0';
        fprintf(codigos_file, "%c %s\n", raiz->simbolo, codigo);
        return;
    }
    if (raiz->izquierdo) {
        codigo[nivel] = '0';
        generarCodigos(raiz->izquierdo, codigo, nivel + 1, codigos_file);
    }
    if (raiz->derecho) {
        codigo[nivel] = '1';
        generarCodigos(raiz->derecho, codigo, nivel + 1, codigos_file);
    }
}

void liberarArbol(Nodo *raiz) {
    if (raiz) {
        liberarArbol(raiz->izquierdo);
        liberarArbol(raiz->derecho);
        free(raiz);
    }
}
