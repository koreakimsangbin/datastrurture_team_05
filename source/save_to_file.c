#include <stdio.h>
#include <stdlib.h>

#include "save_to_file.h"
#include "input.h"

void save_to_file(const char *filename, const char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("파일을 저장하는데 오류가 발생했습니다: %s\n", filename);
        exit(-1);
    }

    fprintf(file, "%s", text);
    fclose(file);
}

void name() {
    char buffer[MAX_LENGTH];
    char *text = NULL;
    if (text != NULL) {
        printf("파일 이름을 입력하세요 (예: newfile.txt):\n");
        fgets(buffer, MAX_LENGTH, stdin);

        save_to_file(buffer, text);
        free(text);

        printf("파일이 저장되었습니다: %s\n", buffer);
    } else {
        printf("텍스트를 입력하지 않았습니다.\n");
    }
}
 
