#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;
    head=newNode;
    return head;
}

// Insert a node at the end of the list
struct Node *insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}


// Delete a node with given value
struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    do {
        if (current->data == value) {
            if (prev != NULL) {
                prev->next = current->next;
                free(current);
                return head;
            } else {
                struct Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                free(head);
                return temp->next;
            }
        }

        prev = current;
        current = current->next;
    } while (current != head);

    printf("Value not found in the list.\n");
    return head;
}

// Search for a node with given value
void search(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    int found = 0;
    int position = 0;

    do {
        position++;
        if (current->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            found = 1;
        }
        current = current->next;
    } while (current != head);

    if (!found) {
        printf("Value not found in the list.\n");
    }
}

// Display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    printf("Circular Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

// Update a node with given value
void update(struct Node* head, int oldValue, int newValue) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    int found = 0;

    do {
        if (current->data == oldValue) {
            current->data = newValue;
            printf("Value updated successfully.\n");
            found = 1;
        }
        current = current->next;
    } while (current != head);

    if (!found) {
        printf("Value not found in the list.\n");
    }
}

// Free memory allocated for the circular linked list
void freeList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* temp = NULL;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

int main() {
    struct Node* head = NULL;
    int choice, value, oldValue, newValue;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Search for a Node\n");
        printf("5. Display the List\n");
        printf("6. Update a Node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Enter value to update old value: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                update(head, oldValue, newValue);
                break;
            case 7:
                freeList(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
//stack
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the stack
struct Stack {
    struct Node* top;
};

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to the stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an invalid value
    }
    struct Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedData;
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from the stack\n", pop(stack));
    printf("%d popped from the stack\n", pop(stack));
    printf("%d popped from the stack\n", pop(stack));
    printf("%d popped from the stack\n", pop(stack)); // Trying to pop from an empty stack

    return 0;
}
//singly linked list
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node 
{
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a new node at a specific position in the linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the first node in the linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node in the linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node from a specific position in the linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Invalid position\n");
        return head;
    }

    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Function to display all the elements in the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to search for an element in the linked list and return its position
int searchElement(struct Node* head, int key) {
    int position = 1;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

// Function to update the value of a node at a specific position in the linked list
struct Node* updateElement(struct Node* head, int position, int newData) {
    struct Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return head;
    }

    current->data = newData;
    return head;
}

// Main function to test the linked list implementation
int main() {
    struct Node* head = NULL;

    // Insert elements at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 12);

    // Display the linked list
    printf("Linked List after insertions at the beginning: ");
    displayList(head);

    // Insert elements at the end
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 9);

    // Display the linked list
    printf("Linked List after insertions at the end: ");
    displayList(head);

    // Insert at a specific position
    head = insertAtPosition(head, 15, 3);

    // Display the linked list
    printf("Linked List after insertion at position 3: ");
    displayList(head);

    // Delete from the beginning
    head = deleteFromBeginning(head);

    // Display the linked list
    printf("Linked List after deletion from the beginning: ");
    displayList(head);

    // Delete from the end
    head = deleteFromEnd(head);

    // Display the linked list
    printf("Linked List after deletion from the end: ");
    displayList(head);

    // Delete at a specific position
    head = deleteAtPosition(head, 2);

    // Display the linked list
    printf("Linked List after deletion at position 2: ");
    displayList(head);

    // Search for an element
    int key = 5;
    int position = searchElement(head, key);
    if (position != -1) {
        printf("Element %d found at position %d\n", key, position);
    } else {
        printf("Element %d not found in the list\n", key);
    }

    // Update an element at a specific position
    head = updateElement(head, 2, 8);

    // Display the linked list
    printf("Linked List after updating element at position 2: ");
    displayList(head);

    return 0;
}
//queue using linked list
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node 
{
    int data;
    struct Node* next;
};

// Structure to represent a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow: Cannot dequeue from an empty queue.\n");
        return -1; // Error value
    }
    
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    
    free(temp);
    
    return data;
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    
    struct Node* current = queue->front;
    printf("Queue elements: ");
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    printf("Dequeued element: %d\n", dequeue(queue));
    
    display(queue);

    printf("Is the queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    return 0;
}
