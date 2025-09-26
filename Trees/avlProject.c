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

int max(int a, int b) {
    return (a > b) ? a : b;
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

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* l = y->left;

    y->left = x;
    x->right = l;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return y;
}

Node* insert(Node* node, int val){
    if(node == NULL) return node;

    if(val < node->data){
        node->left = insert(node->left, val);
    }else if(val > node->data){
        node->right = insert(node->left, val);
    }else{
        node->count++;
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = isBalanced(node);

    if(balance < -1 && val > node->right->data){
        return leftRotate(node);
    }
    if(balance < -1 && val < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    if(balance > 1 && val > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance > 1 && val < node->left->data){
        return rightRotate(node);
    }
    return node;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL) return root;

    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }else{
        if(root && root->count > 1){
            root->count--;
            return root;
        }
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }//This is basically find min in the right subtree.
        root->count = temp->count;
        root->data = temp->data;
        temp->count = 1;
        deleteNode(root->right, temp->data);
    }
    //Deleting completed, now time for rearrangements.
    if(root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = isBalanced(root);

    if(balance < -1 && isBalanced(root->right) <= 0){
        return leftRotate(root);
    }
    if(balance < -1 && isBalanced(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    if(balance > 1 && isBalanced(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance > 1 && isBalanced(root->left) >= 0){
        return rightRotate(root);
    }
    return root;
}