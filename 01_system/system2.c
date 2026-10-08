/* system2.c - Igual que system1.c, pero ps se lanza en segundo plano (&).
   El shell regresa de inmediato, asi que "Done." puede salir antes que ps. */
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Running ps with system\n");
    system("ps ax &");      /* no espera a que ps termine */
    printf("Done.\n");
    exit(0);
}
