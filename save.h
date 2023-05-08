#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void save_to_file(char *filename, char **text) {
    FILE *file = fopen(strcat(filename,".txt"), "wt");
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++)
            fprintf(file, "%c", text[i][j]);
    }
    fclose(file);
    printf("finish");
}

