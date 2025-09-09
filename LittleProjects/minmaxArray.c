/*We'll try to find min or max or both in an array.*/
/*I don't want to use qsort but I'll add it in the end so I don't forget that it exists*/
/*We'll try the bubblesort thing*/
/*qSort is at the bottom!*/

#include <stdio.h>

void sortArray(int* array, int size, int(*compare)(int, int));
//int compare(int a, int b);
int increasingOrder(int a, int b);
int decreasingOrder(int a, int b);

void printArray(int* array, int size);

int main(){
    int numArray[] = {51, 16, -3, 6, 11, 17, 82, 68, 15};
    int size = sizeof(numArray) / sizeof(numArray[0]);

    sortArray(numArray, size, increasingOrder);
    printArray(numArray, size);

    printf("\n"); //Then also why not a print func

    sortArray(numArray, size, decreasingOrder);
    printArray(numArray, size);

    return 0;
}
/*
//We can't calc array size in function so we'll input from calling place
void sortArray(int* array, int size){//Could have written int array[] as well.
    int temp;
    for(size_t i = 0; i < size; i++){
        for(size_t j = 0; j < size - 1; j++){
            if(array[j] < array[j+1]){//Now if we change this < to >, the order changes.
                temp = array[j];      //Lets try to apply what I learned in here, function pointers!
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
*/
/*
int compare(int a, int b){
    if(a>b){
        return -1;
    }else{
        return 1;
    }//Now if we change the 1 and the -1's place, the order changes
}   //I guess instead of making this named compare and constantly changing the func, I'll make
    //2 functions, 1 named increasingOrder, 2 named decreasingOrder, call whichever I need in main in sortArray
*/

void sortArray(int* array, int size, int(*compare)(int, int)){
    int temp;
    for(size_t i = 0; i < size; i++){
        for(size_t j = 0; j < size - 1; j++){
            if(compare(array[j], array[j+1]) > 0){
                temp = array[j];      
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int increasingOrder(int a, int b){
    if(a>b){
        return -1;
    }else{
        return 1;
    }
}

int decreasingOrder(int a, int b){
    if(a>b){
        return 1;
    }else{
        return -1;
    }
}

void printArray(int* array, int size){
    for(size_t i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}

/*
//Below, the qSortCompare function so it compares and calls as we want. Again, we can make 2 seperate to call

int qSortCompare(const void* a, const void* b){ //We're using void because it's qsort. qsort can sort any array.
    int A = *((int*)a); //Typecasting to int* and getting value
    int B = *((int*)b);
    return A-B; //What happens here is it gets the values in the array when called in qsort. if A > B, it returns
}               //positive so it is increasing order. If you do return B-A; then it is reducing order.

int main(){
    //This is how you call qsort: -> You need to #include <stdlib.h> in order to use this function
    qsort(A, 8, sizeof(int), qSortCompare);
    return 0;
}
*/