#ifndef Autocomplete_h
#define Autocomplete_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_trie.h"
#define ALPHABET 26

typedef struct AutoComplete {
    TrieNode* root;
} AutoComplete;

void autocomplete(AutoComplete* ac, char* word);
void find_words(TrieNode* node, char* word, int level);
