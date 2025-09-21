/*Queue rotation. Write a function that rotates a queue by k steps to the left or right.
Implement this for array-based queue and/or linked-list circular queue.
Do not create a new queue; modify the original queue in-place if possible.
Consider the cases where k > size of the queue.
After rotation, the queue must preserve the order of remaining elements.
Optional: Make it work for both left and right rotation with just one function.*/
//I will not make both sides since it requires doubly ll. It's same logic, just going back instead of forward.
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
        q->front = q->rear = newNode;
        newNode->next = newNode;
    }else{
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
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

int peek(Queue* q){
    if(isEmpty(q)) return -1;
    return q->front->data;
}

void printQueue(Queue* q){
    Node* current = q->front;
    while(1){
        printf("%d", current->data);
        if(current == q->rear) break;
        current = current->next;
    }
    printf("\n");
}

void rotateQueue(Queue* q, int k){
    while(k > 0){
        q->rear = q->front;
        q->front = q->front->next;
        k--;
    }
}//To be able to rotate from other side, I need a doubly linked list.(I guess)

int main(){
    Queue q1;
    initQueue(&q1);

    int choice, input, valid;
    char buffer[16];

    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Rotate Queue\n");
        printf("6. Exit\n");

        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &choice) != 1){
            printf("Invalid input.\n");
            continue;
        }
        switch(choice){
        case 1:
            valid = 0;
            while(!valid){
                printf("Enter number to enqueue: ");
                fgets(buffer, sizeof(buffer), stdin);
                if(sscanf(buffer, "%d", &input) == 1){
                    valid = 1;
                }else{
                    printf("Invalid input! Please enter an integer.\n");
                }
            }
            enqueue(&q1, input);
            break;
        case 2:
            printf("Dequeued: %d\n", dequeue(&q1));
            break;
        case 3:
            printf("Front: %d\n", peek(&q1));
            break;
        case 4:
            printQueue(&q1);
            break;
        case 5:
            valid = 0;
            while(!valid){
                printf("Enter the amount of rotate: ");
                fgets(buffer, sizeof(buffer), stdin);
                if(sscanf(buffer, "%d", &input) == 1){
                    valid = 1;
                }else{
                    printf("Invalid input! Please enter an integer.\n");
                }
            }
            rotateQueue(&q1, input);
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
    return 0;
}