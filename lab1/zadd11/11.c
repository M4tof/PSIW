#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024


int main(int argc, char*argv[]){
    int desc_zrod;
    int lbajt;

    if (argc>=2){
        int words=0;
        char buf;
        desc_zrod = open(argv[1],O_RDWR);
        while((lbajt = read(desc_zrod,&buf,1)) > 0){
            if(buf<=47 || (buf>=58 && buf<=64) || (buf>=91 && buf <=96 && buf!=95) || buf>=123){
                words++;
            }
        }
        printf("The file consists of %d words",++words);
        close(desc_zrod);
    }
    
    else{
        int words=0;
        char buf[MAX];
        int hasRead = read(STDIN_FILENO,buf,MAX);
        for (int i =0; i<hasRead;i++){
            if(buf[i]<=47 || (buf[i]>=58 && buf[i]<=64) || (buf[i]>=91 && buf[i]<=96 && buf[i]!=95) || buf[i]>=123){
                words++;
            }
        }
        printf("The string consists of %d words",words);
        close(desc_zrod);
    }
    return 0;
}