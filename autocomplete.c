#include "autocomplete.h"

void autocomplete(TrieNode* root, char* partial) {
    TrieNode* curr = root;
    int len = strlen(partial);

    for (int i = 0; i < len; i++) {
        int index = partial[i] - 'a';
        if (curr->children[index] == NULL) {
            return;
        }
        curr = curr->children[index];
    }

    char completed_word[100];
    strcpy(completed_word, partial);
    find_words(curr, completed_word, len);
}

void find_words(TrieNode* node, char* word, int level) {
    if (node->end_point) {
        printf("%s\n", word);
    }

    for (int i = 0; i < ALPHABET; i++) {
        if (node->children[i] != NULL) {
            word[level] = node->children[i]->character;
            word[level + 1] = '\0';
            find_words(node->children[i], word, level + 1);
        }
    }
}