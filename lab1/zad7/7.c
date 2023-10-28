#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 2048

void manStrRev(char *str){
    int start=0;
    int end=strlen(str)-2;
    while(start<end){
        char byte=str[start];
        str[start]=str[end];
        str[end]=byte;
        start++;
        end--;
    }
}

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
    int letter=0;
    while(words<10){
        lseek(origin,-1,SEEK_CUR);
        read(origin,&byte,1);
        lseek(origin,-1,SEEK_CUR);
        
        

        if(*byte==' '){
            buf[words][letter++]='\n';
            buf[words][letter++]='\0';
            words++;
            letter=0;
        }
        else if(*byte=='\n'){
            buf[words][letter++]='\n';
            buf[words][letter++]='\0';
            words++;
            letter=0;
            lseek(origin,-1,SEEK_CUR);
        }
        else{
            buf[words][letter]=*byte;
            letter++;
        }
    }

    for(int i=0;i<10;i++){
        manStrRev(buf[i]);
        printf("%s",buf[i]);
        write(destination,buf[i],strlen(buf[i]));
    }

}

void Lines(int origin, int destination){
    char buf[10][MAX];
    char byte[MAX];
    lseek(origin,0,SEEK_END);

    int lines=0;
    int letter=0;
    while(lines<10){
        lseek(origin,-1,SEEK_CUR);
        read(origin,&byte,1);
        lseek(origin,-1,SEEK_CUR);
        
        if(*byte=='\n'){
            buf[lines][letter++]='\n';
            buf[lines][letter++]='\0';
            lines++;
            letter=0;
            lseek(origin,-1,SEEK_CUR);
        }
        else{
            buf[lines][letter]=*byte;
            letter++;
        }
    }

    for(int i=0;i<10;i++){
        manStrRev(buf[i]);
        printf("%s",buf[i]);
        write(destination,buf[i],strlen(buf[i]));
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
        Words(desc_zrod,desc_dest);
        break;
    case 51:
        Lines(desc_zrod,desc_dest);
        break;
    default:
        break;
    }

    close(desc_dest);
    close(desc_zrod);
    return 0;
}