/*We'll print the multiplication table up to n*/
/*It's done already but I want to make it look good. There used to be something in C++ that we set width or something
Let's see if I can find it*/
/*%3d is working for example but it starts writing my number from right instead of left...*/
/*Alright %-3d is making it start writing from left ^^*/
//DONE!

#include <stdio.h>

void multTable(int n);

int main(){
    //I don't know what the does that mean ^^
    int n = 1;
    printf("Enter the number that you want to get multiplication table printed until: \n");
    scanf("%d", &n);
    multTable(n);


    return 0;
}

void multTable(int n){
    int print;
    for(size_t i = 1; i <= n; i++){
        for(size_t j = 1; j <= n; j++){
            print = i * j;
            printf("%-2d *  %-2d =  %-4d  ", j, i, print);
        }
        printf("\n");
    }
}