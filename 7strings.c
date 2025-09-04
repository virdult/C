#include <stdio.h>
#include <string.h>

int main(){

    printf("What is your name?\n");
    char name[10]; // Need to reserve 1 character for null terminator '\0'
    scanf("%19s", name); 

    int letter = 0;
    while(name[letter] != '\0'){
        letter++;
    }
    printf("Size: %d\n", letter);
    printf("Size: %lu\n", strlen(name)); 

    if(strcmp(name, "Umut") == 0){ //What happens is if those 2 are same, strcmp returns 0, so 0==0 becomes tru and if starts
        printf("You get access!\n");
    }
    char copy[20];
    strcpy(copy, name); //Copying a string
    printf("value of copy: %s\n", copy);

    char lastName[] = "Sener";
    strcat(copy, lastName);
    printf("Full name: %s\n", copy);

    return 0;
}