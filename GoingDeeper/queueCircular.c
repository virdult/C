#include <stdio.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int front, rear;
}Queue;
/*These don't feel right for a circular but I'll think about them a little while later.*/
int isEmpty(Queue* q){
    //I thought of what if queue is actually empty on index n? What should I do, but I'll just reset queue if queue gets emptied with dequeue.
    if(q->front == q->rear && q->front != -1){
        return 0;
    }else{
        q->front = 0;
        return 1;
    }
}
int isFull(Queue* q){
    if(q->rear + 1 == q->front){return 1;}
    if(q->rear == MAX - 1){
        if(q->front == 0){
            return 1;
        }else{
            q->rear = -1;
        }
    }
    return 0;
}

void enqueue(Queue* q, int val){
    if(isFull(q)){
        printf("Queue is full. Can not add!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = val;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty. Can not dequeue!\n");
        return -1;
    }
    int out = q->data[q->front];
    if(q->front == MAX - 1 && q->rear != MAX -1){
        q->front = 0;
    }else if(q->front == q->rear){
        q->front = q->rear = -1;
    }else{
        q->front++;
    }
    return out;
}