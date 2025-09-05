#include <stdio.h>

void square();
//void sizeExample();

int main(){
    /*
    int a = 100;
    int *b = &a; // Pointer to an integer
    int **c = &b; // Pointer to a pointer to an integer

    printf("Value of a: %d\n", a); // Direct value of a
    printf("Value of *b: %d\n", *b); // Dereferencing b to get the value of a
    printf("Value of **c: %d\n", **c); // Dereferencing c twice to get the value of a

    *b = 200; // Changing the value of a

    printf("after change, Value of a: %d\n", a); // Direct value of a
    printf("after change, Value of *b: %d\n", *b); // Dereferencing b to get the value of a
    printf("after change, Value of **c: %d\n", **c); // Dereferencing c twice to get the value of a

    int d = 6000;
    b = &d; // Changing b to point to d -> We doN't put '*' because we don't want to change the value 
            // inside but the address
    
    printf("after changing b to point d, b: %d\n", *b); // Dereferencing b to get the value of d
    */

    int x = 5;
    square(&x); // Passing the address of x to the function
    printf("Square of x is: %d\n", x); // x is changed to its square value

    int size = 5;
    int ages[] = {23, 43, 12, 89, 2};

    printf("Memory size of ages array: %lu\n", sizeof(ages));
    sizeExample(ages);


    return 0;
}

void square(int *input){
    *input *= *input;
}
/*
void sizeExample(int ages[]){
    printf("Memory size of ages array: %lu\n", sizeof(ages));
} // Here ages is treated as a pointer, so it will give the size of pointer not the array
  // Even compiler says us that ages is a pointer not an array
  */