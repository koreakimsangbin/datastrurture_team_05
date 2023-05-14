#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TRIE_H
#define TRIE_H

typedef struct TrieNode {
    struct TrieNode* children[26];  // 알파벳 소문자를 저장하기 위한 배열
    int isEndOfWord;  // 단어의 끝을 표시하는 플래그
} TrieNode;

// 트라이 노드 생성 및 초기화
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;

    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }

    return node;
}

// 트라이에 단어 삽입
void insertWord(TrieNode* root, char* word) {
    TrieNode* node = root;

    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';  // 알파벳을 인덱스로 변환

        if (!node->children[index]) {
            node->children[index] = createNode();
        }

        node = node->children[index];
    }

    node->isEndOfWord = 1;
}

#endif