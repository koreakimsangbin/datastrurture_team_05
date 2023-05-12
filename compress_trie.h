#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALP 30

struct TrieNode {
    int word_end;
    struct TrieNode *child[MAX_ALP];
};

struct CompressedTrie {
    struct TrieNode *root;
};

struct TrieNode *create_trie_node(void) {
    struct TrieNode *node = NULL;
    node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (node) {
        node->word_end = 0;
        for (int i = 0; i < MAX_ALP; i++)
            node->child[i] = NULL;
    }
    return node;
}

struct CompressedTrie *create_compressed_trie(void) {
    struct CompressedTrie *trie = NULL;
    trie = (struct CompressedTrie *)malloc(sizeof(struct CompressedTrie));
    if (trie)
        trie->root = create_trie_node();
    return trie;
}

void insert(struct CompressedTrie *trie, char *key) {
    int length = strlen(key);
    int index;
    struct TrieNode *node = trie->root;

    for (int level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (!node->child[index]) {
            node->child[index] = create_trie_node();
        }
        node = node->child[index];
    }
    node->word_end = 1;
}

int search(struct CompressedTrie *trie, char *key) {
    int length = strlen(key);
    int index;
    struct TrieNode *node = trie->root;

    for (int level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (!node->child[index])
            return 0;
        node = node->child[index];
    }
    
    return (node != NULL && node->word_end);
}

int main(void) {
    struct CompressedTrie *trie = create_compressed_trie();

    char keys[][8] = {"apple", "banana", "grape", "orange", "hypeboy", "newjeans"};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        insert(trie, keys[i]);

    printf("%s", search(trie, "hypeboy") ? "Yes" : "No");
    printf("\n");
    printf("%s", search(trie, "pepsi") ? "Yes" : "No");
    return 0;
}
