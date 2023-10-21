#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#define MAX 2048

int main(int argc, char*argv[]){
    int desc_zrod = open(argv[1],O_RDONLY);
    char byte;

    while(read(desc_zrod,&byte,1)>0){
        if (!isascii(byte)){
            printf("This file contains NON basic ascii characters \n");
            close(desc_zrod);
            return 0;
        }
    }
    printf("This file contains only basic ascii characters \n");
    close(desc_zrod);
    return 0;
}