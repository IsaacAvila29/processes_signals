/* Código 3.3 - pexec.c - Reemplaza el proceso actual por "ps ax" usando execlp.
   El PID se conserva, pero el codigo de este programa desaparece,
   por eso "Done." nunca se imprime. */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Running ps with execlp\n");
    execlp("ps", "ps", "ax", 0);    /* si tiene exito, no regresa */
    printf("Done.\n");              /* solo se ejecuta si execlp falla */
    exit(0);
}
