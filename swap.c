#include "monty.h"
/**
 * swap - swaps the top_of_stack two elements
 * @top_of_stack: double pointer to the top_of_stack
 * @current_line_number: current line number of the opcode
 * Description: If the stack contains less than two elements, swap
 * Return: void
 */
void swap(stack_t **top_of_stack, unsigned int current_line_number)
{
	stack_t *buff = *top_of_stack;
	int inputs;


	if (*top_of_stack == NULL || (*top_of_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: cannot swap, stack too short\n", current_line_number);
		free(col.line);
		fclose(col.file);
		free_all_stack(top_of_stack);
		exit(EXIT_FAILURE);
	}
	buff = *top_of_stack;
	inputs = buff->n;
	buff->n = buff->next->n;
	buff->next->n = inputs;
}
