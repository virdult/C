#include "9.2libraries.h"

int recursivePower(int input, int exponent){
    if(exponent < 1){
        return 1;
    }
    return input * recursivePower(input, exponent-1);
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