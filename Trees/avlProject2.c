/*Event Scheduling System with Interval Overlap Queries.
You are building a calendar system. Each event is an interval [start, end].
Using an AVL tree, implement:
addEvent(start, end) → insert a new event.
removeEvent(start, end) → remove a given event.
findConflict(start, end) → check if the new event [start, end] overlaps with an existing one.*/
//Maybe make this menu based so I can use it as a calender type of thing.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 100

typedef struct Node{
    char eventName[MAXNAME];
    int day;
    int month;
    int eventStart;
    int eventEnd;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

int height(Node* n){return n ? n->height : 0;}
int max(int a, int b){return (a > b) ? a : b;}

Node* createNode(int day, int month, int start, int end, char* name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) exit(1);
    newNode->eventStart = start;
    newNode->eventEnd = end;
    newNode->day = day;
    newNode->month = month;

    strncpy(newNode->eventName, name, MAXNAME - 1);
    newNode->eventName[MAXNAME - 1] = '\0';

    newNode->left = newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

void updateNode(Node* n){
    if(!n) return;
    n->height = 1 + max(height(n->left), height(n->right));
}

int getBalance(Node* n){
    if(!n) return 0;
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateNode(y);
    updateNode(x);
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateNode(x);
    updateNode(y);
    return y;
}

