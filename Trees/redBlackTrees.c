/*
1: Every node is either red or black.
2: The ROOT is always black.
3: Leaves are always black.
4: Red parent can not have a Red child.
5: Every path from a node to leaf must contain the same number of black nodes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {RED, BLACK} Color;

typedef struct RBNode{
    int data;
    Color color;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
}RBNode;

static RBNode* NIL = NULL;
static RBNode* root = NULL;

void initRBT(){
    if(NIL != NULL) return; //Already initialized
    NIL = (RBNode*)malloc(sizeof(RBNode));
    if(!NIL){
        perror("malloc"); 
        exit(EXIT_FAILURE);
    }
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NULL;
    NIL->data = 0;
    root = NIL;
}

RBNode* createNode(RBNode* root, int val){
    RBNode* newNode = (RBNode*)malloc(sizeof(RBNode));
    if(!newNode){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NIL;
    return newNode;
}

void leftRotate(RBNode* x){
    RBNode* y = x->right;
    assert(x != NIL && y != NIL);//assert is here to ensure me not calling rotate in a wrong spot. Does nothing if correct, exits program if false
    x->right = y->left;
    if(y->left != NIL) y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == NIL) root = y;
    else if(x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(RBNode* y){
    RBNode* x = y->left;
    assert(y != NIL && x != NIL);
    y->left = x->right;
    if(x->right != NIL) x->right->parent = y;
    x->parent = y->parent;
    if(y->parent == NIL) root = x;
    else if(y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;
    x->left = y;
    y->parent = x;
}

