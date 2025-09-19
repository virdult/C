#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}QueueCircular;

void initQueue(QueueCircular* q){
    q->front = q->rear = NULL;
}

int isEmpty(QueueCircular* q){return q->front == NULL;}

void enqueue(QueueCircular* q, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Malloc failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if(q->front == NULL){
        q->front = q->rear = newNode;
        newNode->next = newNode;
    }else{
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(QueueCircular* q){
    if(isEmpty(q)){
        printf("Queue is empty! Dequeue failed!\n");
        return -1;
    }
    if(q->front == q->rear){
        int val = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
        return val;
    }
    Node* temp = q->front;
    q->front = temp->next;
    q->rear->next = q->front;
    int out = temp->data;
    free(temp);
    return out;
}

int peek(QueueCircular* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

void printQueue(QueueCircular* q){
    if(isEmpty(q)){
        printf("Queue is empty! Nothing to print!\n");
        
    }else{
        Node* temp = q->front;
        while(1){
            printf("%d ", temp->data);
            if(temp == q->rear) break;
            temp = temp->next;
            }
        /*
        Node* temp = q->front;
        do{
            printf("%d ", temp->data);
            temp = temp->next;
            }while(temp != q->front);
        */
    }
    printf("\n");
}

void clearMemo(QueueCircular* q) {
    if(isEmpty(q)) return;

    Node* current = q->front;
    Node* nextNode;

    while(current != q->rear){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(q->rear);

    q->rear = q->front = NULL;//initQueue(q); -> I couldn't know if I should use this here.
}

int main(){
    QueueCircular llQueue;
    initQueue(&llQueue);

    int choice, input;
    char buffer[12];

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
            int valid = 0;
            while(!valid){
                printf("Enter the element to be enqueued: ");
                fgets(buffer, sizeof(buffer), stdin);
                if (sscanf(buffer, "%d", &input) == 1) {
                    valid = 1;
                }else{
                    printf("Invalid input! Please enter a number.\n");
                }
            }
            enqueue(&llQueue, input);
            break;
        case 2:
            printf("%d\n", dequeue(&llQueue));
            break;
        case 3:
            printf("%d\n", peek(&llQueue));
            break;
        case 4:
            printQueue(&llQueue);
            break;
        case 5:
            clearMemo(&llQueue);
            return 0;
        default:
            break;
        }
    }


    return 0;
}