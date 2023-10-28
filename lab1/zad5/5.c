#include <fcntl.h>
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
    
    int longestLineNr=0;
    int currLineNr=1;
    int longestSize=0;
    int currLongest=0;

    while (read(desc_zrod,&buf,1) >0){
        currLongest++;
        if (buf == '\n'){
            currLongest=0;
            currLineNr++;
        }
        if (currLongest > longestSize){
            longestSize = currLongest;
            longestLineNr = currLineNr;
        }
    }
    close(desc_zrod);
    
    printf("The longest line is line nr= %d, which has %d characters.",longestLineNr,longestSize);
    return 0;
}