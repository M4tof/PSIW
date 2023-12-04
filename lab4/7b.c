#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 200

int main(int argc, char *argv[]){
    int pdesk[2];
    pipe(pdesk);
    int adr = fork();

    if (adr!=0){ //w orginale        
        close(pdesk[0]);
        close(1);
        dup(pdesk[1]);
        execlp("ls","ls","-l",NULL);
        close(pdesk[1]);

    }

    else{ // potomny
        close(pdesk[1]);
        close(0);
        dup(pdesk[0]);
        execlp("grep","grep","^d",NULL);
        close(pdesk[0]);
    }
    return 0;
}