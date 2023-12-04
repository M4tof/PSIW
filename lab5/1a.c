#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    mkfifo("kolejka",0666);
    int desk = open("kolejka",O_RDONLY);
    char buf[6];
    while (read(desk,&buf,6) > 0 ){
        printf("%s\n",buf);
    }
    close(desk);
    unlink("kolejka");
    return 0;
}