/*Write a C program that checks whether a string is a palindrome using a stack implemented as a linked list.
Ask user to enter a string. 100 characters max. Use LL. Only use stack operation to compare.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void checkPalindrome(const char* inputWord, int size){
    Stack s;
    init(&s);
    int i = 0;
    char temp;
    while(i < size / 2){
        push(&s, inputWord[i]);
        i++;
    }
    if(size % 2 != 0){
        i++;
    }
    while(i < size){    
        temp = pop(&s);
        if(temp != inputWord[i]){
            printf("Not Palindrome!\n");
            while(!isEmpty(&s)) pop(&s); //-> This line is for when not palindrome, frees the memo of the stack.
            return;
        }
        i++;
    }
    printf("Palindrome!\n");
}

int main(){
    char inputWord[101];

    printf("Write down the words that you want to check if it's palindrome: \n");
    fgets(inputWord, sizeof(inputWord), stdin);
    inputWord[strcspn(inputWord, "\n")] = '\0';
    int size = strlen(inputWord);
    checkPalindrome(inputWord, size);

    return 0;
}