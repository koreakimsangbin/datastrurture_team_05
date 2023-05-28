#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "compress_node.h"

TrieNode* createCompressedTrie(TrieNode* root) {
    TrieNode* compressedRoot = createNode();
    

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


