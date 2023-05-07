#include <stdio.h>
#include "input.h"

void *input() {
    char buffer[MAX_LENGTH];
    char *text = NULL;
    size_t text_len = 0;

    printf("텍스트를 입력하세요 (여러 줄 입력 가능, 끝내려면 스페이스바를 두 번 누르고 엔터):\n");

    while (fgets(buffer, MAX_LENGTH, stdin) != NULL) {
        if (strcmp(buffer, "  \n") == 0) {
            break;
        }

        size_t buffer_len = strlen(buffer);
        text = (char *)realloc(text, text_len + buffer_len + 1);
        if (text == NULL) {
            printf("메모리를 할당하는데 실패했습니다.\n");
            exit(1);
        }

        strcpy(text + text_len, buffer);
        text_len += buffer_len;
    }
}
