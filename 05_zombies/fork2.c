/* Código 3.6 - fork2.c - Igual que fork1.c pero con los conteos invertidos:
   el hijo termina primero y, como el padre no llama a wait(),
   queda como zombie (<defunct>) hasta que el padre acaba.
   Pruebalo con:  ./fork2 &   y luego   ps -al */
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
    case 0:                             /* hijo: termina primero */
        message = "This is the child";
        n = 3;
        break;
    default:                            /* padre */
        message = "This is the parent";
        n = 5;
        break;
    }

    for(; n > 0; n--) {
        puts(message);
        sleep(1);
    }
    exit(0);
}
