#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024


int main(int argc, char*argv[]){
    int lbajt;
    char buf;
    int origin = open(argv[1],O_RDONLY);
    
    while((lbajt = read(origin,&buf,1)) > 0){
    
    return 0;
}