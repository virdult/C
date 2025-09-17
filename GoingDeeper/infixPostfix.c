/*   A + B / C * D - E / (F + G)  ->  A + B / C * D - E / FG+  ->  A + BC/ * D - E / FG+
->  A + BC/D* - EFG+/  ->  ABC/D*+EFG+/-  =  DONE.*/
/*Rule of postfix evaluation: As soon as you encounter an operator, you apply it to the last 2 operands.*/
/*Write a code that transforms an infix expression into postfix*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

typedef struct{
    char expression[MAX];
    int top;
}Stack;

int isEmpty(Stack* s){return s->top == -1;}
int isFull(Stack* s){return s->top == MAX -1;}

void push(Stack* s, char input){
    if(isFull(s)) return;
    s->expression[++(s->top)] = input;
}

char pop(Stack* s){
    if(isEmpty(s)) return '\0';
    return s->expression[(s->top)--];
}

void toPostfix(const char* expression){
    Stack s;
    s.top = -1;

    int i = 0;
    char popped;
    while(expression[i] != '\0'){
        if(expression[i] == '('){
            push(&s, expression[i]);
            i++;
        }
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
            push(&s, expression[i]);
            i++;
        }
        if(expression[i] == ')'){
            while(popped != '('){
                popped = pop(&s);
                printf("%c", popped);
            }
            i++;
        }else{
            printf("%c", expression[i]);
            i++;
        }
    }
    popped = pop(&s);
    printf("%c", popped);
}

int main(){
    int choice;
    char expression[101], buffer[4];

    while(1){
        printf("Welcome to expression manager!\n");
        printf("1. Write the expression in infix.\n");
        printf("2. Make your infix into postfix.\n");
        printf("3. Exit.\n");
        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &choice) != 1){
            printf("Invalid input.\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            printf("Please write down the expression: ");
            fgets(expression, sizeof(expression), stdin);
            break;
        case 2:
            toPostfix(expression);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice!\n");
            break;
        }

    }


    return 0;
}