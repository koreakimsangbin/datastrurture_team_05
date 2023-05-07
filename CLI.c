#include <stdio.h>
#include<stdlib.h>
#include <string.h>
//char *sentance;

int main(int argc, const char * argv[]) {
    // insert code here��
    system("clear");
    char quit[] = "q";
    char **voca;
    voca = malloc(sizeof(char)*10000);
    int num = 0;
    while(1) {
        voca[num] = malloc(sizeof(char) * 100);
        scanf("%s", voca[num]);
        getchar();
        if (strcmp(voca[num], quit) == 0)
                break;
        num++;
    }
    free(voca);
    system("clear");
    return 0;
}
