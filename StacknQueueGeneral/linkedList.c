#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    char description[101];
    struct Node* next;  
}Node;

Node* createNode(int id, const char* description ){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        perror("malloc failed!");
        exit(EXIT_FAILURE);
    }

    newNode->id = id;
    strcpy(newNode->description, description);
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, int id, char* description){
    Node* newNode = createNode(id, description);
    if(!head) return newNode; //Empty List

    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int id){
    if(!head) return NULL;

    //Delete head
    if(head->id == id){
        Node* temp = head->next;
        free(head);
        return temp;
    }


    Node* curr = head;
    while(curr->next && curr->next->id != id) curr = curr->next;

    if(curr->next){
        Node* temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    return head;
}

void printNodes(Node* head){
    Node* temp = head;
    while(temp){
        printf("Node ID: %d, Description: %s\n", temp->id, temp->description);
        temp = temp->next;  
    }
    printf("\n");
}

int main(){
    Node* nodeList = NULL;
    int choice, id;
    char desc[100];

    while (1) {
        printf("1. Add Task\n2. Delete Task\n3. Show Tasks\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        if (choice == 1) {
            printf("Enter Task ID: ");
            scanf("%d", &id);
            getchar(); // consume newline
            printf("Enter Task Description: ");
            fgets(desc, 100, stdin);
            desc[strcspn(desc, "\n")] = 0; // remove newline
            nodeList = addNode(nodeList, id, desc);

        } else if (choice == 2) {
            printf("Enter Task ID to delete: ");
            scanf("%d", &id);
            nodeList = deleteNode(nodeList, id);

        } else if (choice == 3) {
            printNodes(nodeList);

        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    // Free memory
    while (nodeList) {
        Node* temp = nodeList;
        nodeList = nodeList->next;
        free(temp);
    }

    return 0;
}