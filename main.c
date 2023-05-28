#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "trie.h"
#include "compress_algorithm.h"
#include "fix_text.h"
#include "huffman_coding.h"
#include "compress_node.h"

int main(int argc, const char * argv[]) {
    system("clear");
    TrieNode* root = createNode();

    char text[100000];       
    char title[100];

    
    printf("파일명을 작성하시오: ");
    fgets(title, sizeof(title), stdin);
    system("clear");
    
    saveOriginalTextToFile(strcat(title, ".txt"), text, root);
    TrieNode* compressedTrie = createCompressedTrie(root);

    char compressedText[100];
    //compressT(compressedTrie, text);
    //compressText(compressedTrie, text, compressedText);

    char* originalText = readOriginalTextFromFile(strcat(title, ".txt"));
    if (originalText != NULL) {
        printf("Original Text: %s\n", originalText);
        free(originalText);
    }
    system("clear");
    printTrie(compressedTrie, 0);

    return 0;
}
 
