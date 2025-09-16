#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    char expArray[100];
    int top;
}Stack;

int isFull(Stack* stack){return stack->top == 99;}
int isEmpty(Stack* stack){return stack->top == -1;}

void push(Stack* stack, char input){
    if(isFull(stack)){
        printf("Stack overflow!\n");
        return;
    }
    stack->top += 1;
    stack->expArray[stack->top] = input;
}

char pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack->expArray[stack->top--];
}

int isMatch(char open, char close){
    if((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']')){
        return 1;
    }else{
        return 0;
    }
}

int checkBalanced(const char* inputEq){
    Stack arr;
    arr.top = -1;

    for(int i = 0; inputEq[i] != '\0'; i++){
        char c = inputEq[i];
        if(c == '(' || c == '[' || c == '{'){
            push(&arr, c);
        }else if(c == ')' || c == ']' || c == '}'){
            if(isEmpty(&arr)) return 0;
            char last = pop(&arr);
            if(!isMatch(last, c)) return 0;
        }
    }
    return arr.top == -1; //Stack empty, balanced
}

int main(){
    char inputEq[101];
    printf("Write down the equation: \n");
    fgets(inputEq, sizeof(inputEq), stdin);
    if(checkBalanced(inputEq)){
        printf("Balanced!\n");
    }else{
        printf("Not balanced!\n");
    }

    return 0;
}