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
        createNode(val);
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