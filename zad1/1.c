#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 512


int main(int argc, char*argv[]){
    if (argc<3){
        printf("Za malo argumentow \n");
        exit(1);
    }
    creat(argv[1], 0640);

    int desc_zrod = open(argv[1],O_WRONLY);
    if (desc_zrod == -1){
        printf("Error on line 16");
        exit(1);
    }

    write(desc_zrod,argv[2],sizeof(argv[2])/sizeof(argv[2][0])-1);

    close(desc_zrod);
    return 0;
}