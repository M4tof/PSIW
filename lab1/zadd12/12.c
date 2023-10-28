#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024


int main(int argc, char*argv[]){
    int lowwerLetterCount[26]={0};
    int upperLetterCount[26]={0};
    int lbajt;
    char buf;
    int origin = open(argv[1],O_RDONLY);
    
    while((lbajt = read(origin,&buf,1)) > 0){
        if(buf>=65 && buf <=90){
            upperLetterCount[buf-'A']++;
        } 
        else if(buf>=97 && buf<=122){
            lowwerLetterCount[buf-'a']++;
        }
    }
    close(origin);
    int sum=0;
    for(int i=0;i<26;i++){
        sum=sum+lowwerLetterCount[i]+upperLetterCount[i];
    }
    for(int j=0;j<26;j++){
        double upperPercentage = (double)upperLetterCount[j] / sum * 100;
        double lowerPercentage = (double)lowwerLetterCount[j] / sum * 100;
        printf("%c is %.2lf%% and ",'A'+j,upperPercentage);
        printf("%c is %.2lf%% \n",'a'+j,lowerPercentage);
    }
    
    return 0;
}