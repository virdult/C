/*I'll try to make this thing myself once*/

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

void inOrderTraversal(Node* root){
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("Value: %d, Amount: %d\n", root->data, root->count);
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if(root == NULL) return;
    printf("Value: %d, Amount: %d\n", root->data, root->count);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("Value: %d, Amount: %d\n", root->data, root->count);
}

Node* findMin(Node* root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL) return root;

    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }else if(val > root->data){
        root->right = deleteNode(root->right, val);
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
        root->data = temp->data;
        root->count = temp->count;
        temp->count = 1;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    Node* root = NULL;

    root = insertNode(root, 10);
    insertNode(root, 6);
    insertNode(root, 11);
    insertNode(root, 15);
    insertNode(root, 12);
    insertNode(root, 15);
    insertNode(root, 9);
    insertNode(root, 8);
    insertNode(root, 1);
    insertNode(root, 16);
    insertNode(root, 19);
    insertNode(root, 22);
    insertNode(root, 17);
    insertNode(root, 11);
    printf("Post Order\n");
    postOrderTraversal(root);
    printf("Pre Order\n");
    preOrderTraversal(root);
    printf("In Order\n");
    inOrderTraversal(root);
    return 0;
}