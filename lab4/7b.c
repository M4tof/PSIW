#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) { // Child process 1 - ls -l
        close(pipe1[0]); // Close reading end of first pipe

        dup2(pipe1[1], STDOUT_FILENO); // Redirect stdout to the writing end of first pipe

        execlp("ls", "ls", "-l", NULL);

        close(pipe1[1]); // Close writing end of first pipe
    } 
    else {
        pid2 = fork();
        
        if (pid2 == 0) {// Child process 2 - grep ^t
            close(pipe1[1]); // Close writing end of first pipe
            dup2(pipe1[0], STDIN_FILENO); // Redirect stdin to the reading end of first pipe
            
            close(pipe1[0]); // Close reading end of first pipe
            close(pipe2[0]); // Close reading end of second pipe

            dup2(pipe2[1], STDOUT_FILENO); // Redirect stdout to the writing end of second pipe
            close(pipe2[1]); // Close writing end of second pipe

            execlp("grep", "grep", "^t", NULL);
        } 
        else {// Parent process
            close(pipe1[0]); // Close unused ends of pipes
            close(pipe1[1]);
            close(pipe2[1]);

            dup2(pipe2[0], STDIN_FILENO); // Redirect stdin to the reading end of second pipe
            close(pipe2[0]); // Close reading end of second pipe

            execlp("more", "more", NULL);
        }
    }

    return 0;
}
