#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "trie.h"
#include "compress_algorithm.h"
#include "fix_text.h"
#include "huffman_coding.h"

int main(int argc, const char * argv[]) {
    system("clear");
    TrieNode* root = createNode();

    char text[100];       
    char title[100];

    
    TrieNode* compressedTrie = createCompressedTrie(root);

    FILE *file = fopen("original.txt", "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

     while (1) {
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';  // 개행 문자 제거

        if (strcmp(text, "q") == 0) {
            break;
        }
        fprintf(file, "%s\n", text);
        insertWord(root, text);
    }

   
    char compressedText[100];
    compressText(compressedTrie, text, compressedText);

    
    saveOriginalTextToFile("original.txt", text);

    
    char* originalText = readOriginalTextFromFile("original.txt");
    if (originalText != NULL) {
        printf("Original Text: %s\n", originalText);
        free(originalText);
    }

   

    system("clear");
    return 0;
}
 
