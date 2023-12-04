#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void Komunikat(){
    printf("Komunikat2\n");
}

int main(int argc, char *argv[]){
    int wait = atoi(argv[1]);

    signal(SIGALRM,Komunikat);

    alarm(wait);
    printf("Pass alarm %d\n",wait);
    
    int run=0;
    int dump=0;

    while(run==0){
        dump++;
        if(dump%100000000==0){
            printf("%d\n",dump);
        }
    }

    return 0;
}