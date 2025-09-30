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
    int startHour;
    int endHour;
    int keyStart;
    int keyEnd;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

int height(Node* n){return n ? n->height : 0;}
int max(int a, int b){return (a > b) ? a : b;}

Node* createNode(int day, int month, int start, int end, const char* name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) exit(1);
    newNode->startHour = start;
    newNode->endHour = end;
    newNode->day = day;
    newNode->month = month;
    newNode->keyStart = month*720 + day*24 + start;
    newNode->keyEnd = month*720 + day*24 + end;

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

int makeKey(int month, int day, int start){
    return month * 720 + day * 24 + start;
}

Node* insert(Node* root, int day, int month, int start, int end, const char* eventName){
    if(root == NULL) return createNode(day, month, start, end, eventName);
    int newKey = makeKey(month, day, start);
    if(newKey < root->keyStart){
        root->left = insert(root->left, day, month, start, end, eventName);
    }else if(newKey > root->keyStart){
        root->right = insert(root->right, day, month, start, end, eventName);
    }else{
        if(start < root->endHour && end > root->startHour){
            printf("This time period is already occupied with: %s\n", root->eventName);
            printf("Setting current thing have failed. Please try another time.\n");
            return root;
        }
    }

    updateNode(root);
    int balance = getBalance(root);

    //LL
    if(balance > 1 && newKey < root->left->keyStart){
        return rightRotate(root);
    }
    //RR
    if(balance < -1 && newKey > root->right->keyStart){
        return leftRotate(root);
    }
    //LR
    if(balance > 1 && newKey > root->left->keyStart){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //RL
    if(balance < -1 && newKey < root->right->keyStart){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* findMin(Node* root){
    Node* curr = root;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}

//I won't make a deletion for now. Since the code is not useful with this version anyway, I'll not bother thinking
//If I should make the delete with comparing strings or should I input something else etc etc.
//If I ever make an app like this, I'll make the delete then as just clicking the place and then select delete.