# Proyecto Huffman en C

Este proyecto implementa el algoritmo de Huffman para compresión y descompresión de archivos en C, estructurado de forma modular con un Makefile.

## Estructura
- `include/huffman.h`: Cabeceras.
- `src/`: Implementaciones (`huffman.c`, `compress.c`, `decompress.c`, `main.c`).
- `Makefile`: Compilación.

## Uso
1. Compilar: `make`
2. Comprimir: `./huffman comprimir input.txt compressed.bin`
3. Descomprimir: `./huffman descomprimir compressed.bin output.txt`

## Notas
- Genera `codigos.txt` para los códigos Huffman.
- Usa punteros y árboles binarios para la implementación.

## Subir a GitHub
1. `git init`
2. `git add .`
3. `git commit -m "Initial commit"`
4. `git remote add origin <URL>`
5. `git push -u origin main`
