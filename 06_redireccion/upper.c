/* Código 3.8 - upper.c - Filtro: lee de la entrada estandar y escribe todo en mayusculas.
   Ejemplo:  ./upper < file.txt */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int ch;
    while((ch = getchar()) != EOF) {
        putchar(toupper(ch));
    }
    exit(0);
}
