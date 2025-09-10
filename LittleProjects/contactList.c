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

#include <stdio.h>

typedef struct
{
    char name[31];
    char number[16];
}contact;

int main(){



    return 0;
}