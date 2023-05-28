#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

void search(TrieNode *root, char* text) {
    TrieNode *search = root;
    int err;

    for (int i = 0; i < strlen(text); i++) {
        int index = text[i] - 'a';
        if (search->children[index]!=NULL) {
            search = search->children[index];
        }
        else {
            err++;
            break;
        }
    }
    if (err==1) {
        printf("'%s'이 단어는 존재하지 않습니다.\n", text);
    }
    else {
        printf("'%s'이 단어는 총 '%d'개 존재합니다.\n", text, search->count);
    }
} //수정 필요
