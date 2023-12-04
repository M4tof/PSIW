#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void mFunc(int arg){
    printf(" %d was sent",arg);
    printf("\n");
}

int main(int argc, char *argv[]){
    int run=0;
    int dump=0;
    
    for(int i=1;i<20;i++){
        signal(i,mFunc);
    }
    
    while(run==0){
        dump++;
    }

    return 0;
}