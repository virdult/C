#include <stdio.h>
/*
//Pointer to pointer
int main(){
    int x = 5;
    int *a = &x;
    int **b = &a;
    int ***c = &b;

    printf("Using x:\n");
    printf("x: %d\n", x);

    printf("Using a: \n");
    printf("a: %d\n", a);
    printf("x: %d\n", *a);

    printf("Using b: \n");
    printf("b: %d\n", b);
    printf("a: %d\n", *b);
    printf("x: %d\n", *(*b));

    printf("Using c: \n");
    printf("c: %d\n", c);
    printf("b: %d\n", *c);
    printf("a: %d\n", *(*c));
    printf("x: %d\n", *(*(*c)));

    ***c = 10;
    printf("Value of new x: %d\n", x);

return 0;
}
*/
//Our variables are defined a Stack part of the memory. They are the local variables.
//There are 3 more, Which are Heap, Static/Global, Code (text)
//The stack, Static/Global and Code(text) are fixed, decided memories when program is started
//But Heap can ask for more memory and return memory to the device.

//Call by reference
void increment(int *p){
    *p += 5;
}

int main(){
    int a = 4;
    increment(&a);
    printf("a after incrementation: %d\n", a);


    return 0;
}