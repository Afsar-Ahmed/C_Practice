#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Node structure for a doubly-linked list
typedef struct node {
    int number;         // The data in this node
    struct node* next;  // Pointer to the next node
    struct node* prev;  // Pointer to the previous node
} Node;

static Node* head = NULL;
static Node* tail = NULL;

Node* createNode(int num) {
	Node* nd = malloc(sizeof(Node));
	nd->number = num; // Put the value in the node
	nd->next = NULL;  // Next pointer is null for now
	nd->prev = NULL;  // Prev pointer is null for now
	return nd;    // Return a pointer to the new node
}

void printList(Node* nd, bool forward) {
    // Loop as long as there are more nodes
    Node* temp = nd;
    while (temp != NULL) {
        printf("%d\n", temp->number);
        if (forward)
            temp = temp->next; // Go to the next node
        else
            temp = temp->prev; // Go to the previous node
    }
}

void appendNode(int num) {
    Node* nd = createNode(num);  // Allocate new node 'nd'
    if (head == NULL) {   // If list is empty
        head = nd;   // New node is the head (and tail)
    } else {
        tail->next = nd; // Make old tail node point at new one
        nd->prev = tail; // Make new node point back at old tail
    }
    tail = nd;   // New node becomes the new tail
}

// Insert a new node in the middle of the list, or at the end.
void insertNode(Node* loc, int num) {
    Node* nd = createNode(num);  // Allocate new node 'nd'
    if (loc->next != NULL) {
        loc->next->prev = nd; // Node after loc points back to nd
    }
    nd->next = loc->next; // New node points to node after loc
    loc->next = nd;  // loc now points to the new node
    nd->prev = loc;  // New node points back to loc
    if (loc == tail) { // If at end, new node becomes new tail
        tail = nd;  
    }
}

void deleteNode(Node* nd) {
    if (nd == head) {   // Deleting head node?
        head = nd->next;
    }
    if (nd == tail) {   // Deleting tail node?
        tail = nd->prev;
    }
    if (nd->next != NULL) {   // Is there a next node?
        nd->next->prev = nd->prev;
    }
    if (nd->prev != NULL) {   // Is there a previous node?
        nd->prev->next = nd->next;
    }
    free(nd);  // Deallocate the deleted node
}

int main(int argc, char** argv) {
    const int size = 5;  // The list size

    // Input numbers and add them at the tail of the list
    printf("Please enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        int num = 0;
        scanf("%d", &num);

        appendNode(num);
    }
    
    // Insert the number 42 as the second item in the list
    insertNode(head, 42);

    printf("The list forwards:\n");
    printList(head, true/*forward*/);

    printf("The list backwards:\n");
    printList(tail, false/*backward*/);
    
    // Delete two nodes
    deleteNode(head);
    deleteNode(tail);
    
    printf("The list forwards after deleting:\n");
    printList(head, true/*forward*/);

}