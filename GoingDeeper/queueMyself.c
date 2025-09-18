/*I read what a queue is. Now I'll see if I can create one.*/

#include <stdio.h>
#define MAX 100

typedef struct{
    int data[MAX];
    int front, rear;
}Queue;

int isEmpty(Queue* q){return q->front == -1;}
int isFull(Queue* q){return q->rear == MAX - 1;}

void enqueue(Queue* q, int val){
    if(isFull(q)){
        printf("Queue full!\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
    }
    q->data[++(q->rear)] = val;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty. Nothing to dequeue!\n");
        return -1;
    }
    int val = q->data[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front++;
    }
    return val;
}

int peek(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

void printQueue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main(){
    Queue arrQueue;
    arrQueue.front = -1;
    arrQueue.rear = -1;

    int choice, input;
    char buffer[4];

    while(1){
        printf("Welcome to queue test program!\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print queue\n");
        printf("5. Exit\n");

        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &choice) != 1){
            printf("Invalid input! Please enter a number between 1-5: \n");
            fgets(buffer, sizeof(buffer), stdin);
        }
        switch(choice){
        case 1:
            fgets(buffer, sizeof(buffer), stdin);
            if(sscanf(buffer, "%d", &input) != 1){
                printf("Invalid entry!\n");
                continue;
            }
            enqueue(&arrQueue, input);
            break;
        case 2:
            printf("%d \n", dequeue(&arrQueue));
            break;
        case 3:
            printf("%d \n", peek(&arrQueue));
            break;
        case 4:
            printQueue(&arrQueue);
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}