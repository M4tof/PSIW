#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
    int adr = fork();
    if(adr==0){
        printf("Dziecko %d\n",getpid());
        alarm(2);
        pause();
    }
    else{
        wait(NULL);
        printf("Rodzic %d\n",getpid());


        signal(SIGCLD,SIG_IGN);    
        printf("\nTeraz ignoruje\n\n");
                
        adr = fork();
        if(adr!=0){
            wait(NULL);
            printf("Rodzic %d\n",getpid());
            
        }
        else{
            printf("Dziecko2 %d\n",getpid());
            alarm(2);
            pause();
        }
    }

    return 0;
}