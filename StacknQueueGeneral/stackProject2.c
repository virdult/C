/*Write a C program that prints all the prime factors of a given positive integer in descending order 
using a stack to store the factors.*/
/*Asks for an integer from user, finds all the prime factors, pushes each prime to a stack, pops in the end*/
/*Can use array or LL as stack. Max size = 100. Validate input n > 1.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* top;
}Stack;

void init(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int isEmpty(Stack* s){return s->top == NULL;}

int pop(Stack* s){
    if(isEmpty(s)) return -1;
    Node* temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

void primeFactors(Stack* s, int input){
    int factor = 2;
    while(input > 1){
        while(input % factor == 0){
            push(s, factor);
            input /= factor;
        }
        factor++;
    }
}

int main(){
    char buffer[100];
    int input;
    Stack s;
    init(&s);

    printf("Please give the integer you want to find its prime factors: \n");
    fgets(buffer, sizeof(buffer), stdin);
    while(sscanf(buffer, "%d", &input) != 1 || input <= 1){
        printf("Invalid entry! Please enter a valid number: \n");
        fgets(buffer, sizeof(buffer), stdin);
    }
    primeFactors(&s, input);

    printf("Prime factors in descending order: ");
    while(!isEmpty(&s)){
        printf("%d ", pop(&s));
    }
    printf("\n");

    return 0;
}
