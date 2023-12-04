#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int desk = open("kolejkaSerwera",O_WRONLY);
    
    mkfifo("k1",0666);

    write(desk,"k1\0",4);
    close(desk);

    desk = open("k1",O_RDONLY);    
    
    close(0);
    dup(desk);
    execlp("wc","wc",NULL);

    return 0;
}