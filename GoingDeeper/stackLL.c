#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)sizeof(sizeof(Node));
    if(!newNode){
        perror("malloc failed!");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* push(Node* top, int data){
    Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top, int* poppedValue){
    if(!top){
        printf("Stack underflow!");
        return NULL;
    }
    Node* temp = top;
    *poppedValue = temp->data;
    top = top->next;
    free(temp);
    return top;
}

Node* peak(Node* top){
    if(!top){
        printf("Stack is empty!");
    }else{
        printf("Top element: %d\n", top->data);
    }
}

void printStack(Node* top){
    Node* temp = top;
    printf("Stack from top to bottom: \n");
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }    
    printf("\n");
}

int main() {
    Node* stack = NULL;
    int choice, value, popped;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Print Stack\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            stack = push(stack, value);
        } 
        else if (choice == 2) {
            stack = pop(stack, &popped);
            if (stack || popped) {
                printf("Popped: %d\n", popped);
            }
        } 
        else if (choice == 3) {
            peek(stack);
        } 
        else if (choice == 4) {
            printStack(stack);
        } 
        else if (choice == 5) {
            break;
        } 
        else {
            printf("Invalid choice\n");
        }
    }

    // free memory
    while (stack) {
        Node* temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}