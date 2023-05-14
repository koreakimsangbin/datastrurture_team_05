#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TRIE_H
#define TRIE_H

typedef struct TrieNode {
    struct TrieNode* children[26];  
    int isEndOfWord;  
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;

    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insertWord(TrieNode* root, char* word) {
    TrieNode* node = root;

    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';  

        if (!node->children[index]) {
            node->children[index] = createNode();
        }

        node = node->children[index];
    }

    node->isEndOfWord = 1;
}

#endif