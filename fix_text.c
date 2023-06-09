#include "fix_text.h"


void compressText(TrieNode* trie, char* originalText, char* compressedText) {
    int compressedIndex = 0;

    TrieNode* currentNode = trie;
    for (int i = 0; originalText[i] != '\0'; i++) {
        int index = originalText[i] - 'a';  

        if (currentNode->children[index]) {
            compressedText[compressedIndex] = originalText[i];
            compressedIndex++;
            currentNode = currentNode->children[index];
        }
    }

    compressedText[compressedIndex] = '\0';
}

void saveOriginalTextToFile(const char* filename, char* text, TrieNode* root) {
    char *a = (char*)malloc(sizeof(char) * 100);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
    }

     while (1) {
        fgets(text, sizeof(text) + 100, stdin); //sizeof(text)가 일정 갯수 밖에 못 받아서 일단 임시 방편으로 +100으로 시도해보니 성공했다.
        text[strcspn(text, "\n")] = '\0';  // 개행 문자 제거

        if (strcmp(text, "q") == 0) {
            break;
        }

        if (strcmp(text, "f") == 0) {
            printf("찾을 단어를 입력하시오: ");
            scanf("%s", a);
            search(root, a);
            sleep(10);
            free(a);

            break;
        }

        fprintf(file, "%s\n", text);
        insertWord(root, text);
    }
}



char* readOriginalTextFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* text = (char*)malloc((size + 1) * sizeof(char));
    fread(text, sizeof(char), size, file);
    text[size] = '\0';

    fclose(file);

    return text;
}