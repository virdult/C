/*Write a program that creates a stack(LL) and then let user push n integers in it.
Reverse the stack by using another stack. only use stack operations! prints before and after reversal.*/
//Max size 50. Validate n>0. Don't use arrays directly to swap values. Only stack operations.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

typedef struct{
    Node* top;
}Stack;

void init(Stack* s){
    s->top = NULL;
}

int isEmpty(Stack* s){return s->top == NULL;}

void push(Stack* s, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = val;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack underflow!\n");
        return -1;
    }
    Node* temp = s->top;
    int val = temp->value;
    s->top = temp->next;
    free(temp);
    return val;
}

void reverseStack(const Stack* main, Stack* reverse){
    Node* curr = main->top;
    while(curr){
        push(reverse, curr->value);
        curr = curr->next;
    }
}

void printStack(Stack* s){
    Node* curr = s->top;
    while(curr){
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    int val;
    char buffer[16];

    Stack main, reverse;
    init(&main);
    init(&reverse);
    
    printf("Enter positive integers: (Enter 0 when you want to stop.)\n");
    while(1){
        if(!fgets(buffer, sizeof(buffer), stdin)) break;
        while(sscanf(buffer, "%d", &val) != 1 || val < 0){
            printf("Miss input! Please enter a valid integer!\n");
            if(!fgets(buffer, sizeof(buffer), stdin)) break;
        }
        if(val == 0) break;
        push(&main, val);
    }

    reverseStack(&main, &reverse);
    printf("Original Stack: ");
    printStack(&main);
    printf("Reversed Stack: ");
    printStack(&reverse);

    return 0;
}