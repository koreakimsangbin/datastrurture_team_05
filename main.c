#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "compress_trie.h"

int main(int argc, const char * argv[]) {
    system("clear");
    TrieNode* root = createNode('\0');
    char node_word[100];
    char title[100];

    while (scanf("%s", node_word) == 1) {
        if (strcmp(node_word, "q") == 0) {
            printf("파일 명을 입력하시오: ");   
            scanf("%s", title);
            break;
        }
        insert(root, node_word);
    }

    FILE* file = fopen(strcat(title, ".txt"), "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char sentence[100];
    save_file(root, file, sentence, 0);
    fclose(file);

    printf("Word list saved to 'word_list.txt'.\n");

    system("clear");
    return 0;
}
 
