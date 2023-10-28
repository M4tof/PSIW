#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("Poczatek\n");
    int adr = fork();
    
    if(adr==0){ //w potomku
        execlp("ls","ls",NULL);
        exit(0);
    }
    
    else{ // w rodzicu
        wait(NULL);
        printf("Koniec\n");
    }

    return 0;
}