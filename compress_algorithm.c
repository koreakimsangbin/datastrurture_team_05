#include "compress_algorithm.h"

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

