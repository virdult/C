#include <stdio.h>

typedef struct{
    int data;
    int front, rear;
}Queue;

int isEmpty(Queue* q){return q->front == -1;}