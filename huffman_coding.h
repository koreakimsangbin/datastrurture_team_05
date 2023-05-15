#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PriorityQueueNode {
    char data;
    int frequency;
    struct PriorityQueueNode* next;
} PriorityQueueNode;


void enqueue(PriorityQueueNode** queue, char data, int frequency) {
    PriorityQueueNode* newNode = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->next = NULL;

    if (*queue == NULL) {
        *queue = newNode;
    } else if (frequency <= (*queue)->frequency) {
        newNode->next = *queue;
        *queue = newNode;
    } else {
        PriorityQueueNode* current = *queue;
        while (current->next != NULL && frequency > current->next->frequency) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}


char dequeue(PriorityQueueNode** queue) {
    if (*queue == NULL) {
        return '\0';
    }

    PriorityQueueNode* temp = *queue;
    char data = temp->data;
    *queue = (*queue)->next;
    free(temp);

    return data;
}

//트라이랑 허프만이랑 결이 달라서 같이 사용하기는 힘들 것 같다. 어처피 압축 트라이를 사용하니 의미가 없다.