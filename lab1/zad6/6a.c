#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Za malo argumentow\n");
        exit(1);
    }

    int desc_zrod = open(argv[1], O_RDONLY);
    if (desc_zrod == -1) {
        printf("Error with opening");
        exit(1);
    }

    int end = lseek(desc_zrod, 0, SEEK_END);
    if (end == -1) {
        printf("Error with lseek");
        close(desc_zrod);
        exit(1);
    }

    char buf;
    int counted=0;

    while(lseek(desc_zrod,0,SEEK_CUR)>0){
        
        while(buf != '\n' && lseek(desc_zrod,0,SEEK_CUR)!= 0){
            if (lseek(desc_zrod,-1,SEEK_CUR) ==-1){
                printf("Error 1");
                close(desc_zrod);
                exit(1);
            }
            if(read(desc_zrod,&buf,1) <=0){
                printf("Error 2");
                close(desc_zrod);
                exit(1);
            }
            if (lseek(desc_zrod,-1,SEEK_CUR) ==-1){
                printf("Error 3");
                close(desc_zrod);
                exit(1);
            }
            counted++;
        }
        
        if(lseek(desc_zrod,0,SEEK_CUR)== 0){
            printf("\n");
        }
        
        for(int i=0;i<counted;i++){
            read(desc_zrod,&buf,1);
            printf("%c",buf);
        }
        
        if (lseek(desc_zrod,-counted,SEEK_CUR) ==-1){
                printf("Error 5");
                close(desc_zrod);
                exit(1);
            }
        
        if(lseek(desc_zrod,0,SEEK_CUR)==0){
                break;
            }
        counted=0;
    }
    

    printf("\n");
    close(desc_zrod);
    return 0;
}