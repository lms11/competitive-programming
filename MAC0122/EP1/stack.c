#include <stdio.h>
#include <string.h>
#include "stack.h"

struct stack_struct {
	int size;
	StackItem first, last;

	int (*push_callback_func)(Draw);
	Draw push_callback_obj;
};

struct stack_item_struct {
	StackItem next, previous;
	
	union {
		char strValue[STACK_STRING_LENGTH];
		double value;
	}
};

void stack_init(Stack s) {
	// Init
	if (s) {
		s.size = 0;
		s.first = s.last = NULL;
	}
}

void stack_destroy(Stack s) {
	if (!s) return; // Stop if s is already null

	// Release all stack's items
	StackItem cur = s->first, next = cur->next;
	while (next != NULL) {
		free(cur->string);
		free(cur);
		cur = next;
		next = cur.next;
	}
	free(cur->string);
	free(cur);
}

int stack_push_general(Stack s, char string[], double value) {
	if (!s) return 0; // Stop if s is already null

	// Alloc and init StackItem
	StackItem item = malloc(sizeof(StackItem));

	// Check if item was successfully allocated
	if (!item) {
		return 0;
	}

	if (string) {
		// Alloc and init StackItem's string
		item->strValue = malloc(strlen(string) * sizeof(char));

		// Check if item's string was successfully allocated
		if (!item->strValue) {
			free(item);
			return 0;

		} else strcpy(item->strValue, string);

	} else item->value = value;

	// Set item's next as current first in order to put it in stack's top
	s->first->previous = item;
	item->next = s->first;

	// Set stack's first item to be this new item
	s->first = item;

	// If stack is empty, then we should add this item to the last as well
	if (s->size == 0) 
		s->last = item;

	// Update stack's size
	s->size++;

	// Delegate only works for string's push
	if (string && s->push_delegate_func && s->push_delegate_obj)
		return s->push_delegate_func(s->push_delegate_obj);

	return 1;
}

int stack_push(Stack s, char string[]) {
	return stack_push_general(s, string, 0);
}

int stack_push_number(Stack s, double a) {
	return stack_push_general(s, 0, a);
}

StackItem stack_pop(Stack s) {
	StackItem res;
	if (!s) return; // Stop if s is already null

	res = s->first;

	// Set stack's top item to be its next item
	s->first = s->first->next;

	// Release old top item
	s->first->previous = NULL;

	// Update stack's size
	s->size--;

	// Remove res connections
	res->next = res->previous = 0;

	return res;
}

int stack_size(Stack s) {
	if (!s) return -1;
	else return s->size;
}
