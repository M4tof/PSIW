#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

int main(int argc, char*argv[]){
    int desc_zrod;
    int lbajt;

    if (argc>=2){
        char buf;
        desc_zrod = open(argv[1],O_RDWR);
        while((lbajt = read(desc_zrod,&buf,1)) > 0){
            if(buf <=122 && buf >=97){
                lseek(desc_zrod,-1,SEEK_CUR);
                char zamiennik = buf - 32;
                write(desc_zrod,&zamiennik,1);
            }
        }
        close(desc_zrod);
    }
    
    else{
        char buf[MAX];
        int hasRead = read(STDIN_FILENO,buf,MAX);
        for (int i =0; i<hasRead;i++){
            if(buf[i] <= 122 && buf[i] >= 97){
                printf("%c",buf[i]-32);
            }
            else{
                printf("%c",buf[i]);
            }
        }
    }
    return 0;
}