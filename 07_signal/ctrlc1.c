/* Código 4.3 - ctrlc1.c - Captura Ctrl+C (SIGINT) con signal().
   El primer Ctrl+C imprime un mensaje; el manejador restaura la accion
   por defecto, asi que el segundo Ctrl+C termina el programa. */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/* Manejador: se ejecuta al recibir la senal */
void ouch(int sig)
{
    printf("OUCH! - I got signal %d\n", sig);
    (void) signal(SIGINT, SIG_DFL);     /* vuelve al comportamiento normal */
}

int main()
{
    (void) signal(SIGINT, ouch);        /* instala el manejador */

    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
}
