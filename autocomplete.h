#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_trie.h"
#define ALPHABET 26

typedef struct AutoComplete {
    TrieNode* root;
} AutoComplete;

void autocomplete(AutoComplete* ac, char* word){
    TrieNode* node = ac->root;
    char c;
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        c = word[i];
        if(word[i] == NULL){
            return;
        }
        

    }
}
