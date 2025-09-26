/*Dynamic rank queries with AVL
Implement an AVL tree that supports these operations efficiently:
insert(x) → Insert number x.
delete(x) → Delete number x.
rank(x) → Return the number of elements in the set ≤ x.
select(k) → Return the k-th smallest element.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int height;
    int count;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return NULL;
    newNode->count = 1;
    newNode->height = 1;
    newNode->data = val;
    newNode->right = newNode->left = NULL;
    return newNode;
}

int height(Node* n){
    return (n == NULL) ? 0 : n->height;
}

int isBalanced(Node* n){
    if(n == NULL) return 0;
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* r = x->right;

    x->right = y;
    y->right = r;

    x->height = height
}