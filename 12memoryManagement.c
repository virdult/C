#include <stdio.h>
#include <stdlib.h> //Required for memory functions
#include <stdbool.h>
#include <string.h>

/*
void staticFunc(){
    int static x = 0;
    x++;
    printf("x: %d\n", x);
}//This 'int static' makes so that x becomes a static variable, that is not dying after leaving the scope but
//persists itself for the whole program.

int main(){
    
    staticFunc();
    staticFunc();

    return 0;
}
*/

typedef struct{
    char name[30];
    int age;
    bool isVerified;
}user;

user *createUser(char name[], int age, bool isVerified){
    user *newUser = malloc(sizeof(user));
    strcpy(newUser->name, name);
    newUser->age = age;
    newUser->isVerified = isVerified;
    return newUser;
}


int main(){
    int size;
    printf("How many int elements do you need?: \n");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));//Allocates the memory with malloc. Malloc returns a pointer. so we store it
    
    if(arr == 0){
        printf("Invalid Pointer. Error allocating memory.\n");
        return -1;//Something went wrong.
    }else{
        printf("Write down the array.\n");
        for(int i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }

        printf("Your Array:\n");

        for(int i = 0; i < size; i++){
            printf("arr[%d]: %d\n", i, arr[i]);
        }
    }
    
    free(arr); //You need to free the memory.

    user *me = createUser("Umut Şener", 22, true);

    printf("Umut is %d years old!\n", me->age);
    free(me);

    return 0;
}