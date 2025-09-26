/*Event Scheduling System with Interval Overlap Queries.
You are building a calendar system. Each event is an interval [start, end].
Using an AVL tree, implement:
addEvent(start, end) → insert a new event.
removeEvent(start, end) → remove a given event.
findConflict(start, end) → check if the new event [start, end] overlaps with an existing one.*/
//Maybe make this menu based so I can use it as a calender type of thing.

#include <stdio.h>
#include <stdlib.h>

#define MAXNAME 100

typedef struct{
    int day;
    int month;
}Date;

typedef struct Node{
    char eventName[MAXNAME];
    Date eventDate;
    int eventStart;
    int eventEnd;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

int height(Node* n){return n ? n->height : 0;}
int max(int a, int b){return (a > b) ? a : b;}

Node createNode(int start, int end, ){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) exit(1);
    newNode->eventStart
}
