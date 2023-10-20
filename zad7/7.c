#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

void Chars(int origin, int destination){
    char buf[MAX];
    lseek(origin,0,SEEK_END);

    int words=0;
    while(words<10){
        lseek(origin,-1,SEEK_CUR);
        read(origin,&buf[words],1);
        lseek(origin,-1,SEEK_CUR);
        if(buf[words]!='\n'){
            words++;
        }
        else{
            lseek(origin,-1,SEEK_CUR);
        }
    }
    for(int i=9;i>0;i--){
        printf("%c",buf[i]);
        write(destination,&buf[i],1);
    }
}

void Words(int origin, int destination){
    char buf[10][MAX];
    char byte[MAX];
    lseek(origin,0,SEEK_END);

    int words=0;
    while(words<10){
        lseek(origin,-1,SEEK_CUR);
        read(origin,&byte,1);
        lseek(origin,-1,SEEK_CUR);
        if(byte=='\n' || byte==' '){
            words++;
        }
        else{
            lseek(origin,-1,SEEK_CUR);
        }
    }
    for(int i=9;i>0;i--){
        printf("%c",buf[i]);
        write(destination,&buf[i],1);
    }
}

int main(int argc, char*argv[]){
        
    int desc_zrod = open(argv[1],O_RDONLY);
    int desc_dest = open(argv[2],O_WRONLY);

    switch (*argv[3])
    {
    case 49:
        Chars(desc_zrod,desc_dest);
        break;
    case 50:

        break;
    default:
        break;
    }

    close(desc_dest);
    close(desc_zrod);
    return 0;
}