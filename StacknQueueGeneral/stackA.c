#include <stdio.h>

#define MAX 6
int stackArr[MAX];
int top = -1;
/*
int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(){
    if(top == MAX -1){
        return 1;
    }else{
        return 0;
    }
}
*/
int isEmpty(){return top == -1;}
int isFull(){return top == MAX - 1;}

void push(int data){
    if(isFull()){
        printf("Stack Overflow!\n");
        return;
    }
    top += 1;
    stackArr[top] = data;
}

void pop(){
    if(isEmpty()){
        printf("Stack underflow!\n");
        return;
    }
    printf("Popped value: %d\n", stackArr[top]);
    top -= 1;
}//can make function int pop and return the popped thing in the main as well..

void peek(){
    if(top == -1){
        printf("Stack empty!\n");
        return;
    }
    printf("Top value: %d\n", stackArr[top]);
}

int main(){
    int choice, data;
    char buffer[100];

    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements.\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");

        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            continue; // back to menu
        }

        switch(choice){
        case 1:
            int valid = 0;
            while(!valid){
                printf("Enter the element to be pushed: ");
                fgets(buffer, sizeof(buffer), stdin);
                if (sscanf(buffer, "%d", &data) == 1) {
                    push(data);
                    valid = 1;
                }else{
                    printf("Invalid input! Please enter a number.\n");
                }
            }
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if(isEmpty()){
                printf("Stack is empty!\n");
            }else{
                for(int i = 0; i <= top; i++){
                printf("%d ", stackArr[i]);
                }
                printf("\n");
            }
            break;
        case 5:
            return(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}