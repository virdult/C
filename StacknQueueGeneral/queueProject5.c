/*Bank Queue. ->> Simulate a bank queue. Customers arrive with a service time.
You have m counters (servers). Each counter serves one customer at a time.
Compute the total time until all customers are served.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int queueNumber;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

typedef struct{
    int success;
    int queueNumber;
}Result;

void initQueue(Queue* q){
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q){return q->front == NULL;}

void enqueue(Queue* q, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return;
    newNode->queueNumber = val;
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

Result dequeue(Queue* q){
    Result res;
    if(isEmpty(q)){
        res.success = 0;
        return res;
    }
    Node* temp = q->front;
    res.success = 1;
    if(q->front == q->rear){
        initQueue(q);
    }else{
        res.queueNumber = temp->queueNumber;
        q->front = temp->next;
        q->rear->next = q->front;
    }
    free(temp);
    return res;
}

Result peek(Queue* q){
    Result res;
    if(isEmpty(q)){
        res.success = 0;
        return res;
    }
    res.success = 1;
    res.queueNumber = q->front->queueNumber;
    return res;
}

void printQueue(Queue* q){
    if(isEmpty(q)) return;
    Node* curr = q->front;
    printf("Customers: ");
    while(1){
        printf("%d", curr->queueNumber);
        if(curr == q->rear){
            printf("\n");
            return;
        }
        curr = curr->next;
    }
}

Result queueSize(Queue* q){
    Result res;
    if(isEmpty(q)){
        res.success = 0;
        return res;
    }
    res.success = 1;
    int i = 0;
    Node* curr = q->front;
    while(1){
        i++;
        res.queueNumber = i;
        if(curr == q->rear) return res;
        curr = curr->next; 
    }
}
//I'll continue basic. We'll do an advaned thing later for something else...
int main(){
    Queue bankQueue;
    initQueue(&bankQueue);
    Result res;

    Node* counters[2];

    enqueue(&bankQueue, 2);
    enqueue(&bankQueue, 7);
    enqueue(&bankQueue, 6);
    enqueue(&bankQueue, 1);
    enqueue(&bankQueue, 5);
    enqueue(&bankQueue, 3);
    printQueue(&bankQueue);
    printf("Counters: %d\n", sizeof(counters)/sizeof(counters[0]));
    res = queueSize(&bankQueue);
    if(!res.success){
        printf("No one is in the line.\n");
    }else{
        printf("Remaining time: %d\n", res.queueNumber* 4 / (sizeof(counters)/sizeof(counters[0])));
    }

    return 0;
}