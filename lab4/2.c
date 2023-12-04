#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){
    int pdesk[2];
    pipe(pdesk);
    int adr = fork();

    if (adr!=0){ //w orginale
        adr = fork();
        if (adr==0){
            printf("Potomny 2:");
            close(pdesk[0]);
            write(pdesk[1],"Hallo\0",6);
            close(pdesk[1]);
        }
    }

    else{ // potomny
        printf("Potomny1:");
        close(pdesk[1]);
        char buf[6];
        read(pdesk[0],&buf,6);
        for(int i=0;i<7;i++){
            printf("%c",buf[i]);
        }
        printf("\n");
        close(pdesk[0]);
    }
    return 0;
}