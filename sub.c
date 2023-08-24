#include "monty.h"
/**
* sub - Subtract the top_of_stack element from the second element
* @top_of_stack: Double pointer to the top_of_stack
* @current_file_line: current Line number of the current op
*/
void sub(stack_t **top_of_stack, unsigned int current_file_line)
{
	stack_t *buff;
	int element;

	if (*top_of_stack == NULL || (*top_of_stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", current_file_line);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
	element = (*top_of_stack)->n - (*top_of_stack)->next->n;
	buff = *top_of_stack;
	*top_of_stack = (*top_of_stack)->next; 
	(*top_of_stack)->prev = NULL;
	(*top_of_stack)->n = -(element);
	free(buff);

}