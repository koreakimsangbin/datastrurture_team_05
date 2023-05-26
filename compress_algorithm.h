#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "compress_node.h"

TrieNode* createCompressedTrie(TrieNode* root) {
    TrieNode* compressedRoot = createNode();

    
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            TrieNode* node = createCompressedTrie(root->children[i]); 
            node->isEndOfWord = root->children[i]->isEndOfWord;
            compressedRoot->children[i] = node;
        }
    }

    if (root->word != NULL) {
        compressedRoot->word = (char*)malloc(strlen(root->word) + 1);
        strcpy(compressedRoot->word, root->word);
    }

    return compressedRoot;
}

void printTrie(TrieNode* root, int level) {
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    if (root->word != NULL)
        printf("%s\n", root->word);
    else
        printf("-\n");

    for (int i = 0; i < 26; i++) {
        printTrie(root->children[i], level + 1);
    }
}


