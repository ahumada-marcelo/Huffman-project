/*
*   huffman - Projecto generado con la inteligencia artifial de la red X Grok
*
*   
*/

#include "huffman.h"

int main(int argc, char *argv[]) 
{
    if (argc != 4) 
    {
        printf("Uso: %s <comprimir/descomprimir> <entrada> <salida>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "comprimir") == 0) 
    {
        comprimirArchivo(argv[2], argv[3]);
        printf("Archivo comprimido en %s\n", argv[3]);
    } else if (strcmp(argv[1], "descomprimir") == 0) 
    {
        descomprimirArchivo(argv[2], argv[3], "codigos.txt");
        printf("Archivo descomprimido en %s\n", argv[3]);
    } else 
    {
        printf("Opción inválida: %s\n", argv[1]);
        return 1;
    }
    
    return 0;
}
