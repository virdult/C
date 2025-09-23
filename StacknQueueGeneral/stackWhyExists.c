#include <stdio.h>
#include <stdlib.h> //For exit() function
#define MAX 10

typedef struct{
    int arr[MAX];
    int first;
}Stack;

int isFull(Stack* stack){return stack->first == MAX - 1;}
int isEmpty(Stack* stack){return stack->first == -1;} 

void push(Stack* stack, int data){
    if(isFull(stack)){
        printf("Stack overflow!\n");
        return;
    }
    stack->first += 1;
    for(int i = stack->first; i > 0; i--){
        stack->arr[i] = stack->arr[i - 1];
    }
    stack->arr[0] = data;
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow!\n");
        exit(-1);
    }
    int popped = stack->arr[0];
    for(int i = 1; i <= stack->first; i++){
        stack->arr[i - 1] = stack->arr[i];
    }
    stack->first -= 1;
    return popped;
}


int main(){
    int choice, data;
    char buffer[100];
    Stack stackArr;
    stackArr.first = -1;

    while(1){
        printf("Welcome to reversed stack I guess...\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print all the elements\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");

        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &choice) != 1){
            printf("Invalid input, please enter a number.\n");
            continue;
        }
        switch(choice){
        case 1:
            int valid = 0;
            while(!valid){
                printf("Enter the element to be pushed: ");
                fgets(buffer, sizeof(buffer), stdin);
                if (sscanf(buffer, "%d", &data) == 1) {
                    push(&stackArr, data);
                    valid = 1;
                }else{
                    printf("Invalid input! Please enter a number.\n");
                }
            }
            break;
        case 2:
            data = pop(&stackArr);
            printf("Popped: %d\n", data);
            break;
        case 3:
            if(isEmpty(&stackArr)){
                printf("Stack is empty!\n");
                break;
            }
            printf("%d\n", stackArr.arr[0]);
            break;
        case 4:
            if(isEmpty(&stackArr)){
                printf("Stack is empty!\n");
                break;
            }
            for(int i = 0; i <= stackArr.first; i++){
                printf("%d ", stackArr.arr[i]);
            }
            printf("\n");
            break;
        case 5:
            return (0);
        default:
            printf("Wrong choice.\n");
        }
    }

    return 0;
}