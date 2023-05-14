#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"

int search(TrieNode *root, const char *word) {
    int length = strlen(word);
    TrieNode *sear = root;
    for (int level = 0; level < length; level++) {
        int index = ((int)word[level] - (int)'a');
        if (!sear->children[index])
            return 0;
        sear = sear->children[index];
    }
    return (sear != NULL && sear->end_point) ? sear->count : 0;
}
