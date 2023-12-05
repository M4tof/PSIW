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

struct msgb{
    long t;
    char msg[8];
};

int main(){
    key_t qid = msgget(1234,IPC_CREAT|0640);

    int adr = fork();

    if(adr!=0){     //Server
        struct msgb w2;
        msgrcv(qid,&w2,8,1,0);

        char tmp[8];
        strcpy(tmp,w2.msg);

        for(int i=0;tmp[i];i++){
            tmp[i] = toupper(tmp[i]);
        }

        strcpy(w2.msg,tmp);

        w2.t = 2;
        msgsnd(qid,&w2,8,0);
    }

    else{           //Klient
        struct msgb w;
        w.t = 1;
        strcpy(w.msg,"HelLO\0");
        msgsnd(qid,&w,8,0);

        msgrcv(qid,&w,8,2,0);
        printf("%s\n",w.msg);
    }

    return 0;
}