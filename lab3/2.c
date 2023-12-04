#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){
    int run=0;
    int dump=0;
    
    signal(SIGINT,SIG_IGN);

    while(run==0){
        dump++;
    }

    return 0;
}