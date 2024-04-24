#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Node {
	int data;
	Node* next;
}Node;

typedef struct DNode {
	int data;
	struct DNode* prev;
	struct DNode* next;
} DNode;

void traversalSL(Node* head);
void printNodeData(int data);
void printDataFromSL(Node* head);
Node* createNode(int data);
int findLength(Node* head);
void insertAtBeginning(Node** head_ref, int new_data);
void insertionAtEnd(Node** head_ref, int new_data);
void insertAtPosition(int value, int position);
void deleteAtBeginning();
void deleteAtPosition(int position);
void deleteAtEnd();
DNode* toDoublyLinkedList(Node* head);
DNode* toDoublyMirroredList(Node* head);
void enqueue(Node** head_ref, int new_data);
int dequeue(Node** head_ref);
void toCircularList(Node** head_ref);
DNode* toDoublyCircularList(Node* head);
void concatenateLists(Node** head1, Node* head2);
void printListReverse(Node* head);
void displayQueue(Node* head);

//Traverse a simple linked list

void traversalSL(Node* head) {
	//We start from the head
	Node* current = head;
	//Travere the linked list until reaching the end -- nullptr
	while (current != NULL) {
		printf("%d", current->data);
		//then we move to the next node
		current = current->next;
	}

	printf("\n");

}

//Function to print data from a node
void printNodeData(int data) {
	printf("%d ", data);
}

void printDataFromSL(struct Node* head) {
	// Start from the head of the list
	struct Node* current = head;
	// Traverse the linked list until reaching the end (NULL)
	while (current != NULL) {
		// Use the helper function to print the data of the current node
		printNodeData(current->data);
		// Move to the next node
		current = current->next;
	}
	printf("\n");
}

Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Error: Memory allocation failed.\n");
		return NULL; // Return NULL if memory allocation fails
	}
	newNode->data = data; // Set the data part of the node
	newNode->next = NULL; // Initially, the next pointer should be NULL
	return newNode;
}

//Function to find the lenght of the single linked list
int findLength(Node* head) {
	int length = 0;
	//start from the head
	Node* current = head;
	while (current != NULL) {
		//traverse the lisn and increment the length
		length++;
		current = current->next;
	}
	return length;
}

void insertAtBeginning(Node** head_ref, int new_data) {
	//allocate memory for the new node
	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL) {
		printf("Failed to allocate memory for new node\n");
		return;
	}
	//put data in the node
	new_node->data = new_data;
	//make the old head be the second node
	new_node->next = *head_ref;
	//make the head point to the new node
	*head_ref = new_node;
}

void insertionAtEnd(Node** head_ref, int new_data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("Failed to allocate memory for new node\n");
		return;
	}
	//intialise the new node
	new_node->data = new_data;
	new_node->next = NULL;//make the new node point to null as it is the last node in the list

	//if the linked list is empty make the node as head
		if(*head_ref == NULL) {
			*head_ref = new_node;
			return;
		}
	//else traverse till last ode
		Node* last = *head_ref;
		while (last->next != NULL) {
			last = last->next;
		}
	//change the next of last node
		last->next = new_node;
	
}

//insert at a specific position
Node* head = NULL;

void insertAtPosition(int value, int position) {
	//allocate memory for the new node
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("Failed to allocate memory for new node\n");
		return;
	}
	//If position is 0 or the list is empty, insert at the beginning
		if (position == 0 || head == NULL) {
			new_node->next = head;
			head = new_node;
			return;
		}

	// traverse to the node just before the specified position
	Node* current = head;
	for (int i = 1; i < position && current->next != NULL; ++i) {
		current = current->next;
	}

	// 4. Insert the new node at the specified position
	new_node->next = current->next;
	current->next = new_node;
}

