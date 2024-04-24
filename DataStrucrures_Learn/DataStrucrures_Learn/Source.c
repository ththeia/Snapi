#include "SingleList.h"
#include "DoublyList.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
    //// Create individual nodes
    //struct Node* first = createNode(10);
    //struct Node* second = createNode(20);
    //struct Node* third = createNode(30);

    //// Link nodes
    //first->next = second;
    //second->next = third;

    //// Print the linked list
    //printDataFromSL(first);

    //// Free the allocated memory for nodes
    //struct Node* current = first;
    //struct Node* next = NULL;
    //while (current != NULL) {
    //    next = current->next;
    //    free(current);
    //    current = next;
    //}

    //return 0;

    //Node* head = NULL;  // Start with an empty list

    //printf("Inserting elements at the beginning:\n");
    //insertAtBeginning(&head, 10); // List: 10
    //insertAtBeginning(&head, 20); // List: 20, 10
    //insertAtBeginning(&head, 30); // List: 30, 20, 10
    //printDataFromSL(head);

    //printf("Inserting elements at the end:\n");
    //insertionAtEnd(&head, 40);  // List: 30, 20, 10, 40
    //insertionAtEnd(&head, 50);  // List: 30, 20, 10, 40, 50
    //printDataFromSL(head);

    //printf("Inserting element at position 2 (zero-based index):\n");
    //insertAtPosition(25, 2);  // List: 30, 20, 25, 10, 40, 50
    //printDataFromSL(head);

    //printf("Deleting at beginning:\n");
    //deleteAtBeginning();       // List: 20, 25, 10, 40, 50
    //printDataFromSL(head);

    //printf("Deleting at position 3:\n");
    //deleteAtPosition(3);       // List: 20, 25, 10, 50
    //printDataFromSL(head);

    //printf("Deleting at end:\n");
    //deleteAtEnd();             // List: 20, 25, 10
    //printDataFromSL(head);

    //printf("List length: %d\n", findLength(head));

    //// Free all nodes to prevent memory leaks
    //while (head != NULL) {
    //    Node* temp = head;
    //    head = head->next;
    //    free(temp);
    //}

    //Person* head = NULL;

    //printf("Inserting at the beginning:\n");
    //insertAtBeginningDLL(&head, 25, "Alice");
    //traverseDLL(head);

    //printf("Inserting at the end:\n");
    //insertAtEndDLL(&head, 30, "Bob");
    //traverseDLL(head);

    //printf("Inserting at the beginning:\n");
    //insertAtBeginningDLL(&head, 22, "Carol");
    //traverseDLL(head);

    //printf("Inserting at position 2:\n");
    //insertAtPositionDLL(&head, 27, "Dave", 2);
    //traverseDLL(head);

    //printf("Deleting at the beginning:\n");
    //deleteAtBeginningDLL(&head);
    //traverseDLL(head);

    //printf("Deleting at position 1:\n");
    //deleteAtPositionDLL(&head, 1);
    //traverseDLL(head);

    //printf("Deleting at the end:\n");
    //deleteAtEndDLL(&head);
    //traverseDLL(head);

    //// Test for empty list after deletion
    //printf("Deleting at the beginning on empty list:\n");
    //deleteAtBeginningDLL(&head);
    //traverseDLL(head);

    //Node* head = NULL;
    //insertAtBeginning(&head, 10);
    //insertAtBeginning(&head, 20);
    //insertAtBeginning(&head, 30);

    //// Print the original list
    //printf("Original List: ");
    //printDataFromSL(head);

    //// Transform to doubly linked list and print
    //DNode* dblHead = toDoublyLinkedList(head);
    //printf("Doubly Linked List: ");
    //DNode* currentDNode = dblHead;
    //while (currentDNode != NULL) {
    //    printf("%d ", currentDNode->data);
    //    currentDNode = currentDNode->next;
    //}
    //printf("\n");

    //// Transform to doubly mirrored list and print
    //DNode* dblMirroredHead = toDoublyMirroredList(head);
    //printf("Doubly Mirrored List: ");
    //currentDNode = dblMirroredHead;
    //while (currentDNode != NULL) {
    //    printf("%d ", currentDNode->data);
    //    currentDNode = currentDNode->next;
    //}
    //printf("\n");

    //// Transform to circular list
    //toCircularList(&head);
    //printf("Circular List: ");
    //Node* current = head;
    //for (int i = 0; i < 10; i++) { // Limited to 10 prints to avoid infinite loop
    //    printf("%d ", current->data);
    //    current = current->next;
    //}
    //printf("\n");

    //// Transform to doubly circular list
    //DNode* dblCircularHead = toDoublyCircularList(head);
    //printf("Doubly Circular List: ");
    //currentDNode = dblCircularHead;
    //for (int i = 0; i < 10; i++) { // Limited to 10 prints to avoid infinite loop
    //    printf("%d ", currentDNode->data);
    //    currentDNode = currentDNode->next;
    //}
    //printf("\n");

    //// Display list in reverse
    //printf("List in Reverse: ");
    //printListReverse(head);
    //printf("\n");

    //// Queue operations (Enqueue, Display, Dequeue)
    //printf("Queue Operations:\n");
    //enqueue(&head, 40);
    //enqueue(&head, 50);
    //displayQueue(head);
    //printf("Dequeued element: %d\n", dequeue(&head));
    //printf("Queue after one dequeue: ");
    //displayQueue(head);


    Person* head = NULL; // Doubly linked list head pointer

    // Test data
    insertAtEndDLL(&head, 25, "Alice");
    insertAtEndDLL(&head, 30, "Bob");
    insertAtEndDLL(&head, 35, "Charlie");

    // Display original doubly linked list
    printf("Original Doubly Linked List:\n");
    traverseDLL(head);

    // Test transformToSingleList function
    transformToSingleList(&head);
    printf("Doubly List Transformed to Single List:\n");
    traverseDLL(head);

    // Test traverseReverseDLL function
    printf("Reversed Doubly Linked List:\n");
    traverseReverseDLL(head);

    // Test enqueue and dequeue functions
    enqueueD(&head, 40, "David");
    printf("After Enqueue:\n");
    traverseDLL(head);
    dequeueD(&head);
    printf("After Dequeue:\n");
    traverseDLL(head);

    // Test concatenateSingleToDoubly function
    Person* singleListHead = createPerson(45, "Emily");
    concatenateSingleToDoubly(&head, singleListHead);
    printf("Concatenated Single List to Doubly List:\n");
    traverseDLL(head);

    // Test concatenateDoublyLists function
    Person* head2 = NULL;
    insertAtEndDLL(&head2, 50, "Frank");
    insertAtEndDLL(&head2, 55, "Grace");
    printf("Second Doubly List:\n");
    traverseDLL(head2);
    concatenateDoublyLists(&head, &head2);
    printf("Concatenated Doubly Lists:\n");
    traverseDLL(head);

    // Test displayConcatenatedLists function
    displayConcatenatedLists(head);
    return 0;

}
