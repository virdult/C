#include <stdio.h>
#include <math.h>
/*
int addition(int a, int b){
    return a + b;
}

void printHello(char *name){
    printf("Hello %s\n", name);
}

int main(){

    int c;

    int (*p)(int, int); 
    p = &addition; //Can also use p = addition; Directly.

    c = (*p)(2, 3); //De-referencing and executing the function, can use c = p(2, 3); Directly
    printf("%d\n", c);

    void (*ptr)(char*); //Creating the pointer to the function
    ptr = printHello; //Assigning it to the function
    ptr("Tamon"); //Calling the function


    return 0;
}
*/

/*Where and why use this: Function pointers can be passed as arguments to functions. And then, a function that 
would recieve a function pointer as an argument can call back the function that this pointer points to*/
/* EXAMPLE:
void A(){
    printf("Hello");
}
void B(void (*ptr)()){ //Function pointer as argument
    ptr(); //call-back function that "ptr" points to
}
int main(){
    
    //void (*p)() = A;
    //B(p);
    B(A); // A is a callback function



    return 0;
}
*/
//Real use in here:
int compare(int a, int b){
    if (a > b) return 1;
    else return -1;
}
int absoluteCompare(int a, int b){
    if (abs(a) > abs(b)) return 1; //Need #include <math.h> for using 'abs'
    else return -1;
}//What this does is it sorts in order without caring if number is negative or positive
/*Now, I have these 2 compare functions and I can use them when calling the bubblesort in main function
With this, I don't need to write 4 different sorting function in the code but just call it with these 
compare functions in main*/

int qSortCompare(const void* a, const void* b){ //We're using void because it's qsort. qsort can sort any array.
    int A = *((int*)a); //Typecasting to int* and getting value
    int B = *((int*)b);
    return A-B; //What happens here is it gets the values in the array when called in qsort. if A > B, it returns
}               //positive so it is increasing order. If you do return B-A; then it is reducing order.

/*This function can be changed and get used with 2 different styles. But if we need both, we'll need
almost a duplicate of the same function. In order to not do this, we'll use call-back function*/
void bubbleSort(int *A, int n, int(*compare)(int, int)){
    int i, j, temp;
    for(i = 0; i < n; i++){
        for(j = 0; j < n-1; j++){
            if(compare(A[j], A[j+1]) > 0){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            } //On each run of j[0] to j[n], the hightest unordered number gets ordered.
        }
    }
}

int main(){

    int A[] = {1, -2, 6, -12, 14, -17, -3, 9}; //WE WANT TO SORT IN INCREASING ORDER

    bubbleSort(A, 8, compare); //Calling the func

    for(size_t i = 0; i < 8; i++){ //Printing the last version
        printf("%d ", A[i]);
    }
    printf("\n");
    bubbleSort(A, 8, absoluteCompare);

    for(size_t i = 0; i < 8; i++){
        printf("%d ", A[i]);
    }

    //There is also something called qsort that is already defined in #include <stdlib.h>
    qsort(A, 8, sizeof(int), qSortCompare);

    return 0;
}