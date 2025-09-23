/*   A + B / C * D - E / (F + G)  ->  A + B / C * D - E / FG+  ->  A + BC/ * D - E / FG+
->  A + BC/D* - EFG+/  ->  ABC/D*+EFG+/-  =  DONE.*/
/*Rule of postfix evaluation: As soon as you encounter an operator, you apply it to the last 2 operands.*/
/*Write a code that transforms an infix expression into postfix*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

typedef struct{
    char stack[MAX];
    int top;
}Stack;

int isEmpty(Stack* s){return s->top == -1;}
int isFull(Stack* s){return s->top == MAX -1;}

void push(Stack* s, char input){
    if(isFull(s)) return;
    s->stack[++(s->top)] = input;
}

char pop(Stack* s){
    if(isEmpty(s)) return '\0';
    return s->stack[(s->top)--];
}

int precedence(char op){
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

void toPostfix(const char* expression){
    Stack s;
    s.top = -1;

    for(int i = 0; expression[i] != '\0'; i++){
        char c = expression[i];

        if(c == ' ') continue; // skip spaces

        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            // Operand
            printf("%c", c);
        }
        else if(c == '('){
            push(&s, c);
        }
        else if(c == ')'){
            while(!isEmpty(&s) && s.stack[s.top] != '('){
                printf("%c", pop(&s));
            }
            pop(&s); // discard '('
        }
        else { // operator
            while(!isEmpty(&s) && precedence(s.stack[s.top]) >= precedence(c)){
                printf("%c", pop(&s));
            }
            push(&s, c);
        }
    }

    while(!isEmpty(&s)){
        printf("%c", pop(&s));
    }

    printf("\n");
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