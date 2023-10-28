#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("-----poczatek-----\n");
    int adr = fork();
    
    if(adr==0){ //w potomku
        execlp("ps","ps","-o","pid=",NULL);
        exit(0);
    }
    
    else{ // w rodzicu
        wait(NULL);
        printf("-----koniec-----\n");
    }

    return 0;
}