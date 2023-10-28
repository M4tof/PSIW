#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 1024

void formatFile(const int key, const char *filename) {
    int origin = open(filename, O_RDWR);


    close(origin);
}

int main(int argc, char *argv[]) {

    for (int i = 2; i < argc; i++) {
        formatFile(argv[1],argv[i]);
    }

    return 0;
}
