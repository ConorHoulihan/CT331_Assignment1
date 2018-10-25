#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement* createEl(void* data, size_t size, printDataType printData) {
	genericListElement* e = malloc(sizeof(genericListElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	char* dataPointer = malloc(sizeof(char)*size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}

	memmove(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	e->printData = printData;
	return e;
}

//Prints out each element in the list
void traverse(genericListElement* start) {
	genericListElement* current = start;
	while (current != NULL) {
		current->printData(current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* el, void* data, size_t size, printDataType printData) {
	genericListElement* newEl = createEl(data, size, printData);
	genericListElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(genericListElement* after) {
	genericListElement* delete = after->next;
	genericListElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

int length(genericListElement* list) {
	int count = 0;
	genericListElement* current = list;

	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;

}

void push(genericListElement** list, void* data, size_t size, printDataType printData) {
	genericListElement* newList = createEl(data, size, printData);
	if (newList == NULL) {
		exit(0);
	}
	newList->next = *list;
	*list = newList;
}

genericListElement* pop(genericListElement** list) {
	genericListElement* cur = *list;

	if (list == NULL) {
		printf("List is empty.");
		return NULL;
	}
	*list = cur->next;
	cur->next = NULL;

	return cur;
}

void enqueue(genericListElement** list, void* data, size_t size, printDataType printData) {
	genericListElement* cur = createEl(data, size, printData);
	if (cur == NULL) {
		exit(0);
	}
	cur->next = *list;
	*list = cur;
}

genericListElement* dequeue(genericListElement* list) {
	genericListElement* cur = list;

	while ((cur->next)->next != NULL) {
		cur = cur->next;
	}
	genericListElement* temp = cur->next;
	cur->next = NULL;
	return temp;
}
