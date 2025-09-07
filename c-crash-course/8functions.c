#include <stdio.h>
/*
int square();
int cube();
int power();

int main(){

    int x = 5;
    int exp = 5;
    //x *= x; //Squaring value, lets make this with function
    int squaredx = square(x);
    int cubedx = cube(x);
    int poweredx = power(x, exp);
    printf("squared x: %d \n", squaredx);
    printf("cubed x: %d \n", cubedx);
    printf("powered x: %d \n", poweredx);

    return 0;
}

int square(int input){
    return input * input;
}

int cube(int input){
    return input * input * input;
}

int power(int number, int exponent){
    int output = 1;
    while(exponent > 0){
        output *= number;
        exponent--;
    }
    return output;
}
*/
/*
//RECURSION!!

int recursivePower();
void cantChangeVal();
void changeVal();

int main(){
    int x = 5, exponent = 3;
    int answer = recursivePower(x, exponent);
    printf("Answer: %d\n", answer);
    printf("x before function: %d\n", x);
    cantChangeVal(x);
    printf("x after can't function: %d\n", x); //It is the same x, doesn't change because functions are not changing the value,
                                        //It's changing the copy of the value they took.

    changeVal(&x);
    printf("x after change value function: %d\n", x);

    return 0;
}

int recursivePower(int input, int exponent){
    if(exponent < 1){
        return 1;
    }
    return input * recursivePower(input, exponent-1);
}

void cantChangeVal(int input){ //Can't change because the input is a copy of original input. You need pointers and references for this.
    input = 100;
}

void changeVal(int *input){ 
    *input = 100;
}
*/
/* Basically this is, when you're calling this function you use '&'. This guy says to the function, take this variable's address
instead of the variable instead. Function takes it with '*' and it says yes, I'm taking this variable address's input and using
the addressed variable itself. And can change the variable inside by saying '*input' because it is changing the address's var itself. */

int oldestValue();

int main(){
    int size = 7;
    int ages[] = {1, 5, 12, 3, 29, 15, 11};
    printf("%d\n", oldestValue(ages, size));

    return 0;
}

int oldestValue(int ages[], int size){
    int largest = ages[0];
    for(int i = 1; i < size; i++){//The reason we started it from 1 is that we already assing 0'th index at the start. So -1 operation.
        if(ages[i] > largest){
            largest = ages[i];
        }
    }
    return largest;
}