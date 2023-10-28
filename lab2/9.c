#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int pid =getpid();
    int adr1 = fork();

    if (adr1==0){
        setpgid(getpid(),pid);
        sleep(15);
        printf("2nd proces finished \n");
        exit(0);

    }
    if (adr1!=0){ //w orginale
        
        int adr2 = fork();
        if(adr2==0){
            setpgid(getpid(),pid);
            sleep(5);
            printf("3rd proces finished \n");
            exit(0);
        }
        else{
            waitpid(adr1,NULL,0);
            waitpid(adr2,NULL,0);
            printf("All proceses in group finished ! \n");
            exit(0);
        }
    }
    return 0;
}