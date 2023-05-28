#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

void compressText(TrieNode* trie, char* originalText, char* compressedText);
void saveOriginalTextToFile(const char* filename, char* text, TrieNode* root);
char* readOriginalTextFromFile(const char* filename);