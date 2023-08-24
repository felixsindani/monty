#include "monty.h"
/**
* push_in_stack - Pushes a new element onto the stack
* @top_of_stack: A pointer to the top_of_stack
* @element: The element to be pushed into the stack
*/
void push_in_stack(stack_t **top_of_stack, int element)
{
	stack_t *new_node_1;

	new_node_1 = malloc(sizeof(stack_t));
	if (new_node_1 == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node_1->n = element;
	new_node_1->prev = NULL;
	new_node_1->next = NULL; /*added*/
	if (*top_of_stack != NULL)
	{
		new_node_1->next = *top_of_stack;
		(*top_of_stack)->prev = new_node_1;
	}
	*top_of_stack = new_node_1;
}