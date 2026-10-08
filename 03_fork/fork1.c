/* fork1.c - Crea un hijo con fork(). El hijo imprime 5 mensajes y el padre 3.
   El padre termina primero, por eso el prompt del shell aparece
   mezclado con la salida del hijo. */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;

    printf("fork program starting\n");
    pid = fork();
    switch(pid)
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:                             /* hijo */
        message = "This is the child";
        n = 5;
        break;
    default:                            /* padre */
        message = "This is the parent";
        n = 3;
        break;
    }

    /* Ambos procesos ejecutan este ciclo, cada uno con sus propios valores */
    for(; n > 0; n--) {
        puts(message);
        sleep(1);
    }
    exit(0);
}
