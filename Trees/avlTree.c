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

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    //Standard BST delete
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->count > 1) {
            root->count--;
            return root;
        }

        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = root->right;
            while (temp->left != NULL) temp = temp->left;

            root->data = temp->data;
            root->count = temp->count;
            temp->count = 1;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node
    if (root == NULL) return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Check balance
    int balance = getBalance(root);

    // Balance cases
    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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