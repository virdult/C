/*You have n people standing in a circle, numbered 1 to n.
They play "hot potato": pass the potato k times, and the person holding it is eliminated.
Continue until only one person remains.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char* name;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

typedef struct{
    int success;
    char* name;
}Result;

void initQueue(Queue* q){
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q){return q->front == NULL;}

void enqueue(Queue* q, const char* name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return;
    newNode->name = strdup(name);
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
        res.name = NULL;
        return res;
    }

    res.success = 1;
    Node* temp = q->front;
    res.name = strdup(temp->name);  

    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }else{
        q->front = temp->next;
        q->rear->next = q->front;
    }
    
    free(temp->name);
    free(temp);
    
    return res;
}

Result peek(Queue* q){
    Result res;
    if(isEmpty(q)){
        res.success = 0;
        res.name = NULL;
    }else{
        res.success = 1;
        res.name = strdup(q->front->name);
    }
    return res;
}

void printQueue(Queue* q){
    Node* temp = q->front;
    while(1){
        printf("%s\n", temp->name);
        if(temp->next == q->front) break;
        temp = temp->next;
    }
}

void hotPotato(Queue* q, int k){
    if(isEmpty(q)){
        return;
    }
    Node* curr = q->front;
    while(curr  != curr->next){
        for(int i = 1; i < k; i++){
            curr = curr->next;
        }
        Node* eliminated = curr->next;
        printf("Eliminated: %s\n", eliminated->name);

        if(eliminated == q->front) q->front = eliminated->next;
        if(eliminated == q->rear) q->rear = curr;

        curr->next = eliminated->next;

        free(eliminated->name);
        free(eliminated);
    }
    printf("Winner: %s\n", curr->name);
}

void clearMemo(Queue* q) {
    if(isEmpty(q)) return;

    Node* current = q->front;
    Node* nextNode;

    while(current != q->rear){
        nextNode = current->next;
        free(current->name);
        free(current);
        current = nextNode;
    }
    
    free(q->rear->name);
    free(q->rear);

    initQueue(q);
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, "Alice");
    enqueue(&q, "Bob");
    enqueue(&q, "Charlie");
    enqueue(&q, "Diana");
    enqueue(&q, "Rooney");
    enqueue(&q, "Henry");
    enqueue(&q, "Alex");
    enqueue(&q, "Jeff");
    enqueue(&q, "Jack");
    enqueue(&q, "Pepe");
    enqueue(&q, "Donald");

    hotPotato(&q, 3);

    clearMemo(&q); // free remaining memory
    return 0;
}