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

    int desc_zrod = open(argv[1],O_RDONLY);
    if (desc_zrod == -1){
        printf("Error with opening");
        exit(1);
    }

    int end = lseek(desc_zrod,0,SEEK_END);
    
    int goBackBy=0;
    int u=0; //debug
    while(lseek(desc_zrod,0,SEEK_CUR) != 0){
        if(lseek(desc_zrod,-1,SEEK_CUR)==-1){
            printf("Error with first lseek");
            close(desc_zrod);
            exit(1);
        }
        goBackBy++;
        if(buf == '\n'){
            if(read(desc_zrod,&buf,goBackBy) ==-1){
                printf("Error with reading");
                close(desc_zrod);
                exit(1);
            }
            
            printf("dochodzi do teraz"); //tutaj print buf
            
            if(lseek(desc_zrod,goBackBy,SEEK_CUR)==-1){
                printf("Error with second lseek");
                close(desc_zrod);
                exit(1);
            }
        }
        u++; //debug
    }
    printf("%d\n",u); //debug
    
    close(desc_zrod);
    return 0;
}