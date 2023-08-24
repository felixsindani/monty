#include "monty.h"
/**
 * free_all_stack - Frees all nodes of stack
 * @stack: Ptr to the top of the stack
 * Description: This function frees all the nodes of a stack from the top
 */
void free_all_stack(stack_t **stack)
{
	stack_t *current_item = *stack;
	stack_t *buffer = NULL;

	while (current_item != NULL)
	{
		buffer = current_item;
		current_item = current_item->next;
		free(buffer);
	}
	*stack = NULL;
}
