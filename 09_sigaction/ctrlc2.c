/* Código 4.10 - ctrlc2.c - Version de ctrlc1.c con sigaction(), la interfaz recomendada.
   El manejador no se reinicia, asi que cada Ctrl+C imprime el mensaje.
   Para salir usa Ctrl+\ (SIGQUIT). */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
    printf("OUCH! - I got signal %d\n", sig);
}

int main()
{
    struct sigaction act;

    act.sa_handler = ouch;          /* funcion a ejecutar */
    sigemptyset(&act.sa_mask);      /* no bloquear senales extra */
    act.sa_flags = 0;               /* sin opciones especiales */

    sigaction(SIGINT, &act, 0);

    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
}
