#include <stdio.h>
#include <malloc.h>

#define STACK_OK 	0
#define STACK_BAD	1
typedef struct _Stack {
	int data;
	Stack *bottom;
} Stack; 

Stack *current;

Stack *stack_new(int data) {
	Stack *new;
	
	new = malloc(sizeof(Stack));
	new.data = data;
	
	return new;
}

int stack_push(int data) {
	Stack *new;

	new = stack_new(data);
	if (new == 0x0) return STACK_BAD;

	new.bottom = current;
	current = new;

	return STACK_OK;
}


int stack_pop(int *pop) {
	Stack *temp;

	temp = current;
	*pop = current.data;
	current = current.bottom;

	free(temp);

	return STACK_OK;
}


