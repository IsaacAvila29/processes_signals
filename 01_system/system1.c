/* Código 3.1 - system1.c - Ejecuta "ps ax" desde un programa usando system().
   system() lanza un shell (sh -c) y espera a que el comando termine. */
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Running ps with system\n");
    system("ps ax");        /* bloquea hasta que ps termina */
    printf("Done.\n");      /* se imprime despues de toda la salida de ps */
    exit(0);
}
