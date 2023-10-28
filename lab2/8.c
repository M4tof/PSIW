#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int adr = fork();

    if (adr != 0){ //w rodzicu
        printf("Parent process is exiting...\n");
        exit(0);
    } 
    else{
        printf("Child process is running...\n");
        sleep(10);
        printf("Child process continuing after parent exited...\n");
        while(1) {
            sleep(5);
            printf("Child process continuing after parent exited...\n");
        }
    }

    return 0;
}
