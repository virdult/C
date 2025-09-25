/*Write a function that, given a BST and a range [L, R], returns the sum of all 
node values within that range (inclusive).
Requirements:
Must traverse efficiently (avoid visiting unnecessary nodes).
Should use recursion.
Extra: Implement a version that returns the sum without recursion.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int count;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) exit(1);
    newNode->data = val;
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val < root->data){
        root->left = insertNode(root->left, val);
    }else if(val > root->data){
        root->right = insertNode(root->right, val);
    }else{
        root->count++;
    }
    return root;
}

Node* findMin(Node* root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* removeNode(Node* root, int val){
    if(root == NULL){
        return root;
    }

    if(val < root->data){
        root->left = removeNode(root->left, val);
    }else if(val > root->data){
        root->right = removeNode(root->right, val);
    }else{
        if(root->count > 1){
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
        Node* temp = findMin(root->right);
        root->count = temp->count;
        root->data = temp->data;
        temp->count = 1;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

int rangeSumBST(Node* root, int L, int R) {
    if(root == NULL) return 0;

    if(root->data < L){
        return rangeSumBST(root->right, L, R);
    }
    if(root->data > R){
        return rangeSumBST(root->left, L, R);
    }

    int sum = root->data * root->count + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);

    return sum;
}

int main() {
    Node* root = NULL;

    // Build BST
    int values[] = {50, 30, 70, 20, 40, 60, 80, 25, 35, 65, 75};
    int n = sizeof(values) / sizeof(values[0]);
    for(int i = 0; i < n; i++) {
        root = insertNode(root, values[i]);
    }

    int L = 30, R = 65;
    printf("Recursive sum in range [%d, %d]: %d\n", L, R, rangeSumBST(root, L, R));

    return 0;
}