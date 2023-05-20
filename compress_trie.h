#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"

char* compressT(struct TrieNode* root, char* string) {
    struct TrieNode* R = root;
    int count = 0;
    int length = sizeof(string);
    char* compressed_string = (char*)malloc(length * 2 * sizeof(char));
    int index = 0;


    for (int i = 0; i < length; i++) {
        for (int j = 'A'; j <= 'Z'; j++) {
            if (string[i] == string[i + 1])
                count++;
        }
        if (count == 0)
            compressed_string[index++] = string[i];
        //return string;
        else
            compressed_string[index++] = strcat(string[i], (char)count);

        compressed_string[index] = '\0';
        return compressed_string;
    }
}