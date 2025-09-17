/*How do you make queue only using stack? How do you implement dequeue and queue?*/
//This is not how you do it lol! I basically made a queue without knowing how to make a queue xD.
//The answer is at way below the code
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* previous;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Stack;

void init(Stack* s){
    s->front = NULL;
    s->rear = NULL;
}

int isEmpty(Stack* s){return s->front == NULL;}

void enqueue(Stack* s, int val){//Input should be rear
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;
    if(isEmpty(s)){
        s->front = newNode;
        s->rear = newNode;
    }else{
        newNode->next = s->rear;
        s->rear->previous = newNode;
        s->rear = newNode;
    }
}

int dequeue(Stack* s){//Input should be front
    if(isEmpty(s)){
        printf("Stack underflow!\n");
        return -1;
    }
    Node* temp = s->front;
    int val = temp->data;
    s->front = temp->previous;
    free(temp);
    return val;
}

int peek(Stack* s){
    if(isEmpty(s)) return -1;
    return s->front->data;
}

void printQueue(Stack* s){
    Node* temp = s->front;
    printf("Queue from front to back: \n");
    while(temp){
        printf("%d ", temp->data);
        temp = temp->previous;
    }    
    printf("\n");
}

int main(){
    int choice, value, dequeued;
    char buffer[4];

    Stack s;
    init(&s);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Print Queue\n5. Exit\nChoice: ");
        scanf(" %d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&s, value);
        } 
        else if (choice == 2) {
            dequeued = dequeue(&s);
            printf("Dequeued value: %d\n", dequeued);   
        } 
        else if (choice == 3) {
            peek(&s);
        } 
        else if (choice == 4) {
            printQueue(&s);
        } 
        else if (choice == 5) {
            break;
        } 
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

/*
typedef struct {
    int arr[100];
    int top;
} Stack;

void push(Stack* s,int v){ s->arr[++s->top]=v; }
int pop(Stack* s){ return s->arr[s->top--]; }
int empty(Stack* s){ return s->top==-1; }

typedef struct {
    Stack in, out;
} Queue;

void initQueue(Queue* q){
    q->in.top=-1;
    q->out.top=-1;
}
void enqueue(Queue* q,int v){ push(&q->in,v); }
int dequeue(Queue* q){
    if (empty(&q->out))
        while (!empty(&q->in))
            push(&q->out,pop(&q->in));
    if (empty(&q->out)) return -1;
    return pop(&q->out);
}
*/