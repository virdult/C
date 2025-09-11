/*Contact List. Name(Max30char), PhoneNumber(max15chars).
Program should:
    Ask the user how many contacts they want to store (max 100).
    Dynamically allocate memory for the contact list.
    Let the user input all contacts.
    Print out all stored contacts in a clean tabular format.
Extras:
    Add a function to search for a contact by name.
    Add a function to delete a contact.
    Add a function to free all allocated memory properly before exit.*/
//I'll need struct for this but I haven't learned it yet... Let's try though, I have my crash course infos.
//I need both malloc + struct so I'll try this tomorrow...
//Should have started yesterday. No more tomorrows from now on, also, I want to make this so it puts the inputs
//In a file with fstream or whatever it is in C. But I guess I'll do that in contactList2.C file. I'll keep this
//as it is right now.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char number[16];
}contact;

void searchContactName(contact* contactList, int maxContact);
void searchContactNumber(contact* contactList, int maxContact);
void deleteContact(contact* contactList, int maxContact);
void menu(contact* contactList, int maxContact);

int main(){

    int maxContact;
    do{
        printf("How many contacts do you want to store?\n");
        scanf("%d", &maxContact);
    }while(maxContact <= 0 || maxContact > 100);
    //It needs to be an array of contacts. It needs to allocate memory.
    //Or it can create 100 different structs with a for loop. I guess array should work better.
    //Is this going to be a 2 dimensional array since struct have more than 1 input?
    
    //Allocating memory:
    contact* contactList = malloc(maxContact*sizeof(contact));

    //Getting contact inputs:
    for(int i = 0; i < maxContact; i++){
        printf("Enter contact[%d]'s name and number: \n", i);
        scanf("%30s %15s", contactList[i].name, contactList[i].number);
    }

    //Printing Contact List
    for(int i = 0; i < maxContact; i++){
        printf("No: %-2d's -> Name: %-30s | Number: %-16s\n", i, contactList[i].name, contactList[i].number);
    }

    menu(contactList, maxContact);

    free(contactList);
    return 0;
}
/*
This was the first menu function I made but I guess it doesn't gets freed when calling another func and the other
function calls this again so there are an unlimited amount of this guy recreated.
To avoid overflow, we can make a do while loop in menu I guess. I'll do it right below this comment line and 
corrupted menu.
void menu(contact* contactList, int maxContact){
    int choice;
    printf("If you want to quit, type 0.\n");
    printf("If you want to search for contact; type 1 if you know the name, 2 if you know the phone number.\n");
    printf("If you want to delete a person from list, type 3.\n");
    scanf(" %d", &choice);
    if(choice == 1){
        searchContactName(contactList, maxContact);
    }else if(choice == 2){
        searchContactNumber(contactList, maxContact);
    }else if(choice == 3){
        deleteContact(contactList, maxContact);
    }else{//This also contains choice == 0 so it will leave the function cycle and end the program.
        return;
    }
}
*/
void menu(contact* contactList, int maxContact){
    int choice;
    do{
        printf("\n--- MENU ---\n");
        printf("0 - Quit\n");
        printf("1 - Search by name\n");
        printf("2 - Search by number\n");
        printf("3 - Delete a contact\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        if(choice == 1){
            searchContactName(contactList, maxContact);
        }else if(choice == 2){
            searchContactNumber(contactList, maxContact);
        }else if(choice == 3){
            deleteContact(contactList, maxContact);
        }
    }while(choice != 0);
}


void searchContactName(contact* contactList, int maxContact){
    char tempName[31];
    printf("Type the persons name you want to search: \n");
    scanf(" %31s", tempName); //The reason we don't use & is tempName is already an array so it decays to pointer
    for(int i = 0; i < maxContact; i++){
        if(strcmp(contactList[i].name, tempName) == 0){
            printf("The person you're looking for is at list number %d\n", i);
        }else{
            printf("Person not found.\n");
        }
    }//Try something new with a while loop, put the strcmp in the while! This is not working as how I intended
    //menu(contactList, maxContact); -> Not necessary for the correct version of the menu
}
void searchContactNumber(contact* contactList, int maxContact){
    char tempNumber[16];
    printf("Type the persons phone number you want to search: \n");
    scanf(" %16s", tempNumber);
    for(int i = 0; i < maxContact; i++){
        if(strcmp(contactList[i].number, tempNumber) == 0){
            printf("The person you're looking for is at list number %d\n", i);
        }else{
            printf("Person not found.\n");
        }
    }
    //menu(contactList, maxContact);
}
void deleteContact(contact* contactList, int maxContact){
    int contactNumber;
    do{
    printf("Enter the list number of the person you want to delete from Contact List.\n");
    scanf(" %d", &contactNumber);
    }while(contactNumber < 0 || contactNumber > maxContact);
    *contactList[contactNumber].name = '\0';
    *contactList[contactNumber].number = '\0';
    //menu(contactList, maxContact);
}