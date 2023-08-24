#include "monty.h"
/**
* pop - Removes top element of the stack.
* @top_of_stack: A pointer to top of the stack
* @current_line_number: Current line number
*/
void pop(stack_t **top_of_stack, unsigned int current_line_number)
{
	stack_t *buff;

	if (*top_of_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop,stack empty\n", current_line_number);
		free(col.line);
		fclose(col.file);
		free_all_stack(top_of_stack);
		exit(EXIT_FAILURE);
	}
	buff = *top_of_stack;
	*top_of_stack = buff->next;
	if (*top_of_stack != NULL)
	{
		(*top_of_stack)->prev = NULL;
	}
	free(buff);
}