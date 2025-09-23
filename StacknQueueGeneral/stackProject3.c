/*Write a C program that converts a positive integer in decimal to its binary representation using a stack.*/
/*Ask for an input, convert it to binary, pop and print correctly.
Use unsigned int for size. both stack types works, choose your own. check if input > 0*/

#include <stdio.h>
#include <stdlib.h>
//Since unsigned int is max 2^32, the limit of our stack will be 32, so I'll use array based stack
#define MAX 32
typedef struct{
    int arr[MAX];
    int top;
}Stack;

int isFull(Stack* s){return s->top == MAX - 1;}
int isEmpty(Stack* s){return s->top == -1;}

void push(Stack* s, int val){
    if(isFull(s)){
        printf("Stack overflow!\n");
        return; // exit(1); ?? I guess this exits the whole program so no...
    }
    s->arr[++(s->top)] = val;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void decimalToBinary(Stack* s, unsigned int val){
    while(val > 0){
        push(s, val % 2);
        val /= 2;
    }
}

int main(){
    unsigned int input;
    char buffer[100];

    Stack s;
    s.top = -1;

    printf("Type the number you want to change to binary: \n");
    fgets(buffer, sizeof(buffer), stdin);
    while(sscanf(buffer, "%u", &input) != 1){
        printf("Invalid entry. Please enter a valid number: \n");
        fgets(buffer, sizeof(buffer), stdin);
    }
    decimalToBinary(&s, input);
    
    while(!isEmpty(&s)){
        printf("%d", pop(&s));
    }

    return 0;
}