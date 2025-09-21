/*Write a function that checks whether two queues contain the same elements in the same order.
Returns 1 if identical, 0 if not. Do not destroy the original queues
Method A (simple): Compare element-by-element using indexes if you have array-based queues.
Method B (tricky): For linked-list queues, dequeue elements and enqueue them back to preserve the order.
Do both!*/

/* METHOD A : 

#include <stdio.h>

#define MAX 8
typedef struct{
    int queueArr[MAX];
    int front, rear;
}QueueArr;

void initQueueArr(QueueArr* q){
    q->front = q->rear = -1;
}

int isQueueArrEmpty(QueueArr* q){return q->front == -1;}
int isQueueArrFull(QueueArr* q){return (q->rear + 1) % MAX == q->front;}

void enqueueArr(QueueArr* q, int val){
    if(isQueueArrFull(q)) return;
    if(isQueueArrEmpty(q)){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->queueArr[q->rear] = val;
}

int dequeueArr(QueueArr* q){
    if(isQueueArrEmpty(q)) return -1;
    int out = q->queueArr[q->front];
    if(q->front == q->rear){
        initQueueArr(q);
    }else{
        q->front = (q->front + 1) % MAX;
    }
    return out;
}

int compareQueueArr(QueueArr* q1, QueueArr* q2){
    if(q1->front != q2->front || q1->rear != q2->rear){
        return 0;
    }

    int i = q1->front;
    int j = q2->front;

    while(i != (q1->rear + 1) % MAX && j != (q2->rear + 1) % MAX){
        if(q1->queueArr[i] != q2->queueArr[j]){
            return 0;
        }
        i = (i + 1) % MAX;
        j = (j + 1) % MAX;
    }
    return 1;
}
*/ //Method A's end.

//Method B : 
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
    if(!newNode) exit(1);
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
        printf("Queue is emoty!\n");
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

int compareQueue(Queue* q1, Queue* q2) {
    Queue temp1, temp2;
    initQueue(&temp1);
    initQueue(&temp2);

    int same = 1;
    while (!isEmpty(q1) && !isEmpty(q2)) {
        int val1 = dequeue(q1);
        int val2 = dequeue(q2);

        if (val1 != val2) same = 0;

        enqueue(&temp1, val1);//Putting them on temp because I want to keep the order. Otherwise, it will 
        enqueue(&temp2, val2);//go off by 1 index I guess?(with recursion ofc, in here it will just get lost)
    }

    if (!isEmpty(q1) || !isEmpty(q2)) same = 0;

    while (!isEmpty(&temp1)) enqueue(q1, dequeue(&temp1));
    while (!isEmpty(&temp2)) enqueue(q2, dequeue(&temp2));

    return same;
}