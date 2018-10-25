#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef void(*printDataType)(void* data);

typedef struct genericLinkedListElementStruct {
	void* data;
	size_t size;
	struct genericLinkedListElementStruct* next;
	printDataType printData;
} genericListElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement* createEl(void* data, size_t size, printDataType);

//Prints out each element in the list
void traverse(genericListElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* after, void* data, size_t size, printDataType);

//Delete the element after the given el
void deleteAfter(genericListElement* after);

//Counts lenght of list and returns it
int length(genericListElement* length);

//Push a new element onto the head of the list
void push(genericListElement** List, void* data, size_t size, printDataType);

//Pop an element from the head of the list
genericListElement* pop(genericListElement** List);

//Enqueue a new element onto the head of the list
void enqueue(genericListElement** List, void* data, size_t size, printDataType);

//Dequeue an element from the tail of the list
genericListElement* dequeue(genericListElement* List);

#endif
