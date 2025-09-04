#include <stdio.h>
#include <stdbool.h>

int main(){
    int age = 17;
    double money = 30000;
    if(age > 17 && money > 25000){ // && || ! ->    ! Not   ,    && And   ,    || Or
        printf("This is true!\n");
    }else{ // else if(condition){}
        printf("This is false!\n");
    }

    //Switch
    int menuChoice = 1;
    switch(menuChoice){
        case 0:
        case 1:
        case 2:
            printf("Case 0, 1 or 2\n"); //Can be used like this, if 0 or 1 or 2, prints this.
            break;
        case 3:
            printf("Case 3\n");
            break;
        default:
            printf("Default\n");
            break;
    }

    //TERNARY OPERATOR!
    double balance = 5000;
    balance > 0 ? print("You have money!\n") : printf("You don't have money!\n");
    bool hasMoney;
    hasMoney = balance > 0 ? 1 : 0; //hasMoney = if balance > 0, 1(true), else 0(false)
    return 0;
}