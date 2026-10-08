/* Código 3.2 - exec_ejemplos.c - Las seis variantes de exec para lanzar ps.
   - l (execl*): argumentos como lista, terminada en 0
   - v (execv*): argumentos como arreglo
   - p: busca el programa en el PATH
   - e: recibe un entorno (envp) propio
   Se envolvio en main() para que compile; solo se ejecuta la primera
   llamada exec que tenga exito, porque reemplaza al proceso actual. */
#include <unistd.h>

/* Lista de argumentos; argv[0] debe ser el nombre del programa */
char *const ps_argv[] =
    {"ps", "ax", 0};

/* Entorno de ejemplo para execle/execve */
char *const ps_envp[] =
    {"PATH=/bin:/usr/bin", "TERM=console", 0};

int main()
{
    execl("/bin/ps", "ps", "ax", 0);              /* ruta completa */
    execlp("ps", "ps", "ax", 0);                  /* busca ps en el PATH */
    execle("/bin/ps", "ps", "ax", 0, ps_envp);    /* entorno propio */

    execv("/bin/ps", ps_argv);
    execvp("ps", ps_argv);
    execve("/bin/ps", ps_argv, ps_envp);
    return 1;   /* solo se llega aqui si todos los exec fallan */
}
