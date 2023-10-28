#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char*argv[]){
    char buf;
    int newlineFlag = 0;
    if (argc<2){
        printf("Za malo argumentow \n");
        exit(1);
    }

    int desc_zrod = open(argv[1],O_RDONLY);
    if (desc_zrod == -1){
        printf("Error with opening");
        exit(1);
    }

    int end = lseek(desc_zrod,0,SEEK_END);
    
    while(end > 0){
        if(lseek(desc_zrod,end-1,SEEK_SET)==-1){
            printf("Error with first lseek");
            close(desc_zrod);
            exit(1);
        }

        if ((read(desc_zrod,&buf,1)) == -1){
            printf("Error with reading");
            exit(1);
        }
        
        if (buf == '\n') {
            if (newlineFlag == 0) {
                printf("%c", buf);
                newlineFlag = 1;
            }
        } 
        else {
            printf("%c", buf);
            newlineFlag = 0;
        }
        end--;
    }

    close(desc_zrod);
    return 0;
}