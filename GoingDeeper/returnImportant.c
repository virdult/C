/*When I want to return a value from dequeue/pop or peek/top, if I try to check isEmpty in those functions and
if the queue/stack is actually empty, then I need to return a val which can be mislead because that value might 
be inside the queue/stack originally as well. So, I thought of 2 things I can pass this with and I'll code them
in here.
1: Make a struct to depo if isEmpty succeeds and call that struct in the main function when calling these functions.
2: Don't even put isEmpty functions in the dequeue/pop and peek/top, but check the isEmpty before you call these
functions in main script.

I guess making a struct makes more sense for bigger projects yet for small cases, I can just code the second way
myself. Because only I will see the code anyway.*/
/*
// 1:
#include <stdio.h>
#define MAX 8

typedef struct{
    int stack[MAX];
    int top;
}Stack;

typedef struct{
    int success;
    int val;
}Result;

void initStack(Stack* s){
    s->top = -1;
}

int isEmpty(Stack* s){return s->top == -1;}
int isFull(Stack* s){return s->top == MAX - 1;}

void push(Stack* s, int val){
    if(isFull(s)) return;
    s->stack[++s->top] = val;
}

Result pop(Stack* s){
    Result res;
    if(isEmpty(s)){
        res.success = 0;
        return res;
    }
    res.success = 1;
    res.val = s->stack[s->top--];
    return res;
}

Result peek(Stack* s){
    Result res;
    if(isEmpty(s)){
        res.success = 0;
        return res;
    }
    res.success = 1;
    res.val = s->stack[s->top];
    return res;
}

int main(){
    Stack stackArr;
    initStack(&stackArr);

    Result result;
    int choice, input;
    char buffer[16];

    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &choice) != 1){
            printf("Invalid input!\n");
            continue;
        }
        switch(choice){
        case 1:
            int valid = 0;
            while(!valid){
                printf("Enter the number to push: ");
                fgets(buffer, sizeof(buffer), stdin);
                if(sscanf(buffer, "%d", &input) == 1){
                    valid = 1;
                }else{
                    printf("Invalid! Please enter a valid number!\n");
                }
            }
            push(&stackArr, input);
            break;
        case 2:
            result = pop(&stackArr);
            if(result.success){
                printf("Popped: %d\n", result.val);
            }else{
                printf("Stack underflow!\n");
            }
            break;
        case 3:
            result = peek(&stackArr);
            if(result.success){
                printf("Top: %d\n", result.val);
            }else{
                printf("Stack empty! Nothing to see.\n");
            }
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
*/

// 2:
/*
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
        q->rear->next = newNode;
        newNode->next = q->front;
        q->rear = newNode;
    }
}

int dequeue(Queue* q){
    Node* temp = q->front;
    int val = temp->data;
    if(q->front == q->rear){
        initQueue(q);
    }else{
        q->front = temp->next;
        q->rear->next = q->front;
    }
    free(temp);
    return val;
}

int peek(Queue* q){
    return q->front->data;
}

int main(){
    Queue q1;
    initQueue(&q1);

    int choice, input;
    char buffer[16];

    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");

        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &choice) != 1){
            printf("Invalid!\n");
            continue;
        }
        switch(choice){
        case 1:
            int valid = 0;
            while(!valid){
                printf("Enter the number to enqueue: ");
                fgets(buffer, sizeof(buffer), stdin);
                if(sscanf(buffer, "%d", &input) == 1){
                    valid = 1;
                }else{
                    printf("Invalid input. Please enter a number.\n");
                }
            }
            enqueue(&q1, input);
            break;
        case 2:
            if(isEmpty(&q1)){
                printf("Queue is empty. Nothing to dequeue.\n");
            }else{
                printf("Dequeued: %d\n", dequeue(&q1));
            }
            break;
        case 3:
            if(isEmpty(&q1)){
                printf("Queue is empty. Nothing to see.\n");
            }else{
                printf("Front: %d\n", peek(&q1));
            }
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
*/