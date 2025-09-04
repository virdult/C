#include <stdio.h>

int main(){
    /*
    //initialization -> comparison -> update
    int size = 6;
    int ages[] = {12, 23, 41, 92, 72, 54};
    int calculatedSize = sizeof(ages) / sizeof(ages[0]); //Gets the whole size of array and then divides it to one guy
                                                        //If you try to do this in a function, it's not gonna work.
                                                        //Because it will give you the pointer to the array! 
    for(size_t i = 0; i < calculatedSize; i++)
    {
        printf("ages[%d] = %d\n",i ,ages[i]);
    }

    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 5; j++){
            printf("%d %d \n", i, j);
        }
    }
    */
    int i = 10;
    while(i < 10){
        printf("%d ", i);
        i++;
    }
    printf("\n");

    int input;
    do
    {
        printf("Choose a number between 0-9: \n");
        scanf("%d", &input);
    } while (input < 0 || input > 9);
    





    return 0;
}