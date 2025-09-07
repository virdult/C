#include <stdio.h>

int main(){
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    //This is basically 2 arrays side by side blocked together.
    //The memory addresses are for example 400, 404, 408 for the arr[0]
    //and for arr[1] they are 412, 416, 420
    //So think it as it gets one row as 1 and 1 row as 1 side by side.

    //int *p = arr; -> This will give a compilation error because it is not pointing to an integer but to a 
    //1D array of 3 integers such as [1, 2, 3] all together

    int (*p)[3] = arr; //This will work
    printf("arr: %d\n", arr); //Will give the address of the array's first integer
    printf("*arr: %d or arr[0]: %d or &arr[0][0]: %d\n", *arr, arr[0], &arr[0][0]); //Again, all will give address
    printf("if we print arr[1]: %d, we'll jump 3 integers worth of address.\n", arr[1]);
    //And if I want to jump 1 integer only, I can use
    printf("*(arr + 1) + 2: %d or arr[1] + 2: %d or &arr[1][2]: %d\n", *(arr + 1) + 2, arr[1] + 2, &arr[1][2]);
    //The reason you're getting a address even after dereferencing with * is that you dereference the array's pointer
    //So that you still get the address of that pointer(array's first number). It's a bit complicated. yes.

    /*TO SUM UP EVERYTHING. PRINT ARRAY IS GOING TO GIVE YOU THE ADDRESS OF THE ARRAY'S START WHICH IS [0][0]
    AND THEN THE PRINT ARRAY[0] WILL STILL GIVE YOU THE ADDRESS OF THE START OF THE ARRAY BECAUSE ARRAY[0] IS STILL AN ARRAY
    AND THEN *ARRAY WILL AGAIN GIVE THE SAME ADDRESS BECAUSE WE HAVE THE B[0] ARRAY NOW. GOOD LUCK*/

    //These are same: arr[i][j] -> *(arr[i] + j) -> *(*(arr + i) + j)
    //Basically a multi dimentional array is an array of arrays. And also when you call an array, you call it's address.

    //I DON'T PLAN TO EXPLAIN 3 DIMENSIONAL. IF YOU EVER NEED AN EXPLANATION HERE'S THE TIME AND LINK: 2:02:32
    //https://www.youtube.com/watch?v=zuegQmMdy8M

    return 0;
}