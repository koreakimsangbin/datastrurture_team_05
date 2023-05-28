#include "trie.h"

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
    for (int i = 0; i < length; ) {
        for (; i < length ; i++) {
            if (*word >= 'A' && *word <= 'Z') {
                *word += 32;
            }   
            if (word[i] == ' ') {
                i++;
                break;
            }
            
            int index = word[i] - 'a';
            
            if (!node->children[index]) {
                node->children[index] = createNode();
            }
            
            node = node->children[index];
        }
        
        node->isEndOfWord = 1;
        node = root;
    }
}


void showNode(TrieNode* node, char* prefix, int level) {
    if (node->isEndOfWord) {
        prefix[level] = '\0';  
        printf("%s\n", prefix);
    }

    
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            prefix[level] = 'a' + i;  
            showNode(node->children[i], prefix, level + 1);  
        }
    }
}   

void showAllWords(TrieNode* root) {
    char prefix[100000];  
    showNode(root, prefix, 0);

}