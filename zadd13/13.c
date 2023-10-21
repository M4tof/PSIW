#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 2048

int main(int argc, char*argv[]){
    char buf[MAX];
    char *key = argv[1];

    int hasRead = read(STDIN_FILENO,buf,MAX);

    buf[hasRead]='\0';
    
    int keyLen = strlen(key);
    int bufLen = strlen(key);
    int ismatch = 0;
    for(int i=0;i<=bufLen - keyLen;i++){
        int j;
        for (j=0;j<keyLen;j++){
            if(buf[i+j]!=key[j]){
                break;
            }
        }
        if(j==keyLen){
            ismatch=1;
            break;
        }
    }

    if(ismatch){
        printf("%s",buf);
    }
    
    return 0;
}