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

struct msgb{
    long t;
    char msg[8];
};

int main(){
    key_t qid = msgget(1234,IPC_CREAT|0640);

    int adr = fork();

    if(adr!=0){
        struct msgb w2;
        msgrcv(qid,&w2,8,5,0);

        printf("%s\n",w2.msg);
    }

    else{
        struct msgb w;
        w.t = 5;
        strcpy(w.msg,"Hello\0");

        msgsnd(qid,&w,8,0);
    }

    return 0;
}