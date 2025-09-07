#include <stdio.h>
#include "9.2libraries.h"

int main(){

    int x = 5, exponent = 3;
    int answer = recursivePower(x, exponent);
    printf("Answer: %d\n", answer);

    int size = 7;
    int ages[] = {1, 5, 12, 3, 29, 15, 11};
    printf("%d\n", oldestValue(ages, size));

    return 0;
}

//On terminal, type and enter this first: gcc -c 9.1libraries.c
//And then type and enter this: gcc -c 9.0librariesMain.c
//and then at last, type and enter: gcc 9.0librariesMain.o 9.1libraries.o