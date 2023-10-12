#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1

int main(int argc, char*argv[]){
    char buf[MAX];
    int desc_zrod;
    int lbajt;

    if (argc<2){
        printf("Za malo argumentow \n");
        exit(1);
    }

    desc_zrod = open(argv[1],O_RDWR);
    if (desc_zrod == -1){
        printf("Blad otwarcia");
        exit(1);
    }
    
    char X='X';
    while((lbajt = read(desc_zrod,buf,MAX)) > 0){
        if(buf[0]=='x'){
            long roz =lseek(desc_zrod,-1,SEEK_CUR);
            if (write(desc_zrod,&X,1)==-1){
                printf("Error");
                exit(1);
            }
        }   
    }

    if(close(desc_zrod) == -1){
        printf("Blad zamkniecia");
        exit(1);
    }

    return 0;
}