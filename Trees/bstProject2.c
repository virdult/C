/*Problem: Write a function that finds the Lowest Common Ancestor (LCA) of two given nodes in a BST.
The LCA is the deepest node that is an ancestor of both nodes.
Requirements:
Must work in O(h) time, where h = tree height.
Should not use extra space apart from recursion stack.*/

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
    if(root == NULL) return createNode(val);

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
        root->count = temp->count;
        root->data = temp->data;
        temp->count = 1;
        deleteNode(root->right, temp->data);
    }
    return root;
}

Node* lowestCommonAncestor(Node* root, Node* left, Node* right){
    if(root == NULL) return root;

    if(left->data < root->data && right->data < root->data){
        return lowestCommonAncestor(root->left, left, right);
    }else if(left->data > root->data && right->data > root->data){
        return lowestCommonAncestor(root->right, left, right);
    }else{
        return root;
    }
}
//Main is written by GPT
int main() {
    Node* root = NULL;

    // Build the BST
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        root = insertNode(root, values[i]);
    }

    // Let's pick nodes to find LCA for
    Node* node1 = root->left->left;   // 5
    Node* node2 = root->left->right;  // 15

    Node* lca = lowestCommonAncestor(root, node1, node2);
    if (lca != NULL) {
        printf("LCA of %d and %d is %d\n", node1->data, node2->data, lca->data);
    } else {
        printf("LCA not found.\n");
    }

    // Another test
    node1 = root->right->left;  // 25
    node2 = root->right->right; // 35

    lca = lowestCommonAncestor(root, node1, node2);
    if (lca != NULL) {
        printf("LCA of %d and %d is %d\n", node1->data, node2->data, lca->data);
    } else {
        printf("LCA not found.\n");
    }

    return 0;
}