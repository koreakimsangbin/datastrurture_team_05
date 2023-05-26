#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TRIE_H
#define TRIE_H

typedef struct TrieNode {
    struct TrieNode* children[26];  
    char* word;
    int isEndOfWord;  
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;

    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->word = NULL;
    return node;
}



void insertWord(TrieNode* root, char* word) {
    int num =0;
    int i = 0;
    char* as = strtok(word, " ");
    while (as != NULL) {
        TrieNode* wordNode = createNode();

        wordNode->word = (char*)malloc(strlen(as) + 1);
        strcpy(wordNode->word, as);
        root->children[num] = wordNode;
        num++;

        as = strtok(NULL, " ");
    }
    root->isEndOfWord = 1;    
}

#endif