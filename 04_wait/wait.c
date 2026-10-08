/* wait.c - Como fork1.c, pero el padre espera al hijo con wait()
   y revisa su codigo de salida (37) con las macros de sys/wait.h. */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;

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
        exit_code = 37;
        break;
    default:                            /* padre */
        message = "This is the parent";
        n = 3;
        exit_code = 0;
        break;
    }

    for(; n > 0; n--) {
        puts(message);
        sleep(1);
    }

    /* Solo el padre espera a que el hijo termine */
    if (pid != 0) {
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);    /* se bloquea hasta que el hijo acaba */

        printf("Child has finished: PID = %d\n", child_pid);
        if(WIFEXITED(stat_val))         /* termino normalmente? */
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
    }
    exit(exit_code);
}
