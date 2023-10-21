#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024


int main(int argc, char*argv[]){
    int origin = open(argv[1],O_RDWR);
    
    char word[MAX];
    int pos=0;
    char buf;
    int nFlag=0;

    while(read(origin,&buf,1) > 0){
        if(buf!='\n'){
            word[pos]=buf;
            pos++;
        }
        else{
            lseek(origin,-pos - 1,SEEK_CUR);
            for(int i=pos-1;i>=0;i--){
                write(origin,&word[i],1);
            }
            lseek(origin,1,SEEK_CUR);
            pos=0;
            nFlag=1;
            }
    }
        lseek(origin, -pos - nFlag, SEEK_CUR);
        write(origin,"\n",1);
        for (int i = pos - 1; i >= 0; i--) {
            write(origin, &word[i], 1);
        }

    close(origin);
    return 0;
}