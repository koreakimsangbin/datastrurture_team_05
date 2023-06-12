#include "search.h"

void search(TrieNode *root, char* word) {
    TrieNode* currentNode = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';

        if (currentNode->children[index] == NULL) {
            // 해당 글자에 대한 자식 노드가 없는 경우
            printf("단어가 존재하지 않습니다.\n");
            return;
        }

        currentNode = currentNode->children[index];
    }

    if (currentNode->isEndOfWord) {
        printf("단어가 존재합니다.\n");
    } else {
        printf("단어가 존재하지 않습니다.\n");
    }
} 