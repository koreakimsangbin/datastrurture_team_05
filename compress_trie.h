#include <stdio.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode* Children_point[26]; 
    int end_point; 
} TrieNode;

TrieNode* createNode() {
    TrieNode* trie_node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        trie_node->Children_point[i] = NULL;
    }
    trie_node->end_point = 0;
    return trie_node;
}

