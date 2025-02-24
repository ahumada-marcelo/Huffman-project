#include "huffman.h"

void descomprimirArchivo(const char *compressed_file, const char *output_file, const char *codes_file) {
    Nodo *raiz = crearNodo('\0', 0);
    FILE *codigos = fopen(codes_file, "r");
    char simbolo, cod[100];
    while (fscanf(codigos, "%c %s\n", &simbolo, cod) != EOF) {
        Nodo *actual = raiz;
        for (int i = 0; cod[i]; i++) {
            if (cod[i] == '0') {
                if (!actual->izquierdo) actual->izquierdo = crearNodo('\0', 0);
                actual = actual->izquierdo;
            } else {
                if (!actual->derecho) actual->derecho = crearNodo('\0', 0);
                actual = actual->derecho;
            }
        }
        actual->simbolo = simbolo;
    }
    fclose(codigos);

    FILE *in = fopen(compressed_file, "rb");
    FILE *out = fopen(output_file, "w");
    Nodo *actual = raiz;
    unsigned char byte;
    while (fread(&byte, 1, 1, in)) {
        for (int i = 7; i >= 0; i--) {
            int bit = (byte >> i) & 1;
            actual = bit ? actual->derecho : actual->izquierdo;
            if (actual->izquierdo == NULL && actual->derecho == NULL) {
                fputc(actual->simbolo, out);
                actual = raiz;
            }
        }
    }
    fclose(in);
    fclose(out);
    liberarArbol(raiz);
}
