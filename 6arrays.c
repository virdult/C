#include <stdio.h>

int main(){

    /*
    int size = 8;
    int ages[] = {1, 23, 12, 43, 10, 4};
    ages[2] = 50; // 12 -> 50
    //first element - index 0 -> 0 to 9

    for(size_t i = 0; i < size; i++){
        printf("%d ", ages[i]);
    }
    */

    //const int rows = 3;     //Have to make this a constant so multidimensional array works! But const int does not work as well
    //const int columns = 4; //Because in C, const only makes the variable read-only, it is still not compile-time constant
    //#define rows 3
    //#define columns 4 //Either use this #define to make it work, or use enum{} -> No ';' after define
    enum { rows = 3, columns = 4};

    int studentGrades[rows][columns] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%d ", studentGrades[i][j]);
        }
        printf("\n");
    }

    return 0;
}