#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void save_to_file(const char *filename, const char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("파일을 저장하는데 오류가 발생했습니다: %s\n", filename);
        return;
    }

    fputs(text, file);
    fclose(file);
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    char *text = NULL;
    size_t text_len = 0;

    printf("텍스트를 입력하세요 (여러 줄 입력 가능, 끝내려면 스페이스바를 두 번 누르고 엔터):\n");

    while (fgets(buffer, MAX_LINE_LENGTH, stdin) != NULL) {
        if (strcmp(buffer, "  \n") == 0) {
            break;
        }

        size_t buffer_len = strlen(buffer);
        text = (char *)realloc(text, text_len + buffer_len + 1);
        if (text == NULL) {
            printf("메모리를 할당하는데 실패했습니다.\n");
            return 1;
        }

        strcpy(text + text_len, buffer);
        text_len += buffer_len;
    }

    if (text != NULL) {
        printf("파일 이름을 입력하세요 (예: newfile.txt):\n");
        scanf("%1023s", buffer);

        save_to_file(buffer, text);
        free(text);

        printf("파일이 저장되었습니다: %s\n", buffer);
    } else {
        printf("텍스트를 입력하지 않았습니다.\n");
    }

    return 0;
}
