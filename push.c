#include "monty.h"
/**
 * push - Adds a new element to the top of the stack.
 * @top_of_stack: A pointer to the top of the stack.
 * @current_line_number: The line number
 */
void push(stack_t **top_of_stack, unsigned int current_line_number)
{
	int value;
	char *ptr;

	if (col.arg == NULL || *col.arg == '\0' || isspace(*col.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", current_line_number);
		free_all_stack(top_of_stack);
		free(col.line);
		fclose(col.file);
		exit(EXIT_FAILURE);
	}
	value = strtol(col.arg, &ptr, 10);

	if (*ptr != '\0' || ptr == col.arg ||
			value > INT_MAX || value < INT_MIN)
	{
		fprintf(stderr, "L%u: usage: push integer\n", current_line_number);
		free_all_stack(top_of_stack);
		free(col.line);
		if (col.file != NULL)
			fclose(col.file);
		exit(EXIT_FAILURE);
	}
	push_in_stack(top_of_stack, value);
}
