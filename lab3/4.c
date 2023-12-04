#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sleepalrm(){}

int main(int argc, char *argv[]){
    int wait = atoi(argv[1]);

    signal(SIGALRM,sleepalrm);
    alarm(wait);
    pause();


    printf("Finished sleeping\n");
    return 0;
}