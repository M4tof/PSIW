#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int desk = open("kolejka",O_WRONLY);
    write(desk,"Hallo\0",6);
    write(desk, "World\0",6);
    close(desk);
    return 0;
}