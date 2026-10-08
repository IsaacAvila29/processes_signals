/* Código 4.7 y 4.8 - alarm.c - Simula un despertador con fork(), kill() y pause().
   El hijo espera 5 segundos y le manda SIGALRM al padre;
   el padre se suspende con pause() hasta recibir la senal. */
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

/* El manejador solo pone una bandera (no es seguro usar printf aqui) */
void ding(int sig)
{
    alarm_fired = 1;
}

int main()
{
    pid_t pid;

    printf("alarm application starting\n");

    pid = fork();
    switch(pid) {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        /* hijo: espera y avisa al padre */
        sleep(5);
        kill(getppid(), SIGALRM);
        exit(0);
    }

    /* a partir de aqui solo corre el padre */
    printf("waiting for alarm to go off\n");
    (void) signal(SIGALRM, ding);

    pause();                /* suspende hasta que llegue una senal */
    if (alarm_fired)
        printf("Ding!\n");

    printf("done\n");
    exit(0);
}
