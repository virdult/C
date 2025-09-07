/*gcc filename -o exename*/
#include <stdio.h>

int main(){
    printf("Hello World!\n");

    int x = 50;
    int y; //declaration
    y = 10; //initialization

    printf("%s World!\n", "Hello");
    printf("The value of x: %d\n", x);
    printf("x is: %d, y is %d\n", x, y);

    printf("Give me an input: \n");
    int input;
    scanf("%d", &input); //Adress-of-operator, gives a pointer
    printf("You choose the value: %d\n", input);

    char name[20]; //Char array of 20 characters -> '\0' takes one spot, indicates the end of the string
    printf("Give me your name: \n");
    scanf("%19s", name);
    printf("%s", name); //Can't take space characters idk why for now.

    return 0;
}