//Heap, Dynamic Memory Allocation
//for C -> malloc , calloc , realloc , free -> These are functions
//for C++ -> new , delete -> These are operators
#include <stdio.h>
#include <stdlib.h>


int main(){
    int a;//Goes on the stack
    int *p;
    p = (int*)malloc(sizeof(int)); //Goes on heap, it asks how much size do I need to alloc and you put it in the ()
    //malloc returns us a pointer. Now, this p is in stack and holding the address of our allocated memory in heap
    *p = 10;//Assigned in heap
    //p = (int*)malloc(sizeof(int)); Don't do this before free'ing the previous allocated space because you won't
    //be able to reach to that memory anymore...
    free(p);
    p = (int*)malloc(20*sizeof(int));//This is now allocated a 20 size int array on heap
    *p = 2;//Putting numbers in the array
    *(p+1) = 4;//Putting numbers in the array
    p[2] = 6;//Putting numbers in the array
    free(p);
    //Malloc gets that memory for you but doesn't initialize anything. There are some garbage value

    p = (int*)calloc(3, sizeof(int));//3 is number of elements, sizeof is the size per data.
    //what calloc do as different than malloc is, it assigns every single memory it takes for you with 0
    
    int *b = (int*)realloc(p, 2*sizeof(int));
    /*Here, we are extending the previously allocated p to double it's size with realloc. If it possible to 
    extend the previous block, then it will be extended to new size. Else, a new block is going to be allocated
    with the new size, old one will be copied and pasted in here, old one will be free'd.*/
    //Now, we can use p because we have another pointer to point.
    *p = (int*)realloc(b, (1/2)*sizeof(int));
    /*Here, we are shortening the previously allocated memory. What happens is that it will start free'ing
    from the last parts. You can use this to free() by writing: (int*)realloc(b, 0) since it will shorten it to 0*/
    //And now again, since we have p pointing to this memory we can reuse b
    *b = (int*)realloc(NULL, 5*sizeof(int));
    /*And as you can guess, now it is basically a malloc function, allocating something from scratch with the size 5*/
    free(p);
    free(b);
    
    return 0;
}