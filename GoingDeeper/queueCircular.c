#include <stdio.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int front, rear;
}Queue;

void init(Queue* q){
    q->front = q->rear = -1;
}

int isEmpty(Queue* q){return q->front == -1;}
int isFull(Queue* q){return (q->rear + 1) % MAX == q->front;}

void enqueue(Queue* q, int val){
    if(isFull(q)){
        printf("Queue full!\n");
        return;
    }
    if(isEmpty(q)){
        q->front = q->rear = 0;
    }else{
        q->rear = (q->rear + 1) % MAX;
        }
    q->data[q->rear] = val;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue Empty!\n");
        return -1;
    }
    int temp = q->data[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }else{
        q->front = (q->front + 1) % MAX;
    }
    return temp;
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
    int i = q->front;
    while(1){
        printf("%d ", q->data[i]);
        if(q->rear == i) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main(){
    Queue arrQueue;
    init(&arrQueue);

    int choice, input;
    char buffer[4];

    while(1){
        printf("Welcome to circular queue!\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print queue\n");
        printf("5. Exit\n");
        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &choice) != 1){
            printf("Invalid input!\n");
            continue;
        }
        switch(choice){
        case 1:
            printf("Enter value to enqueue: ");
            fgets(buffer, sizeof(buffer), stdin);
            if(sscanf(buffer, "%d", &input) != 1){
                printf("Invalid input, please re enter a valid number: \n");
                fgets(buffer, sizeof(buffer), stdin);
            }
            enqueue(&arrQueue, input);
            break;
        case 2:
            printf("%d\n", dequeue(&arrQueue));
            break;
        case 3:
            printf("%d\n", peek(&arrQueue));
            break;
        case 4:
            printQueue(&arrQueue);
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
    return 0;
}