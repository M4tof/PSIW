#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int adr = fork();
    if (adr!=0){ //w orginale
        adr = fork();
        if(adr!=0){
            adr = fork();
            if(adr!=0){
                execlp("ps","ps","aux",NULL);
            }
        }
    }


    return 0;
}