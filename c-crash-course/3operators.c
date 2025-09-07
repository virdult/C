#include <stdio.h>

/*
Arithmetic: + - * / %
Increment/Decrement: ++ --
Assignment: = += -= *= /=
Comparison: == != < > <= >=
Logical: && || !
Ternary: ? :
*/

int main(){
    
    int a = 5;
    int b;
    printf("Post Increment: \n");
    a = 5;
    b = a++;
    printf("a: %d, b: %d\n", a, b); //a will be printed as 6 and b will be printed as 5
    printf("Pre Increment: \n");
    a = 5;
    b = ++a;
    printf("a: %d, b: %d", a, b); //Both will be printed out as 6

    return 0;
}