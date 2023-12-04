#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    mkfifo("kolejkaSerwera",0666);
    int desk = open("kolejkaSerwera",O_RDONLY);
    char buf[4];
    
    while (read(desk,&buf,4) > 0 ){
        int deskK = open(buf,O_WRONLY);
        close(1);
        dup(deskK);
        execlp("ls","ls",NULL);
        close(desk);
    }
    
    close(desk);
    unlink("kolejkaSerwera");
    return 0;
}