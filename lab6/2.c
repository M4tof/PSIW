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

    if(adr!=0){     //Odbiornik
        struct msgb w2;
        msgrcv(qid,&w2,8,2,0);
        printf("%s\n",w2.msg);

        msgrcv(qid,&w2,8,1,0);
        printf("%s\n",w2.msg);
    }

    else{           //Wysłaniec
        struct msgb w;
        w.t = 1;
        strcpy(w.msg,"Hello\0");
        msgsnd(qid,&w,8,0);

        w.t = 2;
        strcpy(w.msg,"olleH\0");
        msgsnd(qid,&w,8,0);
    }

    return 0;
}