/* Código 3.9 - useupper.c - Ejecuta el filtro upper sobre un archivo.
   Redirige stdin al archivo y luego reemplaza el proceso con upper;
   como los descriptores abiertos se conservan tras exec, upper lee
   del archivo. Equivale a:  ./upper < file.txt */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *filename;

    if (argc != 2) {
        fprintf(stderr, "usage: useupper file\n");
        exit(1);
    }

    filename = argv[1];

    /* stdin ahora apunta al archivo */
    if(!freopen(filename, "r", stdin)) {
        fprintf(stderr, "could not redirect stdin from file %s\n", filename);
        exit(2);
    }

    execl("./upper", "upper", 0);

    /* Solo se llega aqui si execl falla */
    perror("could not exec ./upper");
    exit(3);
}