void deleteAtBeginning() {
	// If the list is empty, do nothing
	if (head == NULL) {
		printf("List is empty. Cannot delete from the beginning.\n");
		return;
	}

	// Store the current head in a temporary variable
	Node* temp = head;

	// Update the head to the next node
	head = head->next;

	// Delete the old head node
	free(temp);
}

void deleteAtPosition(int position) {
	// If the list is empty, do nothing
	if (head == NULL) {
		printf("List is empty. Cannot delete from a specific position.\n");
		return;
	}

	// If deleting the head node
	if (position == 0) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return;
	}

	// Traverse to the node just before the specified position
	Node* current = head;
	for (int i = 1; i < position && current->next != NULL; ++i) {
		current = current->next;
	}

	// If position is beyond the end of the list, do nothing
	if (current->next == NULL) {
		printf("Position is beyond the end of the list. Cannot delete.\n");
		return;
	}

	// Delete the node at the specified position
	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);
}

void deleteAtEnd() {
	// If the list is empty, do nothing
	if (head == NULL) {
		printf("List is empty. Cannot delete from the end.\n");
		return;
	}

	// If there is only one node, delete it and set head to NULL
	if (head->next == NULL) {
		free(head);
		head = NULL;
		return;
	}

	// Traverse to the second last node
	Node* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	// Delete the last node
	free(current->next);
	current->next = NULL;
}
// transform SL into a Doubly Linked List
DNode* toDoublyLinkedList(Node* head) {
	DNode* newHead = NULL;
	DNode* last = NULL;
	Node* current = head;
	while (current != NULL) {
		DNode* newNode = (DNode*)malloc(sizeof(DNode));
		if (newNode == NULL) {
			printf("Memory allocation failed.\n");
			return NULL;
		}
		newNode->data = current->data;
		newNode->prev = last;
		newNode->next = NULL;
		if (last != NULL) {
			last->next = newNode;
		}
		else {
			newHead = newNode;
		}
		last = newNode;
		current = current->next;
	}
	return newHead;
}

//Transform SL into a Doubly Mirrored List


DNode* toDoublyMirroredList(Node* head) {
	DNode* newHead = NULL;
	Node* current = head;
	while (current != NULL) {
		DNode* newNode = (DNode*)malloc(sizeof(DNode));
		if (newNode == NULL) {
			printf("Memory allocation failed.\n");
			return NULL;
		}
		newNode->data = current->data;
		newNode->next = newHead;
		newNode->prev = NULL;
		if (newHead != NULL) {
			newHead->prev = newNode;
		}
		newHead = newNode;
		current = current->next;
	}
	return newHead;
}

//Transform SL into a Queue
// For a queue, we only need to manage enqueue and dequeue operations using existing Node structure.
void enqueue(Node** head_ref, int new_data) {
	insertionAtEnd(head_ref, new_data); // reuse existing function
}

int dequeue(Node** head_ref) {
	if (*head_ref == NULL) {
		printf("Queue is empty.\n");
		return -1;
	}
	Node* temp = *head_ref;
	int data = temp->data;
	*head_ref = (*head_ref)->next;
	free(temp);
	return data;
}
//Transform SL into a Circular List

void toCircularList(Node** head_ref) {
	if (*head_ref == NULL) return;
	Node* last = *head_ref;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = *head_ref;
}

//Transform SL into a Doubly Circular List

DNode* toDoublyCircularList(Node* head) {
	DNode* newHead = toDoublyLinkedList(head);
	if (newHead == NULL) return NULL;
	DNode* last = newHead;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newHead;
	newHead->prev = last;
	return newHead;
}

//Concatenate Two SL Lists

void concatenateLists(Node** head1, Node* head2) {
	if (*head1 == NULL) {
		*head1 = head2;
		return;
	}
	Node* last = *head1;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = head2;
}

//Display List in Reverse Order

void printListReverse(Node* head) {
	if (head == NULL) return;
	printListReverse(head->next);
	printf("%d ", head->data);
}
//transform my single list into a queue and display the queue 
void displayQueue(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
