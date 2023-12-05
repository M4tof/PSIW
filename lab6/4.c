#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define M_DANE 1;
#define M_END 2;
#define M_WYNIK 3;

struct msgb{
    long type;
    int num;
};

int main(){
    key_t qid = msgget(1234,IPC_CREAT|0640);

    int adr = fork();

    if(adr!=0){     //Server
        struct msgb w2;

    }

    else{           //Klient
        struct msgb w;
        w.type = M_DANE;
        for(int i=0; i<=20; i++){
                w.num=i;
                msgsnd(qid,&w,sizeof(w.num),0);
        }

        msgrcv(qid,&w,sizeof(w.num),M_END,0);


    }

    return 0;
}