#include "monty.h"
/**
* add - Add the top_of_stack two elements
* @top_of_stack: Double pointer at the top of the stack.
* @current_line_number: current Line number of the current op
*/
void add(stack_t **top_of_stack, unsigned int current_line_number)
{
	int abc;
	stack_t *buff;

	if (*top_of_stack == NULL || (*top_of_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", current_line_number);
		free(col.line);
		fclose(col.file);
		free_stack(top_of_stack);
		exit(EXIT_FAILURE);
	}
	abc = (*top_of_stack)->n + (*top_of_stack)->next->n;
	buff = *top_of_stack;
	*top_of_stack = (*top_of_stack)->next;
	(*top_of_stack)->prev = NULL;
	(*top_of_stack)->n = abc;
	free(buff);


}