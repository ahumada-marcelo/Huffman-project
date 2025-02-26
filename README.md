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

## Errores
- Errores al usar git.
1)
[marcelo@vialca7 huffman_project]$ git push -u origin main
git@github.com: Permission denied (publickey).
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
[marcelo@vialca7 huffman_project]$ ssh-add ~/.ssh/
known_hosts      known_hosts.old  migit_rsa        migit_rsa.pub    
[marcelo@vialca7 huffman_project]$ ssh-add ~/.ssh/migit_rsa
Could not open a connection to your authentication agent.

2) Tuve que cargar nuevamente el agente para poder tener acceso mediante ssh
[marcelo@vialca7 huffman_project]$ eval `ssh-agent -s`
Agent pid 51809
[marcelo@vialca7 huffman_project]$ ssh-add ~/.ssh/migit_rsa
Identity added: /home/marcelo/.ssh/migit_rsa (ahumada.marcelo@gmail.com)
[marcelo@vialca7 huffman_project]$ git push -u origin main
Enumerating objects: 11, done.
Counting objects: 100% (11/11), done.
Delta compression using up to 2 threads
Compressing objects: 100% (10/10), done.
Writing objects: 100% (11/11), 3.48 KiB | 890.00 KiB/s, done.
Total 11 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:ahumada-marcelo/Huffman-project.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.


