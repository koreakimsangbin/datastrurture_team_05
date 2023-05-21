#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

/*
TrieNode* createCompressedTrie(TrieNode* root) {
    TrieNode* compressedRoot = createNode();

    
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            TrieNode* node = createNode();
            node->isEndOfWord = root->children[i]->isEndOfWord;
            compressedRoot->children[i] = node;
        }
    }

     for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            compressedRoot->children[i] = createCompressedTrie(root->children[i]);
        }
    }

    return compressedRoot;
}
*/

//try_1
char* compressT(TrieNode* root, char* string) {
    TrieNode* R = root;
    int length = strlen(string);
    char* compressed_string = (char*)malloc(length * 2 * sizeof(char) + 1);
    int index = 0;

    for (int i = 0; i < length; i++) {
        int count = 1; 
        compressed_string[index++] = string[i];
        if (string[i] == string[i + 1]){
        while (i + 1 < length && string[i] == string[i + 1]) {
            i++;
            count++;
        }

        char count_str[10]; // 숫자 더하기
        sprintf(count_str, "%d", count); // 숫자 더하기
        for (int j = 0; j < strlen(count_str); j++) { // 숫자 더하기
            compressed_string[index++] = count_str[j]; // 숫자 더하기
        }
        }
    }
    compressed_string[index] = '\0';
    return compressed_string;
}
