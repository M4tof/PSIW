#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

int main(int argc, char*argv[]){
    char buf[MAX];
    char singleBuf;
        
    int desc_zrod = open(argv[1],O_RDONLY);
    int desc_dest = open(argv[2],O_WRONLY);

    lseek(desc_zrod,0,SEEK_END);

    int words=0;
    for(int i =0;i<12;i++){
        lseek(desc_zrod,-1,SEEK_CUR);
        read(desc_zrod,&singleBuf,1);
        lseek(desc_zrod,-1,SEEK_CUR);
        printf("%c \n",singleBuf);
    }


    close(desc_dest);
    close(desc_zrod);
    return 0;
}