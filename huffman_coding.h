#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PriorityQueueNode {
    char data;
    int frequency;
    struct PriorityQueueNode* next;
} PriorityQueueNode;

// 우선순위 큐에 새 노드 삽입
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

// 우선순위 큐에서 노드 제거
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