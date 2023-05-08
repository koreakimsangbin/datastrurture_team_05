#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "save.h"

int main(int argc, const char * argv[]) {
    system("clear");
    char *filename;
    int row = 10000;
    int column = 10000;
    char quit[] = "q";
    int a = 0;
    int b = 0;
    char **voca;
    voca = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++) {
        voca[i] = (char*)malloc(column * sizeof(char));    
    }
    
    int num = 0;
    while(1) {
        scanf("%c", &voca[a][b]);
        if (voca[a][b] == 'q'){
                printf("저장할 파일 이름: ");
                filename = malloc(sizeof(char) * 100);
                fgets(filename, 100, stdin);
                save_to_file(filename, voca); 
                free(filename); 
                break;
        }
        else if (voca[a][b] == '\n') {
            a++;
            b = -1;
        }
        b++;
    }
    

    free(voca);
    system("clear");
    return 0;
}
 
