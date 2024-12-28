#include <stdio.h> 
#include <stdlib.h> 
// Structure to represent a doubly linked list node 
struct Node  
{ 

int data; 
struct Node* prev; 
struct Node* next; };
// Structure to represent a doubly linked list 
struct DoublyLinkedList  
{ 
struct Node* head; 
}; 
// Function to initialize an empty doubly linked list 
void initializeList(struct DoublyLinkedList* list)  
{ 
list->head = NULL; 
} 
// Function to insert a new node at the beginning of the list 
void insertAtBeginning(struct DoublyLinkedList* list, int data)  
{ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
     newNode->data = data; 
     newNode->prev = NULL; 
    newNode->next = list->head; 
 
    if (list->head != NULL)  
    { 
        list->head->prev = newNode; 
    } 
 
    list->head = newNode; 
} 
 
// Function to insert a new node at the end of the list 
void insertAtEnd(struct DoublyLinkedList* list, int data)  
{ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->prev = NULL; 
    newNode->next = NULL; 
 
    if (list->head == NULL)  
    { 
        list->head = newNode; 
        return; 
    } 
 
    struct Node* current = list->head; 
    while (current->next != NULL)  
    { 
        current = current->next; 
    } 
 
    current->next = newNode; 
    newNode->prev = current; 
} 
 
// Function to insert a new node at a given position 
void insertAtPosition(struct DoublyLinkedList* list, int data, int position)  
{ 
    if (position < 0)  
    { 
        printf("Invalid position.\n"); 
        return; 
    } 
 
    if (position == 0)  
    { 
        insertAtBeginning(list, data); 
        return; 
    } 
 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->prev = NULL; 
    newNode->next = NULL; 
 
    struct Node* current = list->head; 
    int currentPosition = 0; 
 
    while (current != NULL && currentPosition < position)  
    { 
        current = current->next; 
        currentPosition++; 
    } 
 
    if (current == NULL)  
    { 
        printf("Position out of range.\n"); 
        free(newNode); 
        return; 
    } 
 
    newNode->prev = current->prev; 
    newNode->next = current; 
     
    if (current->prev != NULL)  
    { 
        current->prev->next = newNode; 
    }  
    else  
    { 
        list->head = newNode; 
    } 
 
    current->prev = newNode; 
} 
 
// Function to delete a node with a given value from the list 
void deleteNode(struct DoublyLinkedList* list, int value)  
{ 
    struct Node* current = list->head; 
 
    while (current != NULL)  
    { 
        if (current->data == value)  
        { 
            if (current->prev != NULL)  
            { 
                current->prev->next = current->next; 
            }  
            else  
            { 
                list->head = current->next; 
            } 
 
            if (current->next != NULL)  
            { 
                current->next->prev = current->prev; 
            } 
 
            free(current); 
            return; 
        } 
 
        current = current->next; 
    } 
 
    printf("Value %d not found in the list.\n", value); 
} 
 
// Function to display the elements of the list 
void displayList(struct DoublyLinkedList* list)  
{ 
    struct Node* current = list->head; 
 
    if (current == NULL)  
    { 
        printf("The list is empty.\n"); 
        return; 
    } 
 
    printf("Doubly Linked List: "); 
    while (current != NULL)  
    { 
        printf("%d ", current->data); 
        current = current->next; 
    } 
    printf("\n"); 
} 
 
int main()  
{ 
    struct DoublyLinkedList myList; 
    initializeList(&myList); 
 
    insertAtBeginning(&myList, 10); 
    insertAtEnd(&myList, 20); 
    insertAtPosition(&myList, 15, 1); 
 
displayList(&myList); 
deleteNode(&myList, 20); 
displayList(&myList); 
return 0; 
} 