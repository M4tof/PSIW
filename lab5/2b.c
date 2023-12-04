#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int desk = open("kolejka",O_WRONLY);

    close(1);
    dup(desk);
    execlp("ls","ls",NULL);

    close(desk);
    
    return 0;
}