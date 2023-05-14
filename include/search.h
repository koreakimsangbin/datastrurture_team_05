#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_trie.h"

int search(TrieNode *root, const char *word);

#endif
