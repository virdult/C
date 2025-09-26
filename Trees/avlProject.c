/*Dynamic rank queries with AVL
Implement an AVL tree that supports these operations efficiently:
insert(x) → Insert number x.
delete(x) → Delete number x.
rank(x) → Return the number of elements in the set ≤ x.
select(k) → Return the k-th smallest element.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int data;
    int height;
    int count;
    int size;//size of subtree
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    n->data = val;
    n->height = 1;
    n->count = 1;
    n->size = 1;
    n->left = n->right = NULL;
    return n;
}

int height(Node* n){return n ? n->height : 0;}
int getSize(Node* n){return n ? n->size : 0;}
int max(int a,int b){return (a>b)?a:b;}

void updateNode(Node* n){
    if(!n) return;
    n->height = 1 + max(height(n->left), height(n->right));
    n->size = getSize(n->left) + getSize(n->right) + n->count;
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

int getBalance(Node* n){
    if(!n) return 0;
    return height(n->left) - height(n->right);
}

Node* insert(Node* node, int val){
    if(node == NULL) return createNode(val);

    if(val < node->data){
        node->left = insert(node->left, val);
    }else if(val > node->data){
        node->right = insert(node->right, val);
    }else{
        node->count++;
        node->size++;//Increment subtree size for this node
        return node;
    }

    updateNode(node);

    int balance = getBalance(node);

    //LL
    if(balance > 1 && val < node->left->data)
        return rightRotate(node);
    //RR
    if(balance < -1 && val > node->right->data)
        return leftRotate(node);
    //LR
    if(balance > 1 && val > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //RL
    if(balance < -1 && val < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* findMin(Node* node){
    Node* cur = node;
    while(cur && cur->left) cur = cur->left;
    return cur;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL) return NULL;

    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }else{
        if(root->count > 1){
            root->count--;
            root->size--;
            return root;
        }
        if(root->left == NULL){
            Node* tmp = root->right;
            free(root);
            return tmp;
        }else if(root->right == NULL){
            Node* tmp = root->left;
            free(root);
            return tmp;
        }else{
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->count = succ->count;
            succ->count = 1;
            root->right = deleteNode(root->right, succ->data);
        }
    }

    updateNode(root);
    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//rank(x): number of elements <= x
int rank(Node* root, int x){
    if(root == NULL) return 0;
    if(x < root->data){
        return rank(root->left, x);
    }else if(x > root->data){
        //All left subtree + this node's count + rank in right
        return getSize(root->left) + root->count + rank(root->right, x);
    }else{
        //x == root->data: everything in left + all occurrences of this value
        return getSize(root->left) + root->count;
    }
}

//select(k): returns k-th smallest (1-based). If k invalid returns INT_MIN.
int selectK(Node* root, int k){
    if(root == NULL || k <= 0 || k > getSize(root)) return INT_MIN;
    int leftSize = getSize(root->left);
    if(k <= leftSize) return selectK(root->left, k);
    if(k <= leftSize + root->count) return root->data;
    return selectK(root->right, k - leftSize - root->count);
}

void inOrderTraversal(Node* root){
    if(!root) return;
    inOrderTraversal(root->left);
    for(int i=0;i<root->count;i++) printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main(){
    Node* root = NULL;

    int arr[] = {20, 4, 15, 70, 50, 100, 15, 15, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) root = insert(root, arr[i]);

    printf("In-order after inserts: ");
    inOrderTraversal(root);
    printf("\n");

    //rank queries
    printf("rank(15) = %d  (should count all <= 15)\n", rank(root, 15));
    printf("rank(50) = %d\n", rank(root, 50));
    printf("total size = %d\n", getSize(root));

    //select queries
    for(int k=1;k<=getSize(root);k++){
        int val = selectK(root, k);
        printf("%d-th smallest = %d\n", k, val);
    }

    //deletes
    root = deleteNode(root, 15); //removes one occurrence of 15
    printf("After deleting one 15: ");
    inOrderTraversal(root);
    printf("\n rank(15) = %d\n", rank(root, 15));

    //delete all 4s by calling delete until rank or select shows none
    root = deleteNode(root, 4); //deletes one 4 (we had duplicates)
    printf("After deleting a 4: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}