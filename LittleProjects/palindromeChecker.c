/*Reads a string from user. Checks if string is a palindrome(reads same forward and backward).
Writes a clear message if the input string a palindrome or not.
Your program should ignore capital letters(A and a should be same). 
Constraints: Max 100 letter. Implement the palindrome checker using both array and pointers. 
Display reversed string before checking*/
//Seems easy...

#include <stdio.h>



int main(){
    char word[101];//101 because of '\0'
    printf("Welcome to the Palindrome Checker! Enter your word, we accept up to 100 letters: ");
    scanf(" %100s", &word); //printf("%s", word); //-> Seems fine.


    return 0;
}