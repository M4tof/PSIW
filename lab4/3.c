#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX 200

int main(int argc, char *argv[]){
    int pdesk[2];
    pipe(pdesk);
    int adr = fork();

    if (adr!=0){ //w orginale        
        adr = fork();
        if (adr==0){
            close(pdesk[0]);
            write(pdesk[1],"World\0",7);

            close(pdesk[1]);
        }
        close(pdesk[0]);
        write(pdesk[1],"Halo\0\n",7);
        close(pdesk[1]);

    }

    else{ // potomny
        close(pdesk[1]);
        char buf[MAX];
        
        while(read(pdesk[0],&buf,MAX)){
            for(int i=0;i<14;i++){
                printf("%c",buf[i]);
            }
        };
        


        printf("\n");
        close(pdesk[0]);
    }
    return 0;
}