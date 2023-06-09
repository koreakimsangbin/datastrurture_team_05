#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "search.h"
#include "trie.h"
#ifndef FIX_TEXT
#define FIX_TEXT

void compressText(TrieNode* trie, char* originalText, char* compressedText);
void saveOriginalTextToFile(const char* filename, char* text, TrieNode* root);
char* readOriginalTextFromFile(const char* filename);

#endif 