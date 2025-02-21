#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: the file can't be open\n", argv[1]);
        return -1;
    }
    fclose(file);

    char cmd[BUFSIZE];
    int limited = snprintf(cmd, BUFSIZE, "wc -c < \"%s\"", argv[1]);
    if (limited < 0 || limited >= BUFSIZE) {
        fprintf(stderr, "Error: the file path is too long.\n");
        return -1;
    }
    system(cmd);
}
