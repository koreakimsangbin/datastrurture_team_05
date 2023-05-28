#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "trie.h"
#include "compress_algorithm.h"
#include "fix_text.h"

int main(int argc, const char * argv[]) {
    system("clear");
    TrieNode* root = createNode();

    char text[100000];       
    char title[100];

    
    TrieNode* compressedTrie = createCompressedTrie(root);
    printf("파일명을 작성하시오: ");
    fgets(title, sizeof(title), stdin);
    system("clear");
    
    saveOriginalTextToFile(strcat(title, ".txt"), text, root);
   
    char compressedText[100];
    compressText(compressedTrie, text, compressedText);

    char* originalText = readOriginalTextFromFile(strcat(title, ".txt"));
    if (originalText != NULL) {
        printf("Original Text: %s\n", originalText);
        free(originalText);
    }

    system("clear");

    showAllWords(root);
    return 0;
}
 
