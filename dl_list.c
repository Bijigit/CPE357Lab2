#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct listElement{
    struct listElement *prev, *next;
    char text[1000];
}element;


element *head = NULL;
element *tail = NULL;

void addElement();
void pushString();
void printList();
void deleteItem();
void endProgram();

int main(int argc, char *argv[]){
    
    int selection;
    int isFirstElement = 1;
    do{
        printf("1 push string\n2 print list\n3 delete item\n4 end program\n");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
            pushString();
            break;
        case 2:
            printList();
            break;
        case 3:
            deleteItem();     
            break;
        case 4:
            endProgram();
            break;
        default:
            break;
        }
    }while(selection != 4);

    return 0;
}

void addElement(char *input){    
    element *newElement = (element *)malloc(sizeof(element));
    strcpy(newElement->text, input);
    if(head == NULL){
        tail = newElement;
        head = tail;
    }
    tail -> next = newElement;
    newElement -> prev = tail;
    
}

void pushString(){
    char buffer[1000];
    printf("Input text\n");
    scanf("%s", buffer);
    addElement(buffer);
}

void printList(){
    element *cur = head;
    while(cur != NULL){
        printf("%s", cur->text);
        cur = cur->next;
    }
}

void deleteItem(){
    int itemLocation;
    printf("Which item would you like to delete?\n");
    scanf("%d", &itemLocation);
    element *cur = head;
    for(int i = 1; (i < itemLocation) && (cur != NULL); i++){
        cur = cur->next;
    }
    if(cur != NULL){
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    }
}

void endProgram(){
    if(head != NULL){
        element *temp = head->next;
        element *cur = head;
        while(cur != NULL){
            free(cur);
            cur = temp;
            temp = temp->next;
        }
    }
}