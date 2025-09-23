/*Reverse a queue. Write a function that reverses the order of elements in a queue.
Try both with a stack and without using extra data structures (recursion).*/

#include <stdio.h>
#define MAX 10

typedef struct{
    int queueArr[10];
    int front, rear;
}Queue;

void initQueue(Queue* q){
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
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->queueArr[q->rear] = val;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue empty. Nothing to dequeue!\n");
        return -1;
    }
    int val = q->queueArr[q->front];
    if(q->front == q->rear){
        initQueue(q);
    }else{
        q->front = (q->front + 1) % MAX;
    }
    return val;
}

int peek(Queue* q){
    if(isEmpty(q)){
        printf("Queue empty!\n");
        return -1;
    }
    return q->queueArr[q->front];
}

void printQueue(Queue* q){
    if(isEmpty(q)) return;
    int i = q->front;
    while(1){
        printf("%d", q->queueArr[i]);
        if(i == q->rear) break;
        i = (i + 1) % MAX;    
    }
    printf("\n");
}
//Recursion
void reverseQueue(Queue* q){
    if(isEmpty(q)){
        return;
    }
    int val = dequeue(q);
    reverseQueue(q);
    enqueue(q, val);
}
//Stack
typedef struct{
    int val[MAX];
    int top;
}Stack;

void initStack(Stack* s){s->top = -1;}
int isStackEmpty(Stack* s){return s->top == -1;}
int isStackFull(Stack* s){return s->top == MAX - 1;}
void push(Stack* s, int val){
    if(isStackFull(s)){
        return;
    }
    s->val[++(s->top)] = val;
}
int pop(Stack* s){
    if(isStackEmpty(s)){
        return -1;
    }
    return s->val[(s->top)--];
}

void reverseQueueWithStack(Queue* q){
    Stack s;
    initStack(&s);  

    while(!isEmpty(q)){
        push(&s, dequeue(q));
    }
    while(!isStackEmpty(&s)){
        enqueue(q, pop(&s));
    }
}

int main(){
    Queue queue;
    initQueue(&queue);

    int choice, input;
    char buffer[12];

    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Reverse Queue With Recursion\n");
        printf("6. Reverse Queue With Stack\n");
        printf("7. Exit\n");

        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &choice) != 1){
            printf("Invalid choice.\n");
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
            enqueue(&queue, input);
            break;
        case 2:
            printf("Dequeued: %d\n", dequeue(&queue));
            break;
        case 3:
            printf("Front: %d\n", peek(&queue));
            break;
        case 4:
            printQueue(&queue);
            break;
        case 5:
            reverseQueue(&queue);
            break;
        case 6:
            reverseQueueWithStack(&queue);
            break;
        case 7:
            return 0;
        default:
            break;
        }
    }

    return 0;
}