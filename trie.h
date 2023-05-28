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


TrieNode* return_root(TrieNode* root) {
    return root;
}


void insertWord(TrieNode* root, char* word) {
    TrieNode* wordNode = root;
    while (*word != '\0') {
        if (*word >= 'A' && *word <= 'Z') {
            *word += 32;
        }
        if ((*word - ' ') == 0) {
            word++;
            continue;
        }
        if (wordNode->children[*word - 'a'] == NULL) {
            wordNode->children[*word - 'a'] = createNode();
        }

        wordNode = wordNode->children[*word - 'a'];

        word++;
    }
    wordNode->isEndOfWord = 1;   
}

int search(struct TrieNode* root, char* word)
{
    if (root == NULL) {
        return 0;
    }
 
    struct TrieNode* wordNode = root;
    while (*word != '\0')
    {
        wordNode = wordNode->children[*word - 'a'];
         if (wordNode == NULL) {
            return 0;
        }
         word++;
    }
    return wordNode->isEndOfWord;
}
#endif