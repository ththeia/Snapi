#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person Person;
struct Person {
    int age;
    char* name;
    Person* prev;
    Person* next;
};

void traverseDLL(Person* head);
void printPersonDetails(Person* p);
Person* createPerson(int age, char* name);
int findLengthDLL(Person* head);
void insertAtBeginningDLL(Person** head_ref, int age, char* name);
void insertAtEndDLL(Person** head_ref, int age, char* name);
void insertAtPositionDLL(Person** head_ref, int age, char* name, int position);
void deleteAtBeginningDLL(Person** head_ref);
void deleteAtPositionDLL(Person** head_ref, int position);
void deleteAtEndDLL(Person** head_ref);
void transformToCircularList(Person** head_ref);


void transformToSingleList(Person** head_ref);
void traverseReverseDLL(Person* tail);
void enqueueD(Person** head_ref, int age, char* name);
void dequeueD(Person** head_ref);
void concatenateSingleToDoubly(Person** head_doubly, Person* head_single);
void concatenateDoublyLists(Person** head1, Person** head2);
void displayConcatenatedLists(Person* head_concatenated);

void traverseDLL(Person* head) {
    Person* current = head;
    while (current != NULL) {
        printPersonDetails(current);
        current = current->next;
    }
    printf("\n");
}

void printPersonDetails(Person* p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

Person* createPerson(int age, char* name) {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    if (newPerson == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    newPerson->age = age;
    // Allocate memory for the name and copy the string
    newPerson->name = (char*)malloc(strlen(name) + 1);  // +1 for null terminator
    if (newPerson->name == NULL) {
        printf("Error: Memory allocation for name failed.\n");
        free(newPerson);  // Free the previously allocated Person structure
        return NULL;
    }
    strcpy_s(newPerson->name, strlen(name) + 1, name);;
    newPerson->prev = NULL;
    newPerson->next = NULL;
    return newPerson;
}

int findLengthDLL(Person* head) {
    int length = 0;
    Person* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void insertAtBeginningDLL(Person** head_ref, int age, char* name) {
    Person* new_person = createPerson(age, name);
    if (new_person == NULL) return;
    new_person->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->prev = new_person;
    }
    *head_ref = new_person;
}

void insertAtEndDLL(Person** head_ref, int age, char* name) {
    Person* new_person = createPerson(age, name);
    if (new_person == NULL) return;

    if (*head_ref == NULL) {
        *head_ref = new_person;
        return;
    }

    Person* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_person;
    new_person->prev = last;
}

void insertAtPositionDLL(Person** head_ref, int age, char* name, int position) {
    if (position == 0) {
        insertAtBeginningDLL(head_ref, age, name);
        return;
    }

    Person* new_person = createPerson(age, name);
    if (new_person == NULL) return;

    Person* current = *head_ref;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is beyond the end of the list.\n");
        free(new_person);
        return;
    }

    new_person->next = current->next;
    new_person->prev = current;
    if (current->next != NULL) {
        current->next->prev = new_person;
    }
    current->next = new_person;
}

void deleteAtBeginningDLL(Person** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete from the beginning.\n");
        return;
    }

    Person* to_delete = *head_ref;
    *head_ref = (*head_ref)->next;
    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }
    free(to_delete->name);
    free(to_delete);
}

void deleteAtPositionDLL(Person** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete from a specific position.\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginningDLL(head_ref);
        return;
    }

    Person* current = *head_ref;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is beyond the end of the list.\n");
        return;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    free(current->name);
    free(current);
}

void deleteAtEndDLL(Person** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    Person* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    if (last->prev != NULL) {
        last->prev->next = NULL;
    }
    else {
        *head_ref = NULL;  // If this was the only node in the list
    }

    free(last->name);
    free(last);
}

//Transform Doubly List into a Circular List :

void transformToCircularList(Person** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot transform to circular list.\n");
        return;
    }

    Person* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = *head_ref;
    (*head_ref)->prev = last;
}

//Transform Doubly into a Single Linked List:
void transformToSingleList(Person** head_ref) {
    Person* current = *head_ref;
    while (current != NULL) {
        current->prev = NULL;
        current = current->next;
    }
}

//Display Doubly Linked List in Reverse :

void traverseReverseDLL(Person* tail) {
    Person* current = tail;
    while (current != NULL) {
        printPersonDetails(current);
        current = current->prev;
    }
    printf("\n");
}
//Transform Doubly List into a Queue:
// Enqueue at the end of the list
void enqueueD(Person** head_ref, int age, char* name) {
    insertAtEndDLL(head_ref, age, name);
}

// Dequeue from the beginning of the list
void dequeueD(Person** head_ref) {
    deleteAtBeginningDLL(head_ref);
}

//Concatenate a Single List to a Doubly List :

void concatenateSingleToDoubly(Person** head_doubly, Person* head_single) {
    if (*head_doubly == NULL) {
        *head_doubly = head_single;
        return;
    }

    Person* last = *head_doubly;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = head_single;
    head_single->prev = last;
}

//Concatenate Two Doubly Lists :

void concatenateDoublyLists(Person** head1, Person** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }

    if (*head2 == NULL) {
        return;
    }

    Person* last1 = *head1;
    while (last1->next != NULL) {
        last1 = last1->next;
    }

    last1->next = *head2;
    (*head2)->prev = last1;
}

//Display Concatenated Doubly Lists :

void displayConcatenatedLists(Person* head_concatenated) {
    traverseDLL(head_concatenated);
}
//swap nodes without swaping the data 
void swapNodes(Person** head_ref, Person* node1, Person* node2) {
    if (node1 == NULL || node2 == NULL || node1 == node2)
        return;

    // Handle special case if one of the nodes is the head
    if (*head_ref == node1)
        *head_ref = node2;
    else if (*head_ref == node2)
        *head_ref = node1;

    // Adjust the previous pointers of adjacent nodes
    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->prev != NULL)
        node2->prev->next = node1;

    // Adjust the next pointers of adjacent nodes
    if (node1->next != NULL)
        node1->next->prev = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    // Swap next and prev pointers of the nodes to swap them
    Person* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;
}