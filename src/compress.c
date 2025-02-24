#include "huffman.h"
#include <string.h>

void comprimirArchivo(const char *input_file, const char *output_file) {
    int frecuencias[256] = {0};
    FILE *in = fopen(input_file, "r");
    if (!in) { perror("Error al abrir archivo de entrada"); exit(1); }
    int c;
    while ((c = fgetc(in)) != EOF) frecuencias[(unsigned char)c]++;
    fclose(in);

    int n = 0;
    for (int i = 0; i < 256; i++) if (frecuencias[i]) n++;
    char simbolos[n];
    int freqs[n];
    int idx = 0;
    for (int i = 0; i < 256; i++) {
        if (frecuencias[i]) {
            simbolos[idx] = (char)i;
            freqs[idx] = frecuencias[i];
            idx++;
        }
    }

    Nodo *arbol = construirArbolHuffman(simbolos, freqs, n);
    FILE *codigos_file = fopen("codigos.txt", "w");
    char codigo[100];
    generarCodigos(arbol, codigo, 0, codigos_file);
    fclose(codigos_file);

    FILE *out = fopen(output_file, "wb");
    if (!out) { perror("Error al abrir archivo de salida"); exit(1); }
    in = fopen(input_file, "r");
    unsigned char buffer = 0;
    int bits = 0;
    rewind(codigos_file = fopen("codigos.txt", "r"));
    char simbolo, cod[100];
    char *codigos[256] = {0};
    while (fscanf(codigos_file, "%c %s\n", &simbolo, cod) != EOF) {
        codigos[(unsigned char)simbolo] = strdup(cod);
    }
    fclose(codigos_file);

    while ((c = fgetc(in)) != EOF) {
        char *cod = codigos[(unsigned char)c];
        for (int i = 0; cod[i]; i++) {
            buffer = (buffer << 1) | (cod[i] - '0');
            bits++;
            if (bits == 8) {
                fwrite(&buffer, 1, 1, out);
                buffer = 0;
                bits = 0;
            }
        }
    }
    if (bits > 0) {
        buffer <<= (8 - bits);
        fwrite(&buffer, 1, 1, out);
    }
    fclose(in);
    fclose(out);
    liberarArbol(arbol);
    for (int i = 0; i < 256; i++) free(codigos[i]);
}
