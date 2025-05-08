#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;          // Data part of the node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); // Allocate memory for a new node
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;  // Set the data
    newNode->next = NULL;   // Initialize the next pointer to NULL (end of the list)
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head; // Temporary pointer to traverse the list
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the current node's data
        temp = temp->next;            // Move to the next node
    }
    printf("NULL\n");  // Indicating the end of the list
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);  // Create a new node
    newNode->next = *head;                    // Link new node to the current head
    *head = newNode;                          // Update head to the new node
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);  // Create a new node
    if (*head == NULL) {                      // If the list is empty
        *head = newNode;                      // New node becomes the head
        return;
    }
    struct Node* temp = *head;                // Temporary pointer to traverse the list
    while (temp->next != NULL) {               // Traverse until the last node
        temp = temp->next;
    }
    temp->next = newNode;                     // Link last node to the new node
}

// Function to delete the first node
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {  // If the list is empty
        printf("The list is already empty.\n");
        return;
    }
    struct Node* temp = *head;  // Temporary pointer to the first node
    *head = temp->next;         // Move the head to the next node
    free(temp);                 // Free the memory of the deleted node
}

// Main function to test the linked list operations
int main() {
    struct Node* head = NULL; // Start with an empty list

    // Insert elements at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printf("List after inserting at the beginning:\n");
    printList(head);

    // Insert elements at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("List after inserting at the end:\n");
    printList(head);

    // Delete the first node
    deleteFirstNode(&head);

    printf("List after deleting the first node:\n");
    printList(head);

    return 0;
}
