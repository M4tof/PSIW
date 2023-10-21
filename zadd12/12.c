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
        printf("Empty space");
    }
    return 0;
}