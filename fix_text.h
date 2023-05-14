#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

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

void saveOriginalTextToFile(const char* filename, char* text) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "%s", text);

    fclose(file);
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