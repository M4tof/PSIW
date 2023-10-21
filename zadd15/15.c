#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 1024

void searchForChain(int desc, char *chain, const char *filename) {

}

int main(int argc, char *argv[]) {
    char *searchChain = argv[1];

    for (int i = 2; i < argc; i++) {
        int origin = open(argv[i], O_RDWR);
        searchForChain(origin, searchChain, argv[i]);
        close(origin);
    }
    return 0;
}
