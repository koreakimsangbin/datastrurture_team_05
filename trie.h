#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TRIE_H
#define TRIE_H

typedef struct TrieNode {
    struct TrieNode* children[26];  
    int isEndOfWord;  
} TrieNode;
TrieNode* createNode();
void insertWord(TrieNode* root, char* word);
void showNode(TrieNode* node, char* prefix, int level);
void showAllWords(TrieNode* root);
#endif
