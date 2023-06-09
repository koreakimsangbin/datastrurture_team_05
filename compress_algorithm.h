#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "search.h"

#ifndef COMPRESS_ALGORITHM
#define COMPRESS_ALGORITHM

TrieNode* createCompressedTrie(TrieNode* root);

#endif