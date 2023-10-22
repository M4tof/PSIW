#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 1024

void searchForChain(const char *chain, const char *filename) {
    int line = 1;
    int chainstart = 0;
    int origin = open(filename, O_RDWR);

    char buf;
    int correct = 1;
    int start = 0;
    char currentChainChar;

    while (read(origin, &buf, 1) > 0) {
        chainstart++;
        if (buf == '\n') {
            line++;
            chainstart = 0;
        }

        if (correct && buf == chain[start]) {
            if (start == 0) {
                currentChainChar = buf;
            }

            start++;

            if (start == strlen(chain)) {
                printf("Chain '%s' was found in file %s on line %d beginning at character %d\n", chain, filename, line, chainstart - strlen(chain)+1);
                start = 0;
                correct = 1;
            }
        } 
        
        else {
            start = 0;
            correct = 1;
        }
    }

    close(origin);
}

int main(int argc, char *argv[]) {
    const char *searchChain = argv[1];

    for (int i = 2; i < argc; i++) {
        searchForChain(searchChain, argv[i]);
    }

    return 0;
}
