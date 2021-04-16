#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 1000

typedef struct listElement{
    struct listElement *prev, *next;
    char text[1000];
}element;


element *head = NULL;
element *tail = NULL;
int size = 0;

void addElement();
void pushString();
void printList();
void deleteItem();
void endProgram();

int main(int argc, char *argv[]){
    
    int selection;
    do{
        selection = 0;
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
            printf("Please choose one of the listed options.\n");
            break;
        }
        fflush(stdin);
    }while(selection != 4);

    return 0;
}

void addElement(char *input){    
    element *newElement = (element *)malloc(sizeof(element));
    strcpy(newElement->text, input);
    newElement->next = NULL;
    if(head == NULL){
        tail = newElement;
        head = tail;
        head->prev = NULL;
        tail->next = NULL;
    }else{
        tail -> next = newElement;
        newElement -> prev = tail; 
        tail = newElement;   
    }
}

void pushString(){
    char buffer[BUFFER_SIZE];
    printf("Input text\n");
    //scanf("%s", buffer);
    fflush(stdin);
    fgets(buffer, BUFFER_SIZE, stdin);
    addElement(buffer);
    size++;
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
    if(scanf("%d", &itemLocation) && itemLocation > 0 && itemLocation <= size){
        element *cur = head;
        for(int i = 1; (i < itemLocation) && (cur != NULL); i++){
            cur = cur->next;
        }
        if(cur != NULL){
            if(cur == head && cur == tail){
                head = NULL;
                tail = NULL;
            }else if(cur == head){
                head = cur->next;
                cur->next->prev = NULL;
            }else if(cur == tail){
                tail = cur->prev;
                cur->prev->next = NULL;
            }else{
                cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
            }
            free(cur);
        }
        size--;
    }else{
        printf("Please choose a valid element to delete. There are currently %d elements to choose from\n", size);
    }
    
}

void endProgram(){
    if(head != NULL){
        element *temp = head->next;
        element *cur = head;
        while(cur->next != NULL){
            free(cur);
            cur = temp;
            temp = temp->next;
        }
        free(cur);
    }
}