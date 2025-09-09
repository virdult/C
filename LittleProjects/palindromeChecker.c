/*Reads a string from user. Checks if string is a palindrome(reads same forward and backward).
Writes a clear message if the input string a palindrome or not.
Your program should ignore capital letters(A and a should be same). 
Constraints: Max 100 letter. Implement the palindrome checker using both array and pointers. 
Display reversed string before checking*/
//Seems easy...
//I thought of 2 ways reversing a string: 
//1 -> Find the string length, if it's even, swap the first and the last and go +1 -1 and swap kinda thing.
//2 -> I guess we could do it kinda like bubblesort.
//I guess I'll do both of them and check because why not?

#include <stdio.h>
#include <string.h>


int main(){
    char word[101];//101 because of '\0'
    char reverseWord[101];
    printf("Welcome to the Palindrome Checker! Enter your word, we accept up to 100 letters: ");
    scanf(" %100s", &word); //printf("%s", word); //-> Seems fine.
    strcpy(reverseWord, word);
    int a = strlen(word);
    //The first way(Write in a func if you want to, I won't bother):
    /*
    if(a % 2 == 0){
        char temp[1];
        for(int i = 0; i < a/2; i++){
            temp[0] = reverseWord[i];
            reverseWord[i] = reverseWord[a - 1 - i];
            reverseWord[a - 1 - i] = temp[0];
        }
    }else{
        char temp[1];
        for(int i = 0; i < (a+1)/2; i++){
            temp[0] = reverseWord[i];
            reverseWord[i] = reverseWord[a - 1 - i];
            reverseWord[a - 1 - i] = temp[0];
        }
    }
    */
    //Second way(Again, write a func if you want to, I won't bother):
    char temp[1];
    for(int i = 0; i < a - 1; i++){
        for(int j = 0; j < a - i - 1; j++){
            temp[0] = reverseWord[j];
            reverseWord[j] = reverseWord[j + 1];
            reverseWord[j + 1] = temp[0];
        }
    }

    //Now for the part of comparing and printing:
    int same = strcmp(word, reverseWord);
    if(same == 0){
        printf("The reversed string: %s \n", reverseWord);
        printf("It is a Palindrome Word!\n");
    }else{
        printf("The reversed string: %s \n", reverseWord);
        printf("Not a Palindrome Word!\n");
    }

    return 0;
}