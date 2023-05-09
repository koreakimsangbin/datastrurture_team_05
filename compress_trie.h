#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET];
    char character;
    int end_point;
} TrieNode;

TrieNode* createNode(char character) {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET; i++) {
        node->children[i] = NULL;
    }
    node->character = character;
    node->end_point = 0;
    return node;
}

void node_insert(TrieNode* root, char* word) {
    TrieNode* curr = root;
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = createNode(word[i]);
        }
        curr = curr->children[index];
    }

    curr->end_point = 1;
}

void save_file(TrieNode* root, FILE* file, char* sentence, int level) {
    if (root == NULL) {
        return;
    }

    sentence[level] = root->character;
    if (root->end_point) {
        sentence[level + 1] = '\0';
        fprintf(file, "%s\n", sentence);
    }

    for (int i = 0; i < ALPHABET; i++) {
        save_file(root->children[i], file, sentence, level + 1);
    }
}
