#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int count;
    int height;
    struct Node* left;
    struct Node* right;
}Node;

int height(Node* n){
    return (n == NULL) ? 0: n->height;
}

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) exit(1);
    newNode->data = val;
    newNode->height = 1;
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getBalance(Node* n){
    if(n == NULL) return 0;
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x; // new root
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y; // new root
}

// Insert a value in AVL tree
Node* insert(Node* node, int val){
    // Normal BST insert
    if (node == NULL) return createNode(val);

    if (val < node->data)
        node->left = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);
    else {
        node->count++; // duplicate
        return node;
    }

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Balance the tree if needed
    // Case 1: Left Left
    if (balance > 1 && val < node->left->data)
        return rightRotate(node);

    // Case 2: Right Right
    if (balance < -1 && val > node->right->data)
        return leftRotate(node);

    // Case 3: Left Right
    if (balance > 1 && val > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left
    if (balance < -1 && val < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // unchanged node
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main
int main() {
    Node* root = NULL;

    // Insert values
    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    printf("Inorder traversal of the AVL tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}