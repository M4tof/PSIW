#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    mkfifo("kolejka",0640);
    int desk = open("kolejka",O_RDONLY);

    close(0);
    dup(desk);
    execlp("wc","wc",NULL);

    close(desk);
    unlink("kolejka");
    return 0;
}