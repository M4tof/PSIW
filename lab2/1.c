#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
    int rdpid = getpid();
    int adr = fork();
    if(adr==0){ //w potomku
        printf("Rodzic => %d, potomek=> %d\n",rdpid,getpid());
    }
    else{
        printf("1Jestem rodzicem o pid = %d\n",rdpid);
    }

    rdpid=getpid();
    int adr2gen = fork();
    if(adr2gen==0){ //w potomku
        printf("Rodzic => %d, potomek=> %d\n",rdpid,getpid());
    }
    else{
        printf("2Jestem rodzicem o pid = %d\n",rdpid);
    }


    return 0;
}