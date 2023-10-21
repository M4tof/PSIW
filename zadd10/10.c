#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 512

void AppendToFromFile(int original, int destination){
    int lbajt;
    char buf[MAX];
    while ((lbajt = read(original,buf,MAX)) > 0){
        write(destination,buf,lbajt);
    }
    write(destination,"\n",1);
}

int main(int argc, char*argv[]){
    int ogCount = argc - 2;
    int desc_cel = open(argv[argc-1],O_WRONLY);
    for (int i=1;i<=ogCount;i++){
        int desc_zrod = open(argv[i],O_RDONLY);
        AppendToFromFile(desc_zrod,desc_cel);
        close(desc_zrod);
    }

    close(desc_cel);
    return 0;
}