#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
    printf("Poczatek\n");
    execlp("ls","ls",NULL);
    printf("Koniec\n");

    return 0;
}