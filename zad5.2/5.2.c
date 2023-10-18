#include <fcntl.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char*argv[]){
    char buf;
    if (argc<2){
        printf("Za malo argumentow \n");
        exit(1);
    }
    
    for(int i=1;i<argc;i++){
        printf("File %s =",argv[i]);
        int desc_zrod = open(argv[i],O_RDONLY);
        if (desc_zrod == -1){
            printf("Error with opening");
            exit(1);
        }
        int size = 0;
        size = lseek(desc_zrod,0,SEEK_END);
        if(size == -1){
            printf("Error with lseek");
            exit(1);
        }
        printf(" %d bits \n",size);
        close(desc_zrod);
    }
    
    return 0;
}