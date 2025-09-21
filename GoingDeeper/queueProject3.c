/*Queue rotation. Write a function that rotates a queue by k steps to the left or right.
Implement this for array-based queue and/or linked-list circular queue.
Do not create a new queue; modify the original queue in-place if possible.
Consider the cases where k > size of the queue.
After rotation, the queue must preserve the order of remaining elements.
Optional: Make it work for both left and right rotation with just one function.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

void initQueue(Queue* q){
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q){return q->front == NULL;}

void enqueue(Queue* q, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return;
    newNode->data = val;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = q->rear = 0;
        newNode->next = newNode;
    }else{
        newNode->next = q->front;
        q->rear->next = newNode;
    }
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    Node* temp = q->front;
    int out = temp->data;
    if(q->front == q->rear){
        initQueue(q);
    }else{
        q->front = temp->next;
        q->rear->next = q->front;
    }
    free(temp);
    return out;
}

int* peek(Queue* q){//Finally figured out what do do. Use this from now on!
    if(isEmpty(q)) return NULL;
    return q->front;
}