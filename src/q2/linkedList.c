#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

int length(listElement* list) {
	listElement* current = list;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

void push(listElement** list, char* data, size_t size) {
	listElement* newList = createEl(data, size);
	if (newList == NULL) {
		exit(0);
	}
	newList->next = *list;
	*list = newList;
}

listElement* pop(listElement** list) {
	listElement* cur = *list;

	if (list == NULL) {
		printf("List is empty.");
		return NULL;
	}
	else {
		*list = cur->next;
		cur->next = NULL;

		return cur;
	}
}

void enqueue(listElement** list, char* data, size_t size) {
	listElement* cur = createEl(data, size);
	if (cur == NULL) {
		exit(0);
	}
	cur->next = *list;
	*list = cur;
}

listElement* dequeue(listElement* list) {
	listElement* cur = list;

	while ((cur->next)->next != NULL) {
		cur = cur->next;
	}
	listElement* temp = cur->next;
	cur->next = NULL;
	return temp;
}
