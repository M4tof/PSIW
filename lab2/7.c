#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int desc_zrod = open(argv[1], O_WRONLY | O_CREAT);
    int stdout = dup(1);

    dup2(desc_zrod, 1);
    close(desc_zrod);

    execlp("ps", "ps", "ax", NULL);

    dup2(stdout, 1);  
    close(stdout);

    return 0;
}
