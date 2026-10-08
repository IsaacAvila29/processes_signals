/* fork_fragmento.c - Estructura tipica despues de llamar a fork().
   fork() regresa -1 si falla, 0 en el hijo y el PID del hijo en el padre. */
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t new_pid;

    new_pid = fork();

    switch(new_pid) {
    case -1 :    /* Error */
        break;
    case 0 :     /* Somos el hijo */
        break;
    default :    /* Somos el padre */
        break;
    }
    return 0;
}
