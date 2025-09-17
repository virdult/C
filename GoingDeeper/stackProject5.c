/*Write a C program that checks whether a string is a palindrome using a stack implemented as a linked list.
Ask user to enter a string. 100 characters max. Use LL. Only use stack operation to compare. No string operations*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char letter;
    struct Node* next;
}Node;

typedef struct{
    Node* top;
}Stack;

void init(Stack* s){
    s->top = NULL;
}

int isEmpty(Stack* s){return s->top == NULL;}

void push(Stack* s, char letter){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->letter = letter;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack underflow!\n");
        return '\0';
    }
    Node* temp = s->top;
    char output = temp->letter;
    s->top = temp->next;
    free(temp);
    return output;
}

int checkPalindrome(const char* inputWord){
    
}

int main(){
    char inputWord[101];

    printf("Write down the words that you want to check if it's palindrome: \n");
    fgets(inputWord, sizeof(inputWord), stdin);
    checkPalindrome(inputWord);





    return 0;
}