#include <stdio.h>
/*
int main(){
    int arr[] = {2, 4, 5, 1, 6};
    printf("%d\n", arr); //This gives us the address of arr
    printf("%d\n", &arr[0]); //Again, as it should be, gives the address of arr[0]
    printf("%d\n", &arr[1]); //Gives the address of the second guy on the array. which is in an it, 4 bytes later
    printf("%d\n", arr[0]); //gives the value of the first guy
    printf("%d\n", *arr); //Gives the value of the first guy again.
    return 0;
}
*/

int sumOfElements(int a[], int size){
    int sum = 0;
    //int size = sizeof(a) / sizeof(a[0]); //Calculating the size of array in the func for the for loop is NOT
    for(int i = 0; i < size; i++){         //going to work because we pass inside not the array but a pointer to
        sum += a[i];                       //the array.
    }
    return sum;
}
    //You can use this function to change the array since it is calling the array with it's pointer!
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int total = sumOfElements(arr, size);
    return 0;
}